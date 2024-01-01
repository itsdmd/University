package main

import (
	"io"
	"os"
	"testing"
)

func TestSortArray_Bubble(t *testing.T) {
	in, err := os.CreateTemp("", "")
	if err != nil {
		t.Fatal(err)
	}
	defer in.Close()

	_, err = io.WriteString(in, "1\n")
	if err != nil {
		t.Fatal(err)
	}

	_, err = in.Seek(0, io.SeekStart)
	if err != nil {
		t.Fatal(err)
	}

	sortedArray := sortArray(in)

	// Check that the array is sorted
	for i := 1; i < len(sortedArray); i++ {
		for j := i + 1; j < len(sortedArray); j++ {
			if sortedArray[i] > sortedArray[j] {
				t.Errorf("Array is not sorted at index %d and %d", i, j)
			}
		}
	}
}

func TestSortArray_Interchange(t *testing.T) {
	in, err := os.CreateTemp("", "")
	if err != nil {
		t.Fatal(err)
	}
	defer in.Close()

	_, err = io.WriteString(in, "2\n")
	if err != nil {
		t.Fatal(err)
	}

	_, err = in.Seek(0, io.SeekStart)
	if err != nil {
		t.Fatal(err)
	}

	sortedArray := sortArray(in)

	// Check that the array is sorted
	for i := 1; i < len(sortedArray); i++ {
		for j := i + 1; j < len(sortedArray); j++ {
			if sortedArray[i] > sortedArray[j] {
				t.Errorf("Array is not sorted at index %d and %d", i, j)
			}
		}
	}
}
