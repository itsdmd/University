package formatter

import (
	"207w04/customer"
	"strconv"
)

type PlainTextFormatter struct {
	result string
}

func NewPlainTextFormatter() PlainTextFormatter {
	return PlainTextFormatter{}
}

func (f *PlainTextFormatter) GetStatement(customer customer.Customer) string {
	result := "Rental Record for " + customer.GetName() + "\n"
	result += "Amount owed is " + strconv.FormatFloat(customer.GetTotalCharge(), 'f', -1, 64) + "\n"
	result += "You earned " + strconv.Itoa(customer.GetTotalFrequentRenterPoints()) + " frequent renter points"
	return result
}
