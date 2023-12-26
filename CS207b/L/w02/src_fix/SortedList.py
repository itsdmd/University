from sort_algos.SortAlgo import SortAlgo
import abc


class SortAlgoABC(metaclass=abc.ABCMeta):
    @abc.abstractmethod
    def sort(self, arr):
        pass


class SortedList:
    algo = SortAlgoABC
    arr = []

    def __init__(self, algo_name):
        self.algo = SortAlgo(algo_name)

    def sort(self, arr):
        self.arr = self.algo.sort(arr)
        return self.arr

    def print(self):
        print(self.arr)
