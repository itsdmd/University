package employee

import (
	"fmt"
)

/* ----------------------- Concurrent ----------------------- */

// Decorate with tasks of another employee
type Concurrent struct {
	Employees []IEmployee
}

func (c *Concurrent) GetName() string {
	return ""
}

func (c *Concurrent) SetName(name string) IEmployee {
	return c
}

func (c *Concurrent) DoTask() {
	for _, e := range c.Employees {
		e.DoTask()
	}
}

func (c *Concurrent) Join(time string) {
	c.Employees[0].Join(time)
}

func (c *Concurrent) Terminate(time string) {
	c.Employees[0].Terminate(time)
}

/* ----------------------- ReportTask ----------------------- */
type ReportTask struct {
	Employee IEmployee
}

func (r *ReportTask) GetName() string {
	return r.Employee.GetName()
}

func (r *ReportTask) SetName(name string) IEmployee {
	r.Employee.SetName(name)
	return r
}

func (r *ReportTask) DoTask() {
	r.Employee.DoTask()
	fmt.Printf("%s is reporting\n", r.Employee.GetName())
}

func (r *ReportTask) Join(time string) {
	r.Employee.Join(time)
}

func (r *ReportTask) Terminate(time string) {
	r.Employee.Terminate(time)
}

/* ----------------------- Cooperate  ----------------------- */
type Cooperate struct {
	Employee IEmployee
}

func (c *Cooperate) GetName() string {
	return c.Employee.GetName()
}

func (c *Cooperate) SetName(name string) IEmployee {
	c.Employee.SetName(name)
	return c
}

func (c *Cooperate) DoTask() {
	c.Employee.DoTask()
	fmt.Printf("%s is cooperating\n", c.Employee.GetName())
}

func (c *Cooperate) Join(time string) {
	c.Employee.Join(time)
}

func (c *Cooperate) Terminate(time string) {
	c.Employee.Terminate(time)
}

/* ------------------------ Planning ------------------------ */
type Planning struct {
	Employee IEmployee
}

func (p *Planning) GetName() string {
	return p.Employee.GetName()
}

func (p *Planning) SetName(name string) IEmployee {
	p.Employee.SetName(name)
	return p
}

func (p *Planning) DoTask() {
	p.Employee.DoTask()
	fmt.Printf("%s is planning\n", p.Employee.GetName())
}

func (p *Planning) Join(time string) {
	p.Employee.Join(time)
}

func (p *Planning) Terminate(time string) {
	p.Employee.Terminate(time)
}

/* ------------------------ Motivate ------------------------ */
type Motivate struct {
	Employee IEmployee
}

func (m *Motivate) GetName() string {
	return m.Employee.GetName()
}

func (m *Motivate) SetName(name string) IEmployee {
	m.Employee.SetName(name)
	return m
}

func (m *Motivate) DoTask() {
	m.Employee.DoTask()
	fmt.Printf("%s is motivating\n", m.Employee.GetName())
}

func (m *Motivate) Join(time string) {
	m.Employee.Join(time)
}

func (m *Motivate) Terminate(time string) {
	m.Employee.Terminate(time)
}

/* ------------------------ Monitor  ------------------------ */
type Monitor struct {
	Employee IEmployee
}

func (m *Monitor) GetName() string {
	return m.Employee.GetName()
}

func (m *Monitor) SetName(name string) IEmployee {
	m.Employee.SetName(name)
	return m
}

func (m *Monitor) DoTask() {
	m.Employee.DoTask()
	fmt.Printf("%s is monitoring\n", m.Employee.GetName())
}

func (m *Monitor) Join(time string) {
	m.Employee.Join(time)
}

func (m *Monitor) Terminate(time string) {
	m.Employee.Terminate(time)
}

/* ------------------- CreateRequirement  ------------------- */
type CreateRequirement struct {
	Employee IEmployee
}

func (c *CreateRequirement) GetName() string {
	return c.Employee.GetName()
}

func (c *CreateRequirement) SetName(name string) IEmployee {
	c.Employee.SetName(name)
	return c
}

func (c *CreateRequirement) DoTask() {
	c.Employee.DoTask()
	fmt.Printf("%s is creating requirement\n", c.Employee.GetName())
}

func (c *CreateRequirement) Join(time string) {
	c.Employee.Join(time)
}

func (c *CreateRequirement) Terminate(time string) {
	c.Employee.Terminate(time)
}

/* ----------------------- AssignTask ----------------------- */
type AssignTask struct {
	Employee IEmployee
}

func (a *AssignTask) GetName() string {
	return a.Employee.GetName()
}

func (a *AssignTask) SetName(name string) IEmployee {
	a.Employee.SetName(name)
	return a
}

func (a *AssignTask) DoTask() {
	a.Employee.DoTask()
	fmt.Printf("%s is assigning task\n", a.Employee.GetName())
}

func (a *AssignTask) Join(time string) {
	a.Employee.Join(time)
}

func (a *AssignTask) Terminate(time string) {
	a.Employee.Terminate(time)
}

/* --------------------- ManageProgress --------------------- */
type ManageProgress struct {
	Employee IEmployee
}

func (m *ManageProgress) GetName() string {
	return m.Employee.GetName()
}

func (m *ManageProgress) SetName(name string) IEmployee {
	m.Employee.SetName(name)
	return m
}

func (m *ManageProgress) DoTask() {
	m.Employee.DoTask()
	fmt.Printf("%s is managing progress\n", m.Employee.GetName())
}

func (m *ManageProgress) Join(time string) {
	m.Employee.Join(time)
}

func (m *ManageProgress) Terminate(time string) {
	m.Employee.Terminate(time)
}
