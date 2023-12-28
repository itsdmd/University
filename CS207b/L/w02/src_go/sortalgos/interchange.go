package sortalgos

type InterchangeSort struct{}

func (b *InterchangeSort) Sort(input []int) []int {
	for i := 0; i < len(input); i++ {
		for j := i + 1; j < len(input); j++ {
			if input[i] > input[j] {
				input[i], input[j] = input[j], input[i]
			}
		}
	}
	return input
}

func (b *InterchangeSort) Name() string {
	return "Interchange Sort"
}
