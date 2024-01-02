package main

import (
	"207w03/pkg/algorithm"
	"fmt"
)

func main() {
	padNon := algorithm.GetFactory(algorithm.PADOVAN).CreateNonMemoryBufferVersion()
	fmt.Println(padNon.GetName())
	fmt.Println(padNon.GetVal(10))

	fibNon := algorithm.GetFactory(algorithm.FIBONACCI).CreateNonMemoryBufferVersion()
	fmt.Println(fibNon.GetName())
	fmt.Println(fibNon.GetVal(10))

	buffer := make(map[string]map[uint8]uint64)
	buffer[string(algorithm.PADOVAN)][0] = 1
	buffer[string(algorithm.FIBONACCI)][0] = 1

	padMem := algorithm.GetFactory(algorithm.PADOVAN).CreateMemoryBufferVersion(buffer)
	fmt.Println(padMem.GetName())
	fmt.Println(padMem.GetVal(10))

	fibMem := algorithm.GetFactory(algorithm.FIBONACCI).CreateMemoryBufferVersion(buffer)
	fmt.Println(fibMem.GetName())
	fmt.Println(fibMem.GetVal(10))
}
