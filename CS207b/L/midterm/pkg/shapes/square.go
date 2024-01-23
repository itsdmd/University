package shapes

import (
	"fmt"
)

type Square struct{}

func (s *Square) GetName() string {
	return "hình vuông"
}

func (s *Square) Draw() {
	fmt.Print(s.GetName())
}

type SquareFactory struct{}

func (f *SquareFactory) MakeShape() IShape {
	return &Square{}
}
