import asyncio
import struct
import sys

sys.path.append("..")

from ppsspp import PPSSPP

ENTITY_ARRAY_PTR = 0x9c122b0

def parse_num(num):
    try:
        if num.startswith("0x"):
            return int(num, 16)

        return int(num)
    except Exception:
        return None

async def read_u32(psp, addr):
    data = await psp.read_memory(addr, 4)

    return struct.unpack("<I", data)[0]

async def read_u16(psp, addr):
    data = await psp.read_memory(addr, 2)

    return struct.unpack("<H", data)[0]

async def read_u8(psp, addr):
    data = await psp.read_memory(addr, 1)

    return struct.unpack("B", data)[0]

async def write_u8(psp, addr, value):
    await psp.write_memory(addr, struct.pack("B", value))

async def write_u16(psp, addr, value):
    await psp.write_memory(addr, struct.pack("<H", value))

async def write_u32(psp, addr, value):
    await psp.write_memory(addr, struct.pack("<I", value))

async def get_entities(psp):
    objects = []
    array_ptr = await read_u32(psp, ENTITY_ARRAY_PTR)

    for i in range(0x14):
        addr = await read_u32(psp, array_ptr + (i * 4) + 0x1220)
        objects.append(addr)

    return objects

""" Reading commands """

async def cmd_read_32(psp, entities, cmd):
    # r32 <entity idx> <offset>
    if len(cmd) != 3:
        print("Wrong command arguments")
        return

    idx = parse_num(cmd[1])
    offset = parse_num(cmd[2])

    if idx is None or idx < 0 or idx >= len(entities):
        print(f"Invalid index: {cmd[1]}")
        return

    if offset is None:
        print(f"Invalid offset: {cmd[2]}")
        return

    if not entities[idx]:
        print(f"No entity at index {idx}")
        return

    value = await read_u32(psp, entities[idx] + offset)

    print(f"hex: 0x{value:08x} dec: {value}")

async def cmd_read_16(psp, entities, cmd):
    # r16 <entity idx> <offset>
    if len(cmd) != 3:
        print("Wrong command arguments")
        return

    idx = parse_num(cmd[1])
    offset = parse_num(cmd[2])

    if idx is None or idx < 0 or idx >= len(entities):
        print(f"Invalid index: {cmd[1]}")
        return

    if offset is None:
        print(f"Invalid offset: {cmd[2]}")
        return

    if not entities[idx]:
        print(f"No entity at index {idx}")
        return

    value = await read_u16(psp, entities[idx] + offset)

    print(f"hex: 0x{value:04x} dec: {value}")

async def cmd_read_8(psp, entities, cmd):
    # r8 <entity idx> <offset>
    if len(cmd) != 3:
        print("Wrong command arguments")
        return

    idx = parse_num(cmd[1])
    offset = parse_num(cmd[2])

    if idx is None or idx < 0 or idx >= len(entities):
        print(f"Invalid index: {cmd[1]}")
        return

    if offset is None:
        print(f"Invalid offset: {cmd[2]}")
        return

    if not entities[idx]:
        print(f"No entity at index {idx}")
        return

    value = await read_u8(psp, entities[idx] + offset)

    print(f"hex: 0x{value:02x} dec: {value}")

""" Writing commands """
async def cmd_write_32(psp, entities, cmd):
    # w32 <entity idx> <offset> <value>
    if len(cmd) != 4:
        print("Wrong command arguments")
        return

    idx = parse_num(cmd[1])
    offset = parse_num(cmd[2])
    value = parse_num(cmd[3])

    if idx is None or idx < 0 or idx >= len(entities):
        print(f"Invalid index: {cmd[1]}")
        return

    if offset is None:
        print(f"Invalid offset: {cmd[2]}")
        return

    if value is None or value < 0 or value > (1 << 32) - 1:
        print(f"Invalid value: {cmd[2]}")

    if not entities[idx]:
        print(f"No entity at index {idx}")
        return

    await write_u32(psp, entities[idx] + offset, value)

async def cmd_write_16(psp, entities, cmd):
    # w8 <entity idx> <offset> <value>
    if len(cmd) != 4:
        print("Wrong command arguments")
        return

    idx = parse_num(cmd[1])
    offset = parse_num(cmd[2])
    value = parse_num(cmd[3])

    if idx is None or idx < 0 or idx >= len(entities):
        print(f"Invalid index: {cmd[1]}")
        return

    if offset is None:
        print(f"Invalid offset: {cmd[2]}")
        return

    if value is None or value < 0 or value > (1 << 16) - 1:
        print(f"Invalid value: {cmd[2]}")

    if not entities[idx]:
        print(f"No entity at index {idx}")
        return

    await write_u16(psp, entities[idx] + offset, value)

async def cmd_write_8(psp, entities, cmd):
    # w8 <entity idx> <offset> <value>
    if len(cmd) != 4:
        print("Wrong command arguments")
        return

    idx = parse_num(cmd[1])
    offset = parse_num(cmd[2])
    value = parse_num(cmd[3])

    if idx is None or idx < 0 or idx >= len(entities):
        print(f"Invalid index: {cmd[1]}")
        return

    if offset is None:
        print(f"Invalid offset: {cmd[2]}")
        return

    if value is None or value < 0 or value > (1 << 8) - 1:
        print(f"Invalid value: {cmd[2]}")

    if not entities[idx]:
        print(f"No entity at index {idx}")
        return

    await write_u8(psp, entities[idx] + offset, value)

async def cmd_list(psp, entities):
    for i, entity in enumerate(entities):
        if entity == 0:
            continue

        vtable = await read_u32(psp, entity)
        hp = await read_u16(psp, entity + 0x2e4)

        print(f"[{i}] vtable: 0x{vtable:08x} hp: {hp}")

def cmd_help():
    print("list                                     : lists the currently active entities")
    print("r<8/16/32> <entity idx> <offset>         : Reads value from entity object")
    print("w<8/16/32> <entity idx> <offset> <value> : Writes value to entity object")

async def main():
    psp = PPSSPP()
    await psp.connect()

    while True:
        command = str(input("mhdbg > "))
        command = command.strip()
        entities = await get_entities(psp)

        if command == "list":
            await cmd_list(psp, entities)
        elif command == "help":
            cmd_help()
        elif command.startswith("r32"):
            await cmd_read_32(psp, entities, command.split(" "))
        elif command.startswith("r16"):
            await cmd_read_16(psp, entities, command.split(" "))
        elif command.startswith("r8"):
            await cmd_read_8(psp, entities, command.split(" "))
        elif command.startswith("w32"):
            await cmd_write_32(psp, entities, command.split(" "))
        elif command.startswith("w16"):
            await cmd_write_16(psp, entities, command.split(" "))
        elif command.startswith("w8"):
            await cmd_write_8(psp, entities, command.split(" "))
        else:
            print(f"Unkown command: '{command}'")

if __name__ == '__main__':
    asyncio.run(main())
