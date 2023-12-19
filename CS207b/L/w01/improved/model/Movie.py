class Movie:
    REGULAR = 0
    NEW_RELEASE = 1
    CHILDRENS = 2

    __title = None
    __price_code = None

    def __init__(self, title, price_code):
        self.__title = title
        self.__price_code = price_code

    def get_price_code(self):
        return self.__price_code

    def set_price_code(self, arg):
        self.__price_code = arg

    def get_title(self):
        return self.__title
