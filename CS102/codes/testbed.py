# Write a program that print the second largest number in an integer array without using native functions

arr = [301, 302, 303, 304, 305]

def Find(arr):
    
    if len(arr) == 1:
        return arr[0]
    
    if len(arr) == 2:
        if arr[0] > arr[1]: return arr[1]
        else: return arr[0]
    
    first = arr[0]
    second = arr[1]
    
    for i in range(2, len(arr)):
        if arr[i] > first:
            second = first
            first = arr[i]
        elif arr[i] > second:
            second = arr[i]
    
    return second

def main():
    print("Second largest number: ", Find(arr))
    
main()