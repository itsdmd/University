package soldier

type Sword struct {
	Soldier ISoldier
}

func (s *Sword) Hit() int {
	return s.Soldier.Hit() + 10
}

func (s *Sword) WardOff(damage int) bool {
	return s.Soldier.WardOff(damage)
}

type Shield struct {
	Soldier ISoldier
}

func (s *Shield) Hit() int {
	return s.Soldier.Hit()
}

func (s *Shield) WardOff(damage int) bool {
	return s.Soldier.WardOff(damage - 10)
}
