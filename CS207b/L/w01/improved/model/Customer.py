from model.Movie import Movie
from model.Rental import Rental


class Customer:
    __name = None
    __rentals = []

    def __init__(self, name):
        self.__name = name

    def add_rental(self, rental):
        self.__rentals.append(rental)

    def get_name(self):
        return self.__name

    def statement(self):
        total_amount = 0
        frequent_renter_points = 0
        result = "Rental Record for " + self.get_name() + "\n"

        for rental in self.__rentals:
            this_amount = rental.get_charge()

            # add frequent renter points
            frequent_renter_points += 1
            # add bonus for a two day new release rental
            if (
                rental.get_movie().get_price_code() == Movie.NEW_RELEASE.get_code()
                and rental.get_days_rented() > 1
            ):
                frequent_renter_points += 1

            # show figures for this rental
            result += (
                "\t" + rental.get_movie().get_title() + "\t" + str(this_amount) + "\n"
            )
            total_amount += this_amount

        # add footer lines
        result += "Amount owed is " + str(total_amount) + "\n"
        result += (
            "You earned " + str(frequent_renter_points) + " frequent renter points"
        )
        return result
