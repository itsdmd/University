package formatter

import (
	"207w04/customer"
	"strconv"
)

type HTMLFormatter struct {
	result string
}

func NewHTMLFormatter() HTMLFormatter {
	return HTMLFormatter{}
}

func (f *HTMLFormatter) GetStatement(customer customer.Customer) string {
	result := "<h1>Rental Record for <em>" + customer.GetName() + "</em></h1>\n"
	result += "<p>Amount owed is <em>" + strconv.FormatFloat(customer.GetTotalCharge(), 'f', -1, 64) + "</em></p>\n"
	result += "<p>You earned <em>" + strconv.Itoa(customer.GetTotalFrequentRenterPoints()) + "</em> frequent renter points</p>"

	return result
}
