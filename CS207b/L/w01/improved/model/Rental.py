class Rental:
    __movie = None
    __days_rented = None

    def __init__(self, movie, days_rented):
        self.__movie = movie
        self.__days_rented = days_rented

    def get_movie(self):
        return self.__movie

    def get_days_rented(self):
        return self.__days_rented
