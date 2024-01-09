package customer

type Customer struct {
	name                 string
	rentals              []Rental
	frequentRenterPoints int
}

type ICustomer interface {
	NewCustomer(name string) Customer
	AddRental(rental Rental)
	GetName() string
	GetRentals() []Rental
	GetTotalCharge() int
	GetTotalFrequentRenterPoints() int
}

func NewCustomer(name string) Customer {
	return Customer{name: name}
}

func (c *Customer) AddRental(rental Rental) {
	c.rentals = append(c.rentals, rental)
}

func (c *Customer) GetName() string {
	return c.name
}

func (c *Customer) GetRentals() []Rental {
	return c.rentals
}

func (c *Customer) GetTotalCharge() float64 {
	var result float64 = 0
	for _, rental := range c.rentals {
		result += rental.GetCharge()
	}
	return result
}

func (c Customer) GetTotalFrequentRenterPoints() int {
	return 0
}
