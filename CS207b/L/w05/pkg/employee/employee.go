package employee

import (
	"fmt"
)

type IEmployee interface {
	GetName() string
	DoTask()
	Join(string)      // Join a team, take time string as parameter
	Terminate(string) // Terminates from a team, take time string as parameter
}

type Employee struct{ Name string }

func (e *Employee) GetName() string {
	return e.Name
}

func (e *Employee) DoTask() {}

func (e *Employee) Join(time string) {
	fmt.Printf("%s joined on %s\n", e.GetName(), time)
}

func (e *Employee) Terminate(time string) {
	fmt.Printf("%s terminated on %s\n", e.GetName(), time)
}
