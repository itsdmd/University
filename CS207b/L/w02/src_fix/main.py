import random
import os
import glob
import SortedList as sl

# Generate a list of 25 random intergers
numList = []
for i in range(25):
    numList.append(random.randint(0, 100))

sortAlgos = []
sortAlgosDir = os.getcwd() + "/sort_algos/"
for file in glob.glob(sortAlgosDir + "*.py"):
    # exclude SortStrat.py
    if file != sortAlgosDir + "SortAlgo.py":
        sortAlgos.append(file[len(sortAlgosDir) : -3])


def main():
    print("Unsorted: ", numList)
    for i in range(len(sortAlgos)):
        print(str(i + 1) + ": " + sortAlgos[i])
    print("0: Quit")

    selection = int(input("Select a sorting algorithm: "))
    if selection == 0:
        exit(0)
    else:
        sortedList = sl.SortedList(sortAlgos[selection - 1])
        print("Sorted: ", sortedList.sort(numList))


main()
