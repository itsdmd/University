package equipment

type StatType string

const (
	HEALTH   StatType = "HEALTH"
	STRENGTH StatType = "STRENGTH"
	ARMOR    StatType = "ARMOR"
)

type Equipment struct {
	StatType StatType
}

type IEquipment interface {
	New() IEquipment
	ModifyStat(int) (StatType, int)
}

type (
	Sword  struct{ Equipment }
	Shield struct{ Equipment }
)

func (s *Sword) New() Equipment {
	return Equipment{StatType: STRENGTH}
}

func (s *Sword) ModifyStat(i int) (StatType, int) {
	return s.StatType, i + 5
}

func (s *Shield) New() Equipment {
	return Equipment{StatType: ARMOR}
}

func (s *Shield) ModifyStat(i int) (StatType, int) {
	return s.StatType, i + 10
}
