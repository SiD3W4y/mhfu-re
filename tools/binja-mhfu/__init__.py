import struct
import os

from binaryninja.plugin import PluginCommand
from binaryninja.enums import SegmentFlag, SymbolType
from binaryninja.interaction import get_open_filename_input
from binaryninja.typelibrary import TypeLibrary

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


def load_type_library(bv):
    plugin_path = os.path.dirname(os.path.realpath(__file__)) + "/data/"
    bntl_path = plugin_path + "psp.bntl"
    header_path = plugin_path + "pspsdk.h"
    psp_typelib = None

    if not os.path.exists(bntl_path):
        print("[PSP] Type library does not exist. Generating ...")

        if not os.path.exists(header_path):
            print("[PSP] Could not find '{}'".format(header_path))
            return

        types = bv.platform.parse_types_from_source_file(header_path)
        tlib = TypeLibrary.new(bv.arch, "psp")

        for name, t in types.functions.items():
            tlib.add_named_object(name, t)

        for name, t in types.types.items():
            tlib.add_named_type(name, t)

        tlib.finalize()
        tlib.write_to_file(bntl_path)
        psp_typelib = tlib
    else:
        print("[PSP] Found cached type library: {}".format(bntl_path))
        psp_typelib = TypeLibrary.load_from_file(bntl_path)

    if not psp_typelib:
        print("[PSP] Could not load type library")
        return

    if psp_typelib not in bv.type_libraries:
        bv.add_type_library(psp_typelib)

    # Now resolve symbols
    for sym in bv.get_symbols_of_type(SymbolType.ImportedFunctionSymbol):
        func = bv.get_function_at(sym.address)

        if not func:
            continue

        func_type = psp_typelib.get_named_object(func.name)

        if func_type is None:
            continue

        func.set_user_type(func_type)
        print("[PSP] Resolved type for {}".format(func.name))


PluginCommand.register("MHFU\\Map ovl file", "Map ovl file", map_ovl)
PluginCommand.register("MHFU\\Unmap ovl file", "Unmap an ovl file", unmap_ovl)
PluginCommand.register("MHFU\\Trace based function detection",
        "Detect functions based on ppsspp trace", trace_detect_function)
PluginCommand.register("MHFU\\Resolve nid calls", "Resolve PSP api calls" , nid_resolve)
PluginCommand.register("MHFU\\Apply pspsdk types", "Apply pspsdk type library", load_type_library)
