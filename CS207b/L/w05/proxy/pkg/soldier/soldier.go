package soldier

type SoldierType string

const (
	INFANTRYMAN SoldierType = "INFANTRYMAN"
	HORSEMAN    SoldierType = "HORSEMAN"
)

type ISoldier interface {
	GetType() SoldierType
	Hit() int
	WardOff(int) bool // Indicates whether the soldier is still alive
}

type Infantryman struct{}

func (i *Infantryman) GetType() SoldierType {
	return INFANTRYMAN
}

func (i *Infantryman) Hit() int {
	return 5
}

func (i *Infantryman) WardOff(damage int) bool {
	return damage <= 5
}

func (h *Horseman) GetType() SoldierType {
	return HORSEMAN
}

type Horseman struct{}

func (h *Horseman) Hit() int {
	return 10
}

func (h *Horseman) WardOff(damage int) bool {
	return damage <= 15
}
