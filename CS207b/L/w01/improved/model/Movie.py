class PriceCode:
    __code = None
    __days_before_additional_charge = None
    __additional_charge_rate = None

    def __init__(self, code, days_before_additional_charge, additional_charge_rate):
        self.__code = code
        self.__days_before_additional_charge = days_before_additional_charge
        self.__additional_charge_rate = additional_charge_rate

    def get_code(self):
        return self.__code

    def set_code(self, arg):
        self.__code = arg

    def get_days_before_additional_charge(self):
        return self.__days_before_additional_charge

    def get_additional_charge_rate(self):
        return self.__additional_charge_rate

    def get_charge(self, days_rented):
        if days_rented <= self.__days_before_additional_charge:
            return days_rented
        else:
            return (
                self.__days_before_additional_charge
                + (days_rented - self.__days_before_additional_charge)
                * self.__additional_charge_rate
            )


class Movie:
    __title = None
    __price_code = None

    REGULAR = PriceCode(0, 2, 1.5)
    NEW_RELEASE = PriceCode(1, 0, 3)
    CHILDRENS = PriceCode(2, 3, 1.5)

    def __init__(self, title, priceCode):
        self.__title = title
        self.__price_code = priceCode

    def get_price_code(self):
        return self.__price_code.get_code()

    def set_price_code(self, priceCode):
        self.__price_code = priceCode

    def get_title(self):
        return self.__title

    def get_charge(self, days_rented):
        return self.__price_code.get_charge(days_rented)
