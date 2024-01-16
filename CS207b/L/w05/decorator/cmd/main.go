package main

import (
	"207w05/soldier"
	"fmt"
)

func main() {
	infantry := &soldier.Infantryman{}

	infantryWithSword := &soldier.Sword{
		Soldier: infantry,
	}

	infantryWithSwordAndShield := &soldier.Shield{
		Soldier: infantryWithSword,
	}

	horseman := &soldier.Horseman{}

	horsemanWithSword := &soldier.Sword{
		Soldier: horseman,
	}

	horsemanWithSwordAndShield := &soldier.Shield{
		Soldier: horsemanWithSword,
	}

	fmt.Println("Infantryman with sword and shield:")
	fmt.Println("Hit:", infantryWithSwordAndShield.Hit())
	fmt.Println("Ward off 25:", infantryWithSwordAndShield.WardOff(25))

	fmt.Println("Horseman with sword and shield:")
	fmt.Println("Hit:", horsemanWithSwordAndShield.Hit())
	fmt.Println("Ward off 25:", horsemanWithSwordAndShield.WardOff(25))
}
