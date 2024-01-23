package shapes

import (
	"fmt"
)

type BackgroundStyle string

const (
	Transparent BackgroundStyle = "không nền"
	Opaque      BackgroundStyle = "nền đơn sắc"
	Gradient    BackgroundStyle = "nền chuyển sắc gradient"
	Radial      BackgroundStyle = "nền chuyển sắc radial"
)

type BackgroundFillStyle string

const (
	Recursive    BackgroundFillStyle = "đệ quy"
	NonRecursive BackgroundFillStyle = "không đệ quy"
)

type Background struct {
	Shape     IShape
	Style     BackgroundStyle
	Color     []Color
	FillStyle BackgroundFillStyle
}

func (b *Background) GetName() string {
	return b.Shape.GetName()
}

func (b *Background) Draw() {
	b.Shape.Draw()
	fmt.Print(", " + string(b.Style))
	switch len(b.Color) {
	case 0:
		fmt.Print()
	case 1:
		fmt.Print(" " + string(b.Color[0]))
	default:
		fmt.Print(" " + string(b.Color[0]))
		for i := 1; i < len(b.Color); i++ {
			fmt.Print("-" + string(b.Color[i]))
		}
	}
	if b.FillStyle != "" {
		fmt.Print(" tô " + string(b.FillStyle))
	}
}
