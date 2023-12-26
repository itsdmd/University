import importlib


class SortedList:
    algo = None
    arr = []

    def __init__(self, algo_name):
        try:
            # Dynamically import the module
            self.algo = importlib.import_module(
                "sort_algos." + algo_name)
        except ImportError:
            print("Error: " + algo_name + " is not a valid sorting algorithm")
            exit(1)

    def sort(self, arr):
        return self.algo.sort(arr)

    def print(self):
        print(self.algo.arr)
