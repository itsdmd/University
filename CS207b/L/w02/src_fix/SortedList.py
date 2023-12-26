from sort_algos.SortStrat import SortStrat


class SortedList:
    algo = None

    def __init__(self, algo_name):
        self.algo = SortStrat(algo_name)

    def sort(self, arr):
        return self.algo.sort(arr)

    def print(self):
        print(self.algo.arr)
