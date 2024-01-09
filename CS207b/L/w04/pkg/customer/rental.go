package customer

import (
	"207w04/movie"
)

type Rental struct {
	movie      movie.Movie
	daysRented int
}

func NewRental(movie movie.Movie, daysRented int) Rental {
	return Rental{movie: movie, daysRented: daysRented}
}

func (r *Rental) GetMovie() movie.Movie {
	return r.movie
}

func (r *Rental) GetDaysRented() int {
	return r.daysRented
}

func (r *Rental) GetCharge() float64 {
	return r.movie.GetCharge(r.daysRented)
}
