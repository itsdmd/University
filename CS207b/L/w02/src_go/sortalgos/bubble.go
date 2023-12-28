package sortalgos

type BubbleSort struct{}

func (b *BubbleSort) Sort(input []int) []int {
	return Sort(input)
}

func (b *BubbleSort) Name() string {
	return "Bubble Sort"
}
