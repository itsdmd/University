package algorithm

import (
	"207w03/pkg/algorithm"
	"math/rand"
	"testing"
	"time"
)

func TestPadovanConsistency(t *testing.T) {
	rand.NewSource(time.Now().UnixNano())
	randNum := uint8(rand.Intn(50))
	t.Log("Testing Padovan with", randNum)

	results := make(map[string]uint64)
	timeTaken := make(map[string]time.Duration)

	buffer := make(map[string]map[uint8]uint64)
	initialBuffer := make(map[uint8]uint64)
	initialBuffer[0] = 1
	buffer[string(algorithm.PADOVAN)] = initialBuffer

	start := time.Now()
	padMem, error := algorithm.GetFactory(algorithm.PADOVAN).CreateMemoryBufferVersion(buffer).GetVal(randNum)
	end := time.Now()
	timeTaken["Mem"] = end.Sub(start)

	if error != nil {
		t.Error(error)
	} else {
		results["Mem"] = padMem
	}

	start = time.Now()
	padNonMem, error := algorithm.GetFactory(algorithm.PADOVAN).CreateNonMemoryBufferVersion().GetVal(randNum)
	end = time.Now()
	timeTaken["NonMem"] = end.Sub(start)

	if error != nil {
		t.Error(error)
	} else {
		results["NonMem"] = padNonMem
	}

	// Iterate through map and check if all values are the same
	for name, value := range results {
		if value != padMem {
			t.Errorf("Expected all variations to return the same value, instead got %v for Mem and %v for %s", padMem, padNonMem, name)
		}
	}

	for name, value := range timeTaken {
		t.Logf("Time taken for %s: %v", name, value)
	}

	t.Log("Test complete. All variations returned the same value of", padMem)
}
