package shapes

import (
	"fmt"
)

type Circle struct{}

func (c *Circle) GetName() string {
	return "hình tròn"
}
func (c *Circle) Draw() {
	fmt.Print(c.GetName())
}

type CircleFactory struct{}

func (f *CircleFactory) MakeShape() IShape {
	return &Circle{}
}
