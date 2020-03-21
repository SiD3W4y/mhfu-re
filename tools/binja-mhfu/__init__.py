import struct

from binaryninja.plugin import PluginCommand
from binaryninja.enums import SegmentFlag
from binaryninja.interaction import get_open_filename_input

from .nid import nid_resolve

def _parse_ovl_file(path):
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

def map_ovl(bv):
    path = get_open_filename_input("Select an ovl file", ext="*.ovl")

    if not path:
        return

    ovl = _parse_ovl_file(path)

    if not ovl:
        return

    data, load_addr = ovl
    print("Loading ovl at address: 0x{:08x}".format(load_addr))

    bv.add_user_segment(load_addr, len(data), 0, len(data),
            SegmentFlag.SegmentReadable | SegmentFlag.SegmentExecutable)
    bv.write(load_addr, data)

def unmap_ovl(bv):
    pass

def trace_detect_function(bv):
    path = get_open_filename_input("Select a ppsspp trace file", ext="*.txt")

    if not path:
        return

    functions = 0
    duplicates = 0

    fp = open(path, "r")

    for line in fp.readlines():
        line = line.strip()

        chks = line.split(" ")

        if len(chks) != 3:
            print("Invalid file format")
            return

        if chks[0] != "CALL":
            continue

        addr = int(chks[1], 16)
        fns = bv.get_functions_containing(addr)

        if not fns:
            bv.create_user_function(addr, plat=bv.platform)
            functions += 1
        else:
            duplicates += 1

    print(f"Loading {functions} functions. Found {duplicates} duplicates")

PluginCommand.register("MHFU\\Map ovl file", "Map ovl file", map_ovl)
PluginCommand.register("MHFU\\Unmap ovl file", "Unmap an ovl file", unmap_ovl)
PluginCommand.register("MHFU\\Trace based function detection",
        "Detect functions based on ppsspp trace", trace_detect_function)
PluginCommand.register("MHFU\\Resolve nid calls", "Resolve PSP api calls" , nid_resolve)
