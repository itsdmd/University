import importlib


class SortStrat:
    sort = None

    def __init__(self, algo_name):
        try:
            # Dynamically import the module
            self.sort = importlib.import_module("sort_algos." + algo_name).sort

        except ImportError:
            print("Error: " + algo_name + " is not a valid sorting algorithm")
            exit(1)
