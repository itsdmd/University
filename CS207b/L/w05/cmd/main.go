package main

import (
	"207w05/employee"
	"fmt"
)

func main() {
	fmt.Println("A: TEAM MEMBER:")
	fmt.Println("-------")
	tm1 := &employee.Cooperate{Employee: &employee.ReportTask{Employee: &employee.Employee{Name: "MEMBER"}}}
	fmt.Printf("The basic information of %s:\n", tm1.GetName())
	tm1.Join("2020-07-01")
	tm1.Terminate("2020-07-31")
	tm1.DoTask()

	fmt.Println("\nB: TEAM LEADER:")
	fmt.Println("-------")
	tl1 := &employee.Planning{Employee: &employee.Motivate{Employee: &employee.Monitor{Employee: &employee.Employee{Name: "LEADER"}}}}
	fmt.Printf("The basic information of %s:\n", tl1.GetName())
	tl1.Join("2020-07-01")
	tl1.Terminate("2020-07-31")
	tl1.DoTask()

	fmt.Println("\nC: MANAGER:")
	fmt.Println("-------")
	m1 := &employee.CreateRequirement{Employee: &employee.AssignTask{Employee: &employee.ManageProgress{Employee: &employee.Employee{Name: "MANAGER"}}}}
	fmt.Printf("The basic information of %s:\n", m1.GetName())
	m1.Join("2020-07-01")
	m1.Terminate("2020-07-31")
	m1.DoTask()

	fmt.Println("\nD: TEAM LEADER AND MANAGER:")
	fmt.Println("-------")
	tlm1 := &employee.Concurrent{Employees: []employee.IEmployee{tl1.SetName("L&M"), m1.SetName("L&M")}}
	fmt.Printf("The basic information of %s:\n", tlm1.GetName())
	tlm1.Join("2020-07-01")
	tlm1.Terminate("2020-07-31")
	tlm1.DoTask()
}
