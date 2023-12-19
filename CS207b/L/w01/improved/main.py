from model.Customer import Customer
from model.Movie import Movie
from model.Rental import Rental

# Write the main program to implement the following use cases:
# A client has lend 3 movies :
# ”Rogue One” of type NEW RELESASE during 5 days ,
# ”Frozen” of type CHILDREN during 7 days,
# ”Star Wars III” of type REGULAR during 4 days.
# Information about the client will be displayed on the standard output.

# Create movies
movie1 = Movie("Rogue One", Movie.NEW_RELEASE)
movie2 = Movie("Frozen", Movie.CHILDRENS)
movie3 = Movie("Star Wars III", Movie.REGULAR)

# Create rentals
rental1 = Rental(movie1, 5)
rental2 = Rental(movie2, 7)
rental3 = Rental(movie3, 4)

# Create customer
customer = Customer("John Doe")

# Add rentals to customer
customer.add_rental(rental1)
customer.add_rental(rental2)
customer.add_rental(rental3)

# Print statement
print(customer.statement())
