package algorithm

import "fmt"

type Fibonacci struct {
	buffer map[string]map[uint8]uint64
}

func (f *Fibonacci) CreateMemoryBufferVersion(buffer map[string]map[uint8]uint64) IAlgorithm {
	return &Fibonacci{buffer: buffer}
}

func (f *Fibonacci) CreateNonMemoryBufferVersion() IAlgorithm {
	return &Fibonacci{}
}

func (f *Fibonacci) GetName() string {
	return string(FIBONACCI)
}

func (f *Fibonacci) GetVal(input uint8) (uint64, error) {
	if input <= 0 {
		return 0, fmt.Errorf("input must be greater than 0")
	}

	var returnVal uint64

	if f.buffer[string(FIBONACCI)] == nil { // NonBuffer
		if input <= 0 {
			return 0, fmt.Errorf("input must be greater than 0")
		}

		if input == 1 {
			return 1, nil
		}

		a, _ := f.GetVal(input - 1)
		b, _ := f.GetVal(input - 2)

		returnVal = a + b
	} else { // Buffer
		if f.buffer[string(FIBONACCI)][input] != 0 {
			return f.buffer[string(FIBONACCI)][input], nil
		} else {
			if input == 1 {
				return 1, nil
			}

			a, _ := f.GetVal(input - 1)
			b, _ := f.GetVal(input - 2)

			returnVal = a + b

			// Store result in buffer
			f.buffer[string(FIBONACCI)][input] = returnVal
		}
	}

	return returnVal, nil
}
