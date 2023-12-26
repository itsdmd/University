class SortedList:
    __list = []

    def __init__(self, numbers):
        self.__list = numbers

    def selectionSort(self):
        for i in range(len(self.__list)):
            minPosition = i
            for j in range(i, len(self.__list)):
                if self.__list[j] < self.__list[minPosition]:
                    minPosition = j
            self.__list[i], self.__list[minPosition] = (
                self.__list[minPosition],
                self.__list[i],
            )
        return self.__list

    def bubbleSort(self):
        for i in range(len(self.__list)):
            for j in range(len(self.__list) - 1):
                if self.__list[j] > self.__list[j + 1]:
                    self.__list[j], self.__list[j + 1] = (
                        self.__list[j + 1],
                        self.__list[j],
                    )
        return self.__list

    def countingSort(self):
        print("Counting Sort")

    def radixSort(self):
        print("Radix Sort")

    def interchangeSort(self):
        print("Interchange Sort")

    def print(self):
        print(self.__list)
