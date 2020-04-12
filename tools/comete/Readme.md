# Comète

Comete is a cli tool for trace search. It can filter basic blocks by using an
execution trace and regex for matching specific instructions. It makes it easy
to find the code you are looking for after a tracing session.

```
Usage of ./comete-display:
  -bin string
        elf program (default "a.out")
  -codeinfo string
        CodeInfo file (default "info.cif")
  -regex_args string
        Regex used to match instruction arguments
  -regex_op string
        Regex used to match specific opcodes
  -show_blocks
        Displays basic block disassembly
  -traceinfo string
        TraceInfo file
```

## Input files

Comete needs a few specific files to run.

### -bin: The elf binary

The elf binary is necessary for disassembly. As of now only 32bit mips binaries
are supported (PSP games).

### -codeinfo: CodeInfo .cif files

CodeInfo files are necessary as they list all functions in the binary as well as
all basic blocks. CodeInfo files have a simple format and can be generated from
a disassembler, an example snippet script for binary ninja is provided.

The format is as follows

| Name | Type | Description |
|:---:|:-----:|:-----------:|
| Magic | u32 | Magic for cif files 0x99464943 ("CIF\x99") |
| Function Count | u32 | Number of function entries |
| Function Info | FunctionInfo[] | Array of function entries |
| Basic Block Count | u32 | Number of basic blocks |
| Basic Block Info | BasicBlockInfo[] | Array of basic block entries |

The FunctionInfo struct is as such:

| Name | Type | Description |
|:----:|:----:|:-----------:|
| Function address | u32 | Address of first basic block of function |
| Function name | char[] | Null terminated string of function name |

The BasicBlockInfo struct is as such:

| Name | Type | Description |
|:----:|:----:|:-----------:|
| Function id | u32 | Index into the FunctionInfo array |
| Start | u32 | Address of first instruction of basic block |
| End | u32 | Address after last instruction of basic block (or close enough) |

### -traceinfo: TraceInfo .tif files

TraceInfo files are optional but very important to leverage the power of the
tool. These files simply contain the address of basic blocks and the number
of times they were executed. The file format is as such:

| Name | Type | Description |
|:----:|:----:|:-----------:|
| Magic | u32 | Magic for tif files 0x99464954 ("TIF\x99") |
| Basic Block Count | u32 | Number of BasicBlockHitInfo entries |
| Basic Block Hits  | BasicBlockHitInfo[] | Array of BasicBlockHitInfo entries |

The BasicBlockHitInfo structure is defined as such:

| Name | Type | Description |
|:----:|:----:|:-----------:|
| Address | u32 | Address of the hit |
| Hitcount | u32 | Number of time the basic block was executed |
