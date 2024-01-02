package main

import (
	"207w03/pkg/algorithm"
	"fmt"
)

func main() {
	padovanNon := algorithm.GetFactory(algorithm.PADOVAN).CreateNonMemoryBufferVersion()
	fmt.Println(padovanNon.GetName())
	fmt.Println(padovanNon.GetVal(10))

	fibonacciNon := algorithm.GetFactory(algorithm.FIBONACCI).CreateNonMemoryBufferVersion()
	fmt.Println(fibonacciNon.GetName())
	fmt.Println(fibonacciNon.GetVal(10))

	buffer := make(map[string]map[uint64]uint64)

	padovanFactory := algorithm.GetFactory(algorithm.PADOVAN).CreateMemoryBufferVersion(buffer)
	fmt.Println(padovanFactory.GetName())
	fmt.Println(padovanFactory.GetVal(10))

	fibonacciFactory := algorithm.GetFactory(algorithm.FIBONACCI).CreateMemoryBufferVersion(buffer)
	fmt.Println(fibonacciFactory.GetName())
	fmt.Println(fibonacciFactory.GetVal(10))
}
