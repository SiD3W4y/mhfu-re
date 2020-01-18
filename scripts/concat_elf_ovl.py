import os
import struct
import argparse

import lief

"""
This scripts reconstructs a binary suitable for analysis by adding a
specified ovl file to the default game elf (loadable code module).
"""

def parse_ovl_file(path):
    data = open(path, "rb").read()

    if len(data) < 0x80:
        print("ovl file too small !!!")
        return

    magic, _, load_addr, _, _, _, _, _ = struct.unpack("<IIIIIIII", data[:0x20])

    if magic != 0x336f574d:
        print("Invalid magic: 0x{:08x}".format(magic))
        return

    if load_addr < 0x09000000 or load_addr > 0x0a000000:
        print("Invalid load address: 0x{:08x}".format(load_addr))
        return

    return (data, load_addr)

def main():
    parser = argparse.ArgumentParser(description="Append ovl file as a new elf segment")
    parser.add_argument("-e", "--elf", help="Input elf file")
    parser.add_argument("-i", "--ovl", help="Input ovl file")
    parser.add_argument("-o", "--output", help="ELF+OVL output file (default out.elf)")
    args = parser.parse_args()

    if not args.elf:
        print("Please specify an elf file")
        return

    if not args.ovl:
        print("Please specify an ovl file")
        return

    args.output = args.output or "out.elf"

    # Sanity checking
    if not os.path.exists(args.elf):
        print(f"Elf file '{args.elf} does not exist")
        return

    if not os.path.exists(args.ovl):
        print(f"Ovl file {args.ovl} does not exist")
        return

    # Load files
    res = parse_ovl_file(args.ovl)

    if not res:
        return

    elf = lief.parse(args.elf)

    if not elf:
        print("Not an elf file")
        return

    # Add segment to elf
    segment = lief.ELF.Segment()
    segment.type = lief.ELF.SEGMENT_TYPES.LOAD
    segment.content = [int(c) for c in res[0]]
    segment.flags = lief.ELF.SEGMENT_FLAGS(lief.ELF.SEGMENT_FLAGS.X | lief.ELF.SEGMENT_FLAGS.R)
    segment.virtual_address = res[1]

    elf.add(segment)

    # Save
    elf.write(args.output)

if __name__ == '__main__':
    main()
