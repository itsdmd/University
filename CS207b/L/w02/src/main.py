import random
import SortedList

sl = SortedList.SortedList

# Generate 25 random numbers
numList = []
for i in range(25):
    numList.append(random.randint(0, 100))

sortedList = sl(numList)

# print("\n\nBubble Sort:")
# sortedList.bubbleSort()
# sortedList.print()
#
# print("\n\nSelection Sort:")
# sortedList.selectionSort()
# sortedList.print()
#
# print("\n\nCounting Sort:")
# sortedList.countingSort()
# sortedList.print()
#
# print("\n\nRadix Sort:")
# sortedList.radixSort()
# sortedList.print()
#
# print("\n\nInterchange Sort:")
# sortedList.interchangesort()
# sortedList.print()


def main():
    print("""
    1. Bubble Sort
    2. Selection Sort
    3. Counting Sort
    4. Radix Sort
    5. Interchange Sort
    """)
    print("Enter the number of the sort you would like to use: ")
    mode = int(input())

    if mode == 1:
        print("Bubble Sort:")
        sortedList.bubbleSort()
        sortedList.print()
    elif mode == 2:
        print("Selection Sort:")
        sortedList.selectionSort()
        sortedList.print()
    elif mode == 3:
        print("Counting Sort:")
        sortedList.countingSort()
        sortedList.print()
    elif mode == 4:
        print("Radix Sort:")
        sortedList.radixSort()
        sortedList.print()
    elif mode == 5:
        print("Interchange Sort:")
        sortedList.interchangesort()
        sortedList.print()
    else:
        print("Invalid input.")


if __name__ == "__main__":
    main()
