# CodeInfo Dumping
#
# Dumps basic block information as well as function information
# Created for use with comete put can be used by anything really
import struct

"""
CodeInfo fileformat:

'CIF\x99': Magic

u32: Function count
[addr: u32, name: str]: Function names (null delimited)

u32: bb_count
[function_id: u32, bb_start: u32, bb_end: u32]
"""

def p32(x):
    return struct.pack("<I", x)

def main():
    path = get_save_filename_input("Output codeinfo")

    if not path:
        return

    fd = open(path, "wb")
    bb_count = 0

    fd.write(b"CIF\x99")
    fd.write(p32(len(bv.functions)))

    for e in bv.functions:
        fd.write(p32(e.start))
        fd.write(bytes(e.name, "UTF-8") + b"\x00")

    # Now writing basic blocks
    bb_count_addr = fd.tell()
    fd.write(p32(0)) # Basic block count

    for i, e in enumerate(bv.functions):
        for block in e.basic_blocks:
            fd.write(p32(i)) # Function id
            fd.write(p32(block.start))
            fd.write(p32(block.end))

            bb_count += 1

    fd.seek(bb_count_addr)
    fd.write(p32(bb_count))

    print(f"[+] Processed {len(bv.functions)} functions")
    print(f"[+] Processed {bb_count} basic blocks")

main()
