package comete

import (
	"bufio"
	"bytes"
	"encoding/binary"
	"errors"
	"os"
	"sort"
)

const (
	CodeInfoMagic = 0x99464943
)

type BasicBlockInfo struct {
	FunctionID uint32
	Start      uint32
	End        uint32
}

type FunctionInfo struct {
	Name  string
	Start uint32
}

type CodeInfo struct {
	Functions   []FunctionInfo
	BasicBlocks []BasicBlockInfo
}

func parseFunctionInfo(reader *bufio.Reader) (*FunctionInfo, error) {
	var address uint32
	err := binary.Read(reader, binary.LittleEndian, &address)

	if err != nil {
		return nil, err
	}

	buffer := bytes.NewBuffer([]byte{})

	// Read until null byte
	for {
		c, err := reader.ReadByte()

		if err != nil {
			return nil, err
		}

		if c == 0 {
			break
		}

		buffer.WriteByte(c)
	}

	result := &FunctionInfo{
		Name:  string(buffer.Bytes()),
		Start: address,
	}

	return result, nil
}

func parseBasicBlockInfo(reader *bufio.Reader) (*BasicBlockInfo, error) {
	var functionID uint32
	var start uint32
	var end uint32

	err := binary.Read(reader, binary.LittleEndian, &functionID)

	if err != nil {
		return nil, err
	}

	err = binary.Read(reader, binary.LittleEndian, &start)

	if err != nil {
		return nil, err
	}

	err = binary.Read(reader, binary.LittleEndian, &end)

	if err != nil {
		return nil, err
	}

	result := &BasicBlockInfo{
		FunctionID: functionID,
		Start:      start,
		End:        end,
	}

	return result, nil
}

func OpenCodeInfo(path string) (*CodeInfo, error) {
	file, err := os.Open(path)

	if err != nil {
		return nil, err
	}

	defer file.Close()

	reader := bufio.NewReader(file)

	// Now onto the parsing
	var magic uint32
	var functionCount uint32

	// Checking the magic
	err = binary.Read(reader, binary.LittleEndian, &magic)

	if err != nil {
		return nil, err
	}

	if magic != CodeInfoMagic {
		return nil, errors.New("Invalid CodeInfo magic")
	}

	// Getting function count
	err = binary.Read(reader, binary.LittleEndian, &functionCount)

	if err != nil {
		return nil, err
	}

	// Now reading the Function info
	var functionInfo []FunctionInfo
	var i uint32

	for i = 0; i < functionCount; i++ {
		function, err := parseFunctionInfo(reader)

		if err != nil {
			return nil, err
		}

		functionInfo = append(functionInfo, *function)
	}

	// Now reading the basic blocks
	var basicBlockCount uint32
	var basicBlockInfo []BasicBlockInfo

	err = binary.Read(reader, binary.LittleEndian, &basicBlockCount)

	if err != nil {
		return nil, err
	}

	for i = 0; i < basicBlockCount; i++ {
		bb, err := parseBasicBlockInfo(reader)

		if err != nil {
			return nil, err
		}

		basicBlockInfo = append(basicBlockInfo, *bb)
	}

	// Now we sort basic block by address for faster search afterwards
	sort.Slice(basicBlockInfo, func(i, j int) bool {
		return basicBlockInfo[i].Start < basicBlockInfo[j].Start
	})

	result := &CodeInfo{
		Functions:   functionInfo,
		BasicBlocks: basicBlockInfo,
	}

	return result, nil
}
