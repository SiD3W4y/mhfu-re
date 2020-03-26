import asyncio
import struct
import sys

sys.path.append("..")

from ppsspp import PPSSPP

rajang_vtable = [
    0x00000000, 0x00000000, 0x09b44c60, 0x09ac4e30, 0x09ac48c0,
    0x08864634, 0x09b41c50, 0x088646ac, 0x08865254, 0x0886574c,
    0x08865810, 0x09ada5b0, 0x09b320c0, 0x09ac5230, 0x09ac4950,
    0x09ac7620, 0x09b30768, 0x09acf6c0, 0x09b30760, 0x09ad08b8,
    0x09ad0920, 0x09b31db8, 0x09ada298, 0x09ada2a0, 0x09ada2a8,
    0x09ada2b0, 0x09ac4e28, 0x09b439d0, 0x09acc448, 0x09b30a38,
    0x09b30d90, 0x09b400e8, 0x09b41d00, 0x09b449c8, 0x09b30d98,
    0x09b449c0, 0x09accbf8, 0x09ac34f8, 0x09ac3500, 0x09ac3508,
    0x09ac3510, 0x09ac3518, 0x09ac3520, 0x09ad7728, 0x09ad7730,
    0x09ad7738, 0x09ad7740, 0x09ad7748, 0x09ad7750, 0x09ad7758,
    0x09b44a48, 0x09ac3528, 0x09ac3530, 0x09ac3538, 0x09ac3540,
    0x09b44498, 0x09b44938, 0x09b438a0, 0x09b418a8, 0x09b439c8,
    0x09b43840, 0x09ac91c0, 0x09b44be8
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

async def vtableHit(psp, pc):
    if pc not in rajang_vtable:
        return

    regs = await psp.get_cpu_registers()
    a0 = regs["a0"]
    a1 = regs["a1"]
    a2 = regs["a2"]
    ra = regs["ra"]

    index = rajang_vtable.index(pc)
    print(f"rajang_vtable[{index}] -> 0x{pc:08x}: call(0x{a0:08x}, 0x{a1:08x}, 0x{a2:08x}) return: 0x{ra:08x}")

    if index == 58:
        hp = await read_u16(psp, a0 + 0x2e4)
        print(f"Rajang hp remaining: {hp}")


async def main():
    psp = PPSSPP()
    await psp.connect()

    blacklist = [3, 5, 6, 7, 8, 11, 12, 13, 14, 15, 21, 27, 28, 31, 32, 33, 34, 36, 55]

    for i, addr in enumerate(rajang_vtable):
        if i >= 2 and i not in blacklist:
            psp.add_hook(addr, vtableHit)

    await psp.loop()

if __name__ == '__main__':
    asyncio.run(main())
