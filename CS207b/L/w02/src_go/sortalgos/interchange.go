package sortalgos

type InterchangeSort struct{}

func (b *InterchangeSort) Sort(input []int) []int {
	return Sort(input)
}

func (b *InterchangeSort) Name() string {
	return "Interchange Sort"
}
