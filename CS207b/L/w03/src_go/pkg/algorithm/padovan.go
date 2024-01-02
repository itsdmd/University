package algorithm

import "fmt"

type Padovan struct {
	buffer map[string]map[uint8]uint64
}

func (f *Padovan) CreateMemoryBufferVersion(buffer map[string]map[uint8]uint64) IAlgorithm {
	return &Padovan{buffer: buffer}
}

func (f *Padovan) CreateNonMemoryBufferVersion() IAlgorithm {
	return &Padovan{}
}

func (p *Padovan) GetName() string {
	return string(PADOVAN)
}

func (p *Padovan) GetVal(input uint8) (uint64, error) {
	if input <= 0 {
		return 0, fmt.Errorf("input must be greater than 0")
	}

	var returnVal uint64

	if p.buffer[string(PADOVAN)] == nil { // NonBuffer
		if input == 1 || input == 2 || input == 3 {
			return 1, nil
		}

		a, _ := p.GetVal(input - 2)
		b, _ := p.GetVal(input - 3)

		returnVal = a + b

	} else { // Buffer
		if p.buffer[string(PADOVAN)][input] != 0 {
			return p.buffer[string(PADOVAN)][input], nil
		} else {
			// Do normal calculation
			if input == 1 || input == 2 || input == 3 {
				return 1, nil
			}

			a, _ := p.GetVal(input - 2)
			b, _ := p.GetVal(input - 3)

			returnVal = a + b

			// Store result in buffer
			p.buffer[string(PADOVAN)][input] = returnVal
		}
	}

	return returnVal, nil
}
