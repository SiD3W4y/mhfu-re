package comete

import (
	"debug/elf"
	"fmt"
	"github.com/bnagy/gapstone"
	"io"
	"strings"
)

// BinInfo represents information about an ELF file
type BinInfo struct {
	binary elf.File
	engine gapstone.Engine
}

// OpenBinInfo opens an elf file for introspection
func OpenBinInfo(path string) (*BinInfo, error) {
	// Reading binary info
	binary, err := elf.Open(path)

	if err != nil {
		return nil, err
	}

	// Setting up capstone, only MIPS supported for now
	if binary.Machine != elf.EM_MIPS {
		return nil, fmt.Errorf("Only MIPS R3000 supported (got %d)", binary.Machine)
	}

	engine, err := gapstone.New(
		gapstone.CS_ARCH_MIPS,
		gapstone.CS_MODE_MIPS32)

	if err != nil {
		return nil, err
	}

	result := &BinInfo{
		binary: *binary,
		engine: engine,
	}

	return result, nil
}

func (info *BinInfo) Read(addr uint64, size uint64) ([]byte, error) {
	var target *elf.Prog

	for _, prog := range info.binary.Progs {
		if prog.Type != elf.PT_LOAD {
			continue
		}

		if (prog.Flags & elf.PF_X) == 0 {
			continue
		}

		if (addr >= prog.Vaddr) && (addr < prog.Vaddr+prog.Filesz) {
			target = prog
			break
		}
	}

	if target == nil {
		return nil, fmt.Errorf("Unmapped address 0x%x", addr)
	}

	// Now clamping the size to be read to prevent oob
	offset := addr - target.Vaddr
	readSize := (target.Vaddr + target.Filesz) - addr

	if size >= readSize {
		size = readSize
	}

	progReader := target.Open()

	_, err := progReader.Seek(int64(offset), io.SeekStart)

	if err != nil {
		return nil, err
	}

	buff := make([]byte, size)
	_, err = progReader.Read(buff)

	if err != nil {
		return nil, err
	}

	return buff, nil
}

func (info *BinInfo) GetInstructionAt(addr uint64) (gapstone.Instruction, error) {
	data, err := info.Read(addr, 16)

	if err != nil {
		return gapstone.Instruction{}, err
	}

	insns, err := info.engine.Disasm(data, addr, 1)

	if err != nil {
		return gapstone.Instruction{}, err
	}

	return insns[0], nil
}

func (info *BinInfo) GetInstructionRange(start uint64, end uint64) ([]gapstone.Instruction, error) {
	if start > end {
		return nil, fmt.Errorf("start > end")
	}

	result := []gapstone.Instruction{}

	for start < end {
		ins, err := info.GetInstructionAt(start)

		if err != nil {
			return nil, err
		}

		result = append(result, ins)
		start += uint64(ins.Size)
	}

	return result, nil
}

func (info *BinInfo) String() string {
	var progInfo []string

	for _, prog := range info.binary.Progs {
		if prog.Type != elf.PT_LOAD {
			continue
		}

		if (prog.Flags & elf.PF_X) == 0 {
			continue
		}

		line := fmt.Sprintf("Start: 0x%x End: 0x%x", prog.Vaddr, prog.Vaddr+prog.Filesz)
		progInfo = append(progInfo, line)
	}

	return strings.Join(progInfo, "\n")
}
