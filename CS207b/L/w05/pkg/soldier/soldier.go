package soldier

type ISoldier interface {
	Hit() int
	WardOff(int) bool // Indicates whether the soldier is still alive
}

type Infantryman struct{}

func (i *Infantryman) Hit() int {
	return 5
}

func (i *Infantryman) WardOff(damage int) bool {
	return damage <= 5
}

type Horseman struct{}

func (h *Horseman) Hit() int {
	return 10
}

func (h *Horseman) WardOff(damage int) bool {
	return damage <= 15
}
