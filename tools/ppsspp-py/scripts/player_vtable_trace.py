import asyncio
import struct
import sys

sys.path.append("..")

from ppsspp import PPSSPP

player_vtable = [
    0x00000000, 0x00000000, 0x09a653d8, 0x09a92028, 0x09a65498,
    0x08864634, 0x09c48c78, 0x088d1dd0, 0x088d6108, 0x088d5f30,
    0x088d5fe4, 0x09a6fb30, 0x08865dbc, 0x088d27bc, 0x09a66198,
    0x09a68fc8, 0x09a655f0, 0x088ce6dc, 0x088ce75c, 0x088cee68,
    0x09a97238, 0x09a70a30, 0x09a71ab0, 0x088d8ed4, 0x088d92f8,
    0x088d96bc, 0x088d6594, 0x09a67630, 0x09ba6988, 0x09c45200,
    0x09a933c0, 0x09a6c968, 0x09aacea0
]

async def read_u8(psp, addr):
    data = await psp.read_memory(addr, 1)

    return struct.unpack("B", data)[0]

async def read_u16(psp, addr):
    data = await psp.read_memory(addr, 2)

    return struct.unpack("<H", data)[0]

async def read_u32(psp, addr):
    data = await psp.read_memory(addr, 4)

    return struct.unpack("<I", data)[0]

async def read_f32(psp, addr):
    data = await psp.read_memory(addr, 4)

    return struct.unpack("<f", data)[0]

async def write_u8(psp, addr, value):
    await psp.write_memory(addr, struct.pack("B", value))

async def write_u16(psp, addr, value):
    await psp.write_memory(addr, struct.pack("<H", value))

async def write_f32(psp, addr, value):
    await psp.write_memory(addr, struct.pack("<f", value))

async def hitFn(psp, pc):
    # Addr: 0x88d6594
    regs = await psp.get_cpu_registers()

    s1 = regs["s1"]
    vtable = await read_u32(psp, s1)

    if s1 > 0x09000000:
        print(f"Player address: 0x{s1:08x} (vtable: 0x{vtable:08x})")

async def vtableHit(psp, pc):
    if pc not in player_vtable:
        return

    index = player_vtable.index(pc)
    print(f"player_vtable[{index}] -> 0x{pc:08x}")

async def mapChange(psp, pc):
    # Addr: 0x9a655f0
    regs = await psp.get_cpu_registers()

    a0 = regs["a0"]

    print("------------------")
    print(f"State: 0x{a0:08x}")

async def damageTaken(psp, pc):
    # Addr: 0x88d6594
    regs = await psp.get_cpu_registers()

    state = regs["a0"]
    damage = regs["a1"]
    ret = regs["ra"]

    dmg = await read_u16(psp, state + 0x3b8)

    print(f"0x{dmg:08x} inflicted to object 0x{state:08x} [return addr: 0x{ret:08x}]")

async def damageCall(psp, pc):
    # Addr: 0x9a6b77c (indirect call to vtable[26])
    regs = await psp.get_cpu_registers()

    state = regs["a0"]
    damage = await read_u16(psp, state + 0x3b8)

    if damage == 0:
        return

    print(f"{damage} damage to entity 0x{state:08x}")

async def monsterState(psp, pc):
    # Addr: 0x9adab30
    regs = await psp.get_cpu_registers()

    state = regs["s3"]
    vtable = await read_u32(psp, state)
    arg1 = regs["a1"]
    arg2 = regs["a2"]
    arg3 = regs["a3"]
    t9 = regs["t9"]

    print(f"Entity 0x{state:08x} (vtable: 0x{vtable:08x}) arg1: {arg1} arg2: {arg2} arg3: {arg3}")
    #print(f"State function: 0x{t9:08x}")

    await psp.set_register("a1", 0)
    await psp.set_register("a2", 0x26)
    await psp.set_register("a3", 4)

async def monsterKill(psp, pc):
    # Addr: 0x9b319e4
    regs = await psp.get_cpu_registers()

    print(f"KILL called 0x{regs['t9']:08x}")


async def main():
    psp = PPSSPP()
    await psp.connect()

    blacklist = [3, 5, 6, 7, 8, 11, 12, 13, 14, 15, 19, 20, 21, 23, 24, 25, 26, 29, 27, 30, 31]

    for i, addr in enumerate(player_vtable):
        if i >= 2 and i not in blacklist:
            psp.add_hook(addr, vtableHit)

    #psp.add_hook(0x09a655f0, mapChange)
    #psp.add_hook(0x88d6594, damageTaken)
    psp.add_hook(0x9a6b77c, damageCall)
    psp.add_hook(0x9ac8b4c, monsterState)
    psp.add_hook(0x9b319e4, monsterKill)

    await psp.loop()

if __name__ == '__main__':
    asyncio.run(main())
