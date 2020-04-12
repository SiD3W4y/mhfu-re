package comete

import (
	"bufio"
	"encoding/binary"
	"errors"
	"os"
	"sort"
)

const (
	TraceInfoMagic = 0x99464954
)

type TraceHitInfo struct {
	Address  uint32
	Hitcount uint32
}

type TraceInfo struct {
	Hits []TraceHitInfo
}

func parseTraceHitInfo(reader *bufio.Reader) (*TraceHitInfo, error) {
	var address uint32
	var hitcount uint32

	err := binary.Read(reader, binary.LittleEndian, &address)

	if err != nil {
		return nil, err
	}

	err = binary.Read(reader, binary.LittleEndian, &hitcount)

	if err != nil {
		return nil, err
	}

	result := &TraceHitInfo{
		Address:  address,
		Hitcount: hitcount,
	}

	return result, nil
}

func OpenTraceInfo(path string) (*TraceInfo, error) {
	file, err := os.Open(path)

	if err != nil {
		return nil, err
	}

	defer file.Close()

	reader := bufio.NewReader(file)

	// Now onto the parsing
	var magic uint32
	var hits uint32

	// Checking the magic
	err = binary.Read(reader, binary.LittleEndian, &magic)

	if err != nil {
		return nil, err
	}

	if magic != TraceInfoMagic {
		return nil, errors.New("Invalid TraceInfo magic")
	}

	// Getting total number of traced bbs
	err = binary.Read(reader, binary.LittleEndian, &hits)

	if err != nil {
		return nil, err
	}

	// Now reading all of the hits
	var traceHits []TraceHitInfo
	var i uint32

	for i = 0; i < hits; i++ {
		hitInfo, err := parseTraceHitInfo(reader)

		if err != nil {
			return nil, err
		}

		traceHits = append(traceHits, *hitInfo)
	}

	// Now we sort basic blocks by address for faster search afterwards
	sort.Slice(traceHits, func(i, j int) bool {
		return traceHits[i].Address < traceHits[j].Address
	})

	result := &TraceInfo{
		Hits: traceHits,
	}

	return result, nil
}
