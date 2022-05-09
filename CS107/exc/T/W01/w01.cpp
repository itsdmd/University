#include <iostream>
#include <numeric> // std::gcd



/// ------------------------------------------------------------------------ ///
///                                  Structs                                 ///
/// ------------------------------------------------------------------------ ///
template <typename T>
struct Frac {
	T hi, lo; // hi = dividend, lo = divisor
};



/// ------------------------------------------------------------------------ ///
///                                 Functions                                ///
/// ------------------------------------------------------------------------ ///

/// -------------------------------- Swap() -------------------------------- ///
template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

/// ---------------------- Fraction-related functions ---------------------- ///
/* #region   */
template <typename T>
void InputFrac(Frac<T> &f) {
	std::cout << "Input fraction's dividend: ";
	std::cin >> f.hi;

	std::cout << "Input fraction's divisor: ";
	std::cin >> f.lo;
}

template <typename T>
void OutputFrac(Frac<T> &f) {
	std::cout << f.hi << "/" << f.lo;
}

template <typename T>
void FracReduce(Frac<T> &f) {
	T gcd = std::gcd(f.hi, f.lo);
	
	f.hi /= gcd;
	f.lo /= gcd;
}

template <typename T>
Frac<T> FracInvert(Frac<T> f) {
	swap(f.hi, f.lo);
	
	return f;
}

template <typename T>
Frac<T> FracAdd(Frac<T> &f1, Frac<T> &f2) {
	Frac<T> f3;
	
	FracReduce(f1);
	FracReduce(f2);
	
	f3.hi = f1.hi * f2.lo + f2.hi * f1.lo;
	f3.lo = f1.lo * f2.lo;
	
	FracReduce(f3);
	
	return f3;
}

// > (1), < (-1), = (0)
template <typename T>
int FracCmpr(Frac<T> &f1, Frac<T> &f2) {
	if ((f1.hi / f1.lo) > (f2.hi / f2.lo)) {
		return 1;
	}
	
	else if ((f1.hi / f1.lo) < (f2.hi / f2.lo)) {
		return -1;
	}
	
	else {
		return 0;
	}
}
/* #endregion */

/// -------------------------------- Sort() -------------------------------- ///
// Condition is passed as a function parameter
// Algo: Bubble
template <typename T>
void Sort(T *arr, int size, bool (*Cmpr)(T, T)) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (!Cmpr(arr[j], arr[j + 1])) {
				swap(arr[j], arr[j + 1])
			}
		}
	}
}

/// -------------------- Comparision condition funtions -------------------- ///
/* #region   */
template <typename T>
bool Decr(T a, T b) {
	return (a > b);
}

template <typename T>
bool Incr(T a, T b) {
	return (a < b);
}

template <typename T>
bool FracIncr(Frac<T> a, Frac<T> b) {
	if (FracCmpr(a, b) == 1) {
		return false;
	}
	
	return true;
}

template <typename T>
bool FracDecr(Frac<T> a, Frac<T> b) {
	if (FracCmpr(a, b) == -1) {
		return false;
	}
	
	return true;
}
/* #endregion */



/// -------------------------------- main() -------------------------------- ///
int main()
{
	//
	
	return 0;
}