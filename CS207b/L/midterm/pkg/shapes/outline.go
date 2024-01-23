package shapes

import (
	"fmt"
)

type OutlineStyle string

const (
	None   OutlineStyle = "không viền"
	Dotted OutlineStyle = "có viền nét chấm gạch"
	Dashed OutlineStyle = "có viền nét đứt"
	Solid  OutlineStyle = "có viền nét liền"
)

type Outline struct {
	Shape IShape
	Style OutlineStyle
	Color Color
}

func (o *Outline) GetName() string {
	return o.Shape.GetName()
}

func (o *Outline) Draw() {
	o.Shape.Draw()
	fmt.Print(", " + string(o.Style))
	switch o.Color {
	case "":
		fmt.Print()
	default:
		fmt.Print(" màu " + string(o.Color))
	}
}
