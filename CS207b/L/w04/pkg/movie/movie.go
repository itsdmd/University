package movie

type MovieType struct {
	index                    int
	initialCharge            float64
	baseDailyRate            float64
	daysBeforeAdditionCharge float64
	additionalDailyRate      float64
}

func NewMovieType(index int, initialCharge, baseDailyRate, daysBeforeAdditionCharge, additionalDailyRate float64) MovieType {
	return MovieType{index: index, initialCharge: initialCharge, baseDailyRate: baseDailyRate, daysBeforeAdditionCharge: daysBeforeAdditionCharge, additionalDailyRate: additionalDailyRate}
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
	} else {
		result += m.movieType.baseDailyRate * daysRentedFloat
	}
	return result
}
