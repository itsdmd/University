package movie

type MovieType struct {
	index                    int
	initialCharge            float64
	daysBeforeAdditionCharge float64
	additionalDailyRate      float64
	frequentRenterPoints     int
}

func NewMovieType(index int, initialCharge, daysBeforeAdditionCharge, additionalDailyRate float64, frequentRenterPoints int) MovieType {
	return MovieType{index: index, daysBeforeAdditionCharge: daysBeforeAdditionCharge, additionalDailyRate: additionalDailyRate, frequentRenterPoints: frequentRenterPoints}
}

type Movie struct {
	title     string
	movieType MovieType
}

func NewMovie(title string, movieType MovieType) Movie {
	return Movie{title: title, movieType: movieType}
}

func (m *Movie) GetTitle() string {
	return m.title
}

func (m *Movie) SetMovieType(movieType MovieType) {
	m.movieType = movieType
}

func (m *Movie) GetPriceCode() int {
	return m.movieType.index
}

func (m *Movie) SetPriceCode(arg int) {
	m.movieType.index = arg
}

func (m *Movie) GetCharge(daysRented int) float64 {
	daysRentedFloat := float64(daysRented)
	result := m.movieType.initialCharge
	if daysRentedFloat > m.movieType.daysBeforeAdditionCharge {
		result += (daysRentedFloat - m.movieType.daysBeforeAdditionCharge) * m.movieType.additionalDailyRate
	}
	return result
}

func (m *Movie) GetFrequentRenterPoints() int {
	return m.movieType.frequentRenterPoints
}
