package sortalgos

// Strategy interface

type SortAlgo interface {
	Name() string
	Sort(data []int) []int
}
