package algorithm

import "fmt"

type Padovan struct {
	buffer map[string]map[uint64]uint64
}

type PadovanFactory interface {
	CreateMemoryBufferVersion(map[string]map[uint64]uint64) IAlgorithm
	CreateNonMemoryBufferVersion() IAlgorithm
}

func (f *Padovan) CreateMemoryBufferVersion(buffer map[string]map[uint64]uint64) IAlgorithm {
	return &Padovan{buffer: buffer}
}

func (f *Padovan) CreateNonMemoryBufferVersion() IAlgorithm {
	return &Padovan{}
}

func (p *Padovan) GetName() string {
	return "Padovan"
}

func (p *Padovan) GetVal(input uint64) (uint64, error) {
	if input <= 0 {
		return 0, fmt.Errorf("input must be greater than 0")
	}

	var returnVal uint64

	if p.buffer[string(AlgType("Padovan"))] == nil { // NonBuffer
		if input == 1 || input == 2 || input == 3 {
			return 1, nil
		}

		a, _ := p.GetVal(input - 2)
		b, _ := p.GetVal(input - 3)

		returnVal = a + b

	} else { // Buffer
		if p.buffer[string(AlgType("Padovan"))][input] != 0 {
			return p.buffer[string(AlgType("Padovan"))][input], nil
		} else {
			// Do normal calculation
			if input == 1 || input == 2 || input == 3 {
				return 1, nil
			}

			a, _ := p.GetVal(input - 2)
			b, _ := p.GetVal(input - 3)

			returnVal = a + b

			// Store result in buffer
			p.buffer[string(AlgType("Padovan"))][input] = returnVal
		}
	}

	return returnVal, nil
}
