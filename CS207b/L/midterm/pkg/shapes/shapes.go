package shapes

type IShape interface {
	GetName() string
	Draw()
}

type IShapeFactory interface {
	MakeShape() IShape
}

func GetShapeFactory(name string) IShapeFactory {
	switch name {
	case "circle":
		return &CircleFactory{}
	case "square":
		return &SquareFactory{}
	default:
		return nil
	}
}
