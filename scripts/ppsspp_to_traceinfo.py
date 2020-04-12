import struct
import argparse

"""
TraceInfo fileformat:

'TIF\x99': Magic
u32: BasicBlockInfo count
[address: u32, hitcount: u32]
"""

def p32(x):
    return struct.pack("<I", x)


def write_tif(infile, outfile):
    lines = open(infile, "r").readlines()
    outfd = open(outfile, "wb")

    outfd.write(b"TIF\x99")
    pos = outfd.tell()
    outfd.write(p32(0))

    entry_count = 0

    for line in lines:
        line = line.strip()

        if len(line) == 0:
            continue

        chunks = line.split(" ")

        if len(chunks) != 3:
            print(f"Invalid format: '{line}'")
            break

        if chunks[0] != "BRANCH" and chunks[0] != "CALL":
            continue

        address = int(chunks[1], 16)
        count = int(chunks[2])

        outfd.write(p32(address))
        outfd.write(p32(count))
        entry_count += 1

    outfd.seek(pos)
    outfd.write(p32(entry_count))
    outfd.close()


def main():
    parser = argparse.ArgumentParser(description="Converts ppsspp traces to Comete's TraceInfo format")
    parser.add_argument("-i", "--input", help="Input trace from ppsspp")
    parser.add_argument("-o", "--output", help="Output CodeInfo file")
    args = parser.parse_args()

    if not args.input:
        print("Please specify an input file")
        return

    if not args.output:
        args.output = "trace.tif"

    write_tif(args.input, args.output)


if __name__ == '__main__':
    main()
