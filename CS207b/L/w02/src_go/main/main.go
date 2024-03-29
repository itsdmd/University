package main

import (
	"207w02/sortalgos"
	"fmt"
	"math/rand"
	"os"
)

func randomArray(length int) []int {
	var arr []int
	for i := 0; i < length; i++ {
		arr = append(arr, rand.Intn(100))
	}
	return arr
}

func sortArray(in *os.File) []int {
	if in == nil {
		in = os.Stdin
	}
	arr := randomArray(25)
	fmt.Println("Unsorted array: ", arr)

	algoMap := map[int]sortalgos.SortAlgo{
		1: &sortalgos.BubbleSort{},
		2: &sortalgos.InterchangeSort{},
	}

	// List all available algorithms and their corresponding index
	for index, algo := range algoMap {
		fmt.Printf("%d. %s\n", index, algo.Name())
	}
	fmt.Print("0. Quit\n\n")
	fmt.Print("Enter the index of the algorithm you want to use: ")
	var algoIndex int
	fmt.Fscanf(in, "%d", &algoIndex)

	// Exit if user enters 0 or value greater than the number of algorithms
	if algoIndex == 0 || algoIndex > len(algoMap) {
		os.Exit(0)
	}

	algo := algoMap[algoIndex]
	sl := sortalgos.InitSL(arr, algo)
	sorted := sl.Sort()

	fmt.Println("Sorted data:", sorted)
	return sorted
}

func main() {
	sortArray(nil)
}
