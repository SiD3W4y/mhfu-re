import asyncio
import sys

sys.path.append("..")

from ppsspp import PPSSPP

task_addr  = 0x09a5f300
sub_addr   = 0x09c19100
em_addr    = 0x09d1a280
stage_addr = 0x09d63100

async def get_ovl_name(psp, ovl_addr):
    name_bytes = await psp.read_memory(ovl_addr + 0x20, 0x60)

    return name_bytes[:name_bytes.find(b"\x00")].decode("UTF-8")

async def main():
    psp = PPSSPP()
    await psp.connect()

    task_name  = await get_ovl_name(psp, task_addr)
    sub_name   = await get_ovl_name(psp, sub_addr)
    em_name    = await get_ovl_name(psp, em_addr)
    stage_name = await get_ovl_name(psp, stage_addr)

    print(f"[+] Current task  : {task_name}")
    print(f"[+] Current sub   : {sub_name}")
    print(f"[+] Current em    : {em_name}")
    print(f"[+] Current stage : {stage_name}")

if __name__ == '__main__':
    asyncio.run(main())
