import struct

from binaryninja.plugin import PluginCommand
from binaryninja.enums import SegmentFlag
from binaryninja.interaction import get_open_filename_input

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

def load_ovl(bv):
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

def unload_ovl(bv):
    pass

PluginCommand.register("MHFU\\Load ovl file", "Loads an ovl file", load_ovl)
PluginCommand.register("MHFU\\Unload ovl file", "Unloads an ovl file", load_ovl)
