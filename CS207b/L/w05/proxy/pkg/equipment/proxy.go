package equipment

import (
	"207w05proxy/soldier"
)

type Proxy struct{}

func (p *Proxy) AddSword(s soldier.ISoldier) {
	h := Handler{dtb: &Database{}}
	h.Handle(s, (&Sword{}).New(), EQUIP)
}

func (p *Proxy) AddShield(s soldier.ISoldier) {
	h := Handler{dtb: &Database{}}
	h.Handle(s, (&Shield{}).New(), EQUIP)
}

func (p *Proxy) RemoveSword(s soldier.ISoldier) {
	h := Handler{dtb: &Database{}}
	h.Handle(s, (&Sword{}).New(), EQUIP)
}

func (p *Proxy) RemoveShield(s soldier.ISoldier) {
	h := Handler{dtb: &Database{}}
	h.Handle(s, (&Shield{}).New(), UNEQUIP)
}

func (p *Proxy) Hit(s soldier.ISoldier) int {
	h := Handler{dtb: &Database{}}
	dummyEquipment := (&Sword{}).New()
	equipment := h.Handle(s, dummyEquipment, GET)
	damageDealt := s.Hit()

	return damageDealt
}

type Method string

const (
	EQUIP   Method = "EQUIP"
	UNEQUIP Method = "UNEQUIP"
	GET     Method = "GET"
)

type Handler struct {
	dtb *Database
}

func (h *Handler) Handle(s soldier.ISoldier, e Equipment, method Method) []Equipment {
	switch method {
	case EQUIP:
		h.dtb.Equip(s, e)
		return nil

	case UNEQUIP:
		h.dtb.Unequip(s, e)
		return nil

	case GET:
		return h.dtb.Get(s)

	default:
		panic("Invalid method")
	}
}
