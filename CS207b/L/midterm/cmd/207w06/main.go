package main

import (
	"207w06/shapes"
	"fmt"
)

func main() {
	// kết quả in ra: "hình vuông, không viền, nền đơn sắc trắng tô đệ quy"
	shapeFactory := shapes.GetShapeFactory("square")
	shape := shapeFactory.MakeShape()
	shape = &shapes.Outline{Shape: shape, Style: shapes.None}
	shape = &shapes.Background{Shape: shape, Style: shapes.Opaque, Color: []shapes.Color{shapes.White}, FillStyle: shapes.Recursive}
	shape.Draw()
	fmt.Println()

	// kết quả in ra: "hình tròn, có viền nét đứt màu đen, không nền"
	shapeFactory = shapes.GetShapeFactory("circle")
	shape = shapeFactory.MakeShape()
	shape = &shapes.Outline{Shape: shape, Style: shapes.Dashed, Color: shapes.Black}
	shape = &shapes.Background{Shape: shape, Style: shapes.Transparent}
	shape.Draw()
	fmt.Println()

	// kết quả in ra: "hình tròn, có viền nét chấm gạch màu đỏ, nền chuyển sắc radial vàng-trắng tô không đệ quy"
	shapeFactory = shapes.GetShapeFactory("circle")
	shape = shapeFactory.MakeShape()
	shape = &shapes.Outline{Shape: shape, Style: shapes.Dotted, Color: shapes.Red}
	shape = &shapes.Background{Shape: shape, Style: shapes.Radial, Color: []shapes.Color{shapes.Yellow, shapes.White}, FillStyle: shapes.NonRecursive}
	shape.Draw()
	fmt.Println()
}
