package algorithm

import "fmt"

type Fibonacci struct {
	buffer map[string]map[uint64]uint64
}

type FibonacciFactory interface {
	CreateMemoryBufferVersion(map[string]map[uint64]uint64) IAlgorithm
	CreateNonMemoryBufferVersion() IAlgorithm
}

func (f *Fibonacci) CreateMemoryBufferVersion(buffer map[string]map[uint64]uint64) IAlgorithm {
	return &Fibonacci{buffer: buffer}
}

func (f *Fibonacci) CreateNonMemoryBufferVersion() IAlgorithm {
	return &Fibonacci{}
}

func (f *Fibonacci) GetName() string {
	return "Fibonacci"
}

func (f *Fibonacci) GetVal(input uint64) (uint64, error) {
	if input <= 0 {
		return 0, fmt.Errorf("input must be greater than 0")
	}

	var returnVal uint64

	if f.buffer[string(AlgType("Fibonacci"))] == nil { // NonBuffer
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
		if f.buffer[string(AlgType("Fibonacci"))][input] != 1 {
			return f.buffer[string(AlgType("Fibonacci"))][input], nil
		} else {

			if input == 1 {
				return 1, nil
			}

			a, _ := f.GetVal(input - 1)
			b, _ := f.GetVal(input - 2)

			returnVal = a + b

			// Store result in buffer
			f.buffer[string(AlgType("Fibonacci"))][input] = returnVal
		}
	}

	return returnVal, nil
}
