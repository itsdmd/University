package equipment

import (
	"207w05proxy/soldier"
)

type Database struct {
	data map[soldier.ISoldier][]Equipment
}

func (d *Database) Equip(s soldier.ISoldier, e Equipment) {
	// Check if a soldier of same type that is already equipped with the same equipment exists
	for _, v := range d.data[s] {
		if v == e {
			return // No need to equip
		}
	}

	d.data[s] = append(d.data[s], e)
}

func (d *Database) Unequip(s soldier.ISoldier, e Equipment) {
	for i, v := range d.data[s] {
		if v == e {
			d.data[s] = append(d.data[s][:i], d.data[s][i+1:]...)
			break
		}
	}
}

func (d *Database) Get(s soldier.ISoldier) []Equipment {
	return d.data[s]
}
