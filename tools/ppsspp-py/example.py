import asyncio
import hexdump
from ppsspp import PPSSPP

async def handle_log(psp, req):
    print(f"[LOG: {req['timestamp']}] {req['header']}: {req['message'].strip()}")

async def sceUtilitySavedataInitStart_hook(psp, pc):
    regs = await psp.get_cpu_registers()
    params = regs["a0"]
    data = await psp.read_memory(params, 256)

    print(f"[HOOK] sceUtilitySavedataInitStart(SceUtilitySavedataParam: 0x{params:08x})")
    hexdump.hexdump(data)

async def sceIoOpen_hook(psp, pc):
    regs = await psp.get_cpu_registers()

    path = regs["a0"]
    flags = regs["a1"]
    mode = regs["a2"]

    # Read path
    path_bytes = await psp.read_memory(path, 256)
    path_str = path_bytes[:path_bytes.find(0)].decode("UTF-8")

    print(f"[HOOK] sceIoOpen(path: '{path_str}', flags: {flags}, mode: {mode}')")

async def sceIoLseek_hook(psp, pc):
    regs = await psp.get_cpu_registers()

    fd = regs["a0"]
    off = regs["a1"]
    whence = regs["a2"]

    print(f"[HOOK] sceIoLseek(fd: {fd}, offset: 0x{off:08x}, whence: 0x{whence:08x})")

decrypt_addr = 0
decrypt_len = 0

async def decrypt_data_hook(psp, pc):
    global decrypt_addr
    global decrypt_len

    regs = await psp.get_cpu_registers()

    game_state = regs["a0"]
    data_ptr = regs["a1"]
    data_len = regs["a2"]

    print(f"[HOOK] decrypt_data(state: 0x{game_state:08x}, data: 0x{data_ptr:08x}, len: 0x{data_len:08x})")

    decrypt_addr = data_ptr
    decrypt_len = data_len

async def decrypt_dump_hook(psp, pc):
    global decrypt_addr
    global decrypt_len

    if decrypt_len > 0x10000:
        print("[HOOK] File too big, skipping dumping...")
        return

    data = await psp.read_memory(decrypt_addr, decrypt_len)
    open(f"dump_0x{decrypt_addr:08x}_0x{decrypt_len:08x}.bin", "wb").write(data)

sceIoOpen_addr = 0x0890dfb0
sceUtilitySavedataInitStart_addr = 0x0890e498
sceIoLseek_addr = 0x0890dfb8

async def main():
    psp = PPSSPP()
    await psp.connect()

    # psp.set_handler("log", handle_log)
    psp.add_hook(sceUtilitySavedataInitStart_addr,
            sceUtilitySavedataInitStart_hook)
    psp.add_hook(sceIoOpen_addr, sceIoOpen_hook)
    # psp.add_hook(sceIoLseek_addr, sceIoLseek_hook)

    psp.add_hook(0x0884ea1c, decrypt_data_hook)
    psp.add_hook(0x0884eaf8, decrypt_dump_hook)

    await psp.loop()

if __name__ == '__main__':
    asyncio.run(main())
