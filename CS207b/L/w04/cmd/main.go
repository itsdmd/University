package main

import (
	"207w04/customer"
	"207w04/customer/formatter"
	"207w04/movie"
	"fmt"
)

func main() {
	REGULAR := movie.NewMovieType(0, 0, 2, 2, 1.5)
	NEW_RELEASE := movie.NewMovieType(1, 0, 2, 2, 2)
	CHILDRENS := movie.NewMovieType(2, 0, 1.5, 3, 1.5)

	movie1 := movie.NewMovie("The Matrix", REGULAR)
	movie2 := movie.NewMovie("The Lord of the Rings", NEW_RELEASE)
	movie3 := movie.NewMovie("The Lion King", CHILDRENS)

	customer1 := customer.NewCustomer("John Doe")
	customer1.AddRental(customer.NewRental(movie1, 3))
	customer1.AddRental(customer.NewRental(movie2, 2))
	customer1.AddRental(customer.NewRental(movie3, 7))

	plainTextFormatter := formatter.NewPlainTextFormatter()
	htmlFormatter := formatter.NewHTMLFormatter()

	fmt.Println(plainTextFormatter.GetStatement(customer1))
	fmt.Print("\n\n")
	fmt.Println(htmlFormatter.GetStatement(customer1))
}
