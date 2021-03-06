package main

import (
	"errors"
	"flag"
	"fmt"
	"github.com/SiD3W4y/comete"
	"github.com/bnagy/gapstone"
	"log"
	"regexp"
	"sort"
)

var codeInfoPath string
var traceInfoPath string
var binPath string
var displayBlocks bool
var regexOp string
var regexArgs string
var hitCount int

func init() {
	flag.StringVar(&codeInfoPath, "codeinfo", "info.cif", "CodeInfo file")
	flag.StringVar(&binPath, "bin", "a.out", "elf program")
	flag.StringVar(&traceInfoPath, "traceinfo", "", "TraceInfo file")
	flag.BoolVar(&displayBlocks, "show_blocks", false, "Displays basic block disassembly")
	flag.StringVar(&regexOp, "regex_op", "", "Regex used to match specific opcodes")
	flag.StringVar(&regexArgs, "regex_args", "", "Regex used to match instruction arguments")
	flag.IntVar(&hitCount, "hitcount", -1, "Only display basic blocks with a specific hitcount")
}

func instructionMatches(instruction gapstone.Instruction) (bool, error) {
	opMatch := false
	argsMatch := false

	if regexOp != "" {
		opRegexMatch, err := regexp.MatchString(regexOp, instruction.Mnemonic)

		if err != nil {
			return false, err
		}

		opMatch = opRegexMatch
	}

	if regexArgs != "" {
		argsRegexMatch, err := regexp.MatchString(regexArgs, instruction.OpStr)

		if err != nil {
			return false, err
		}

		argsMatch = argsRegexMatch
	}

	if (regexOp != "") && (regexArgs != "") {
		return (opMatch && argsMatch), nil
	}

	if (regexOp != "") && (regexArgs == "") {
		return opMatch, nil
	}

	if (regexOp == "") && (regexArgs != "") {
		return argsMatch, nil
	}

	return true, nil
}

func main() {
	flag.Parse()

	codeinfo, err := comete.OpenCodeInfo(codeInfoPath)

	if err != nil {
		log.Fatal(err)
	}

	bininfo, err := comete.OpenBinInfo(binPath)

	if err != nil {
		log.Fatal(err)
	}

	var traceinfo *comete.TraceInfo

	if traceInfoPath != "" {
		traceinfo, err = comete.OpenTraceInfo(traceInfoPath)

		if err != nil {
			log.Fatal(err)
		}
	}

	for i, bb := range codeinfo.BasicBlocks {
		var traceHits uint32

		// If traceinfo exists we only process bbs present in the trace
		if traceinfo != nil {
			idx := sort.Search(len(traceinfo.Hits), func(j int) bool {
				return traceinfo.Hits[j].Address >= bb.Start
			})

			if idx >= len(traceinfo.Hits) {
				continue
			}

			if traceinfo.Hits[idx].Address > bb.End {
				continue
			}

			traceHits = uint32(traceinfo.Hits[idx].Hitcount)

			if (hitCount >= 0) && (traceHits != uint32(hitCount)) {
				continue
			}
		}

		// Now we collect all instructions for matching on string patterns
		insn, err := bininfo.GetInstructionRange(uint64(bb.Start), uint64(bb.End))

		if err != nil && !errors.Is(err, gapstone.ErrOK) {
			fmt.Printf("Error: %v\n", err)
			continue
		}

		regexMatches := false

		for _, ins := range insn {
			match, err := instructionMatches(ins)

			// Regex error should be fatal
			if err != nil {
				log.Fatal(err)
			}

			if match {
				regexMatches = true
				break
			}
		}

		// No instruction matched
		if !regexMatches {
			continue
		}

		if traceinfo != nil {
			fmt.Printf("Block %d (0x%x -> 0x%x) %v hits\n", i, bb.Start, bb.End, traceHits)
		} else {
			fmt.Printf("Block %d (0x%x -> 0x%x)\n", i, bb.Start, bb.End)
		}

		if displayBlocks {
			for _, ins := range insn {
				fmt.Printf("0x%x %s %s\n", ins.Address, ins.Mnemonic, ins.OpStr)
			}
		}
	}
}
