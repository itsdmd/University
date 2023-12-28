package sortalgos

// Concrete strategy
func Sort(input []int) []int {
	swapped := true

	for swapped {
		swapped = false

		for i := 1; i < len(input); i++ {
			if input[i-1] > input[i] {
				input[i], input[i-1] = input[i-1], input[i]
				swapped = true
			}
		}
	}

	return input

}

type BubbleSort struct{}

func (b *BubbleSort) Sort(input []int) []int {
	return Sort(input)
}

func (b *BubbleSort) Name() string {
	return "Bubble Sort"
}
