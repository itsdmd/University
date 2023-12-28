package sortalgos

// Context

type SortedList struct {
	Data []int
	Algo SortAlgo
}

func InitSL(data []int, algo SortAlgo) *SortedList {
	return &SortedList{
		Data: data,
		Algo: algo,
	}
}

func (sl *SortedList) SetAlgo(algo SortAlgo) {
	sl.Algo = algo
}

func (sl *SortedList) Sort() []int {
	return sl.Algo.Sort(sl.Data)
}
