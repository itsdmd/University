# Write a program that asks the user for a number n and prints the sum of prime numbers 1 to n

def IsPrime(n):
    if n <= 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

def SumOfPrimes(n):
    sum = 0
    for i in range(1, n + 1):
        if IsPrime(i):
            sum += i
    return sum

def main():
    n = int(input("n: "))
    print("Sum of prime numbers from 1 to n: ", SumOfPrimes(n))