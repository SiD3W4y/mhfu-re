import json
import struct
import binascii
import logging
import websockets

DEBUG_PORT = 40373

class PPSSPP:
    def __init__(self, port=DEBUG_PORT):
        self.port = port
        self.breakpoints = None
        self.handlers = {}
        self.hooks = {}
        self.socket = None

    async def connect(self):
        # TODO: Error handling
        self.socket = await websockets.connect(f"ws://localhost:{DEBUG_PORT}/debugger")

    async def loop(self):
        """ Handles the event loop and calls related event handlers """
        # First we delete all breakpoints currently active
        bkpts = await self.get_breakpoint_list()

        for b in bkpts:
            address = b["address"]
            logging.debug(f"[PSP] Removing breakpoint at address 0x{address:08x}")
            await self._ws_call("cpu.breakpoint.remove", {"address": address})

        # Install user given breakpoints
        for address, hook in self.hooks.items():
            logging.debug(f"[PSP] Adding breakpoint at address: 0x{address:08x}")
            await self._ws_call("cpu.breakpoint.add",
                    {"address": address, "enabled": True})

        # Handle events
        while True:
            req = await self._next_request()
            await self._handle_request(req)

    def set_handler(self, name, function):
        """ Set/Replace the function handling the event specified by name """
        self.handlers[name] = function

    def add_hook(self, address, function):
        self.hooks[address] = function

    async def set_register(self, name, value):
        await self._ws_call("cpu.setReg", {"name": name, "value": value})

    async def get_raw_registers(self):
        await self._ws_call("cpu.getAllRegs", {})
        regs = await self._wait_event_sync("cpu.getAllRegs")

        return regs

    async def get_cpu_registers(self):
        rawRegs = await self.get_raw_registers()

        for category in rawRegs["categories"]:
            if category["name"] == "GPR":
                rawRegs = category
                break

        return dict(zip(rawRegs["registerNames"], rawRegs["uintValues"]))

    async def get_fpu_registers(self):
        rawRegs = await self.get_raw_registers()

        for category in rawRegs["categories"]:
            if category["name"] == "FPU":
                rawRegs = category
                break

        return dict(zip(rawRegs["registerNames"], rawRegs["floatValues"]))

    async def get_vfpu_registers(self):
        rawRegs = await self.get_raw_registers()

        for category in rawRegs["categories"]:
            if category["name"] == "VFPU":
                rawRegs = category
                break

        return dict(zip(rawRegs["registerNames"], rawRegs["floatValues"]))

    async def get_breakpoint_list(self):
        await self._ws_call("cpu.breakpoint.list", {})
        bkpts = await self._wait_event_sync("cpu.breakpoint.list")

        return bkpts["breakpoints"]

    async def get_module_list(self):
        await self._ws_call("hle.module.list", {})
        res = await self._wait_event_sync("hle.module.list")

        return res["modules"]

    async def evaluate(self, expr):
        await self._ws_call("cpu.evaluate", {"expression": expr})
        ret = await self._wait_event_sync("cpu.evaluate")

        return ret["uintValue"]

    async def read_memory(self, address, size):
        """
        This api call requires a ppsspp fork: https://github.com/SiD3W4y/ppsspp
        """
        await self._ws_call("cpu.memory.read", {"address": address, "size": size})
        ret = await self._wait_event_sync("cpu.memory.read")

        return binascii.unhexlify(ret["payload"])

    async def _wait_event_sync(self, eventName):
        """
        Waits for an event of a specific type, bypassing the event loop.

        This hack is necessary to get pseudo synchronous register/memory access
        from within callbacks.
        """

        while True:
            req = await self._next_request()

            if req["event"] == "error":
                return None

            if req["event"] != eventName:
                await self._handle_request(req)
                continue

            return req

    async def _handle_request(self, req):
        """ Handles an individual request """
        if req["event"] in self.handlers:
            await self.handlers[req["event"]](self, req)
        elif req["event"] == "cpu.stepping":
            await self._handle_breakpoint(req)
        else:
            logging.debug(f"[PSP] Unhandled event: {req['event']}")

    async def _handle_breakpoint(self, req):
        pc = req["pc"]

        if pc in self.hooks:
            await self.hooks[pc](self, pc)

        await self._ws_call("cpu.resume", {})

    async def _next_request(self):
        req = await self.socket.recv()
        reqObj = json.loads(req)

        return reqObj

    async def _ws_call(self, name, args):
        req = {"event": name}

        if args:
            for k, v in args.items():
                req[k] = v

        reqData = json.dumps(req)
        await self.socket.send(reqData)
