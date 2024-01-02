package algorithm

type AlgType string

const (
	FIBONACCI AlgType = "Fibonacci"
	PADOVAN   AlgType = "Padovan"
)

type IAlgorithm interface {
	GetName() string
	GetVal(uint8) (uint64, error)
}

type AlgorithmAbstractFactory interface {
	GetFactory(AlgType) AlgorithmFactory
}

type AlgorithmFactory interface {
	CreateMemoryBufferVersion(map[string]map[uint8]uint64) IAlgorithm
	CreateNonMemoryBufferVersion() IAlgorithm
}

func GetFactory(algType AlgType) AlgorithmFactory {
	switch algType {
	case FIBONACCI:
		return &Fibonacci{}
	case PADOVAN:
		return &Padovan{}
	default:
		return nil
	}
}
