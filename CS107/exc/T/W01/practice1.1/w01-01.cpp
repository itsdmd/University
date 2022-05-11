#include <iostream>
#include <numeric> // std::gcd


/// ------------------------------------------------------------------------ ///
///                                Definitions                               ///
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
void Swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

/// ---------------------- Fraction-related functions ---------------------- ///
/* #region   */
template <typename T>
void FracInput(Frac<T> &f) {
	std::cout << "Dividend = ";
	std::cin >> f.hi;

	do {
		std::cout << "Divisor = ";
		std::cin >> f.lo;
	} while (f.lo == 0);
}

template <typename T>
void FracOutput(Frac<T> f) {
	if (f.hi >= 0 && f.lo < 0) {
		f.hi *= -1;
	}
	
	if (f.hi == 0) {
		std::cout << "0";
	}
	
	else if (f.lo == 1) {
		std::cout << f.hi;
	}
	
	else {
		std::cout << f.hi << "/" << f.lo;
	}
}

template <typename T>
Frac<T> FracReduce(Frac<T> f) {
	T gcd = std::gcd(f.hi, f.lo);
	
	f.hi /= gcd;
	f.lo /= gcd;
	
	return f;
}

template <typename T>
Frac<T> FracInvert(Frac<T> f) {
	Swap(f.hi, f.lo);
	
	return f;
}

template <typename T>
Frac<T> FracAdd(Frac<T> f1, Frac<T> f2) {
	Frac<T> res;
	
	f1 = FracReduce(f1);
	f2 = FracReduce(f2);
	
	res.hi = f1.hi * f2.lo + f2.hi * f1.lo;
	res.lo = f1.lo * f2.lo;
	
	FracReduce(res);
	
	return res;
}

// > (1), < (-1), = (0)
template <typename T>
int FracCmpr(Frac<T> const &f1, Frac<T> const &f2) {
	double f1_d, f2_d;
	
	f1_d = (double)f1.hi / (double)f1.lo;
	f2_d = (double)f2.hi / (double)f2.lo;
	
	if (f1_d > f2_d) {
		return 1;
	}
	
	else if (f1_d < f2_d) {
		return -1;
	}
	
	else {
		return 0;
	}
}
/* #endregion */


/// -------------------------------- main() -------------------------------- ///
int main() {
	Frac<int> f1, f2;
	
	std::cout << "[1]\n";
	FracInput(f1);
	std::cout << "[2]\n";
	FracInput(f2);
	
	
	std::cout << "\n[1] = ";
	FracOutput(f1);
	std::cout << "\n\n[2] = ";
	FracOutput(f2);
	
	
	std::cout << "\n\nReduced [1] = ";
	FracOutput(FracReduce(f1));
	std::cout << "\nReduced [2] = ";
	FracOutput(FracReduce(f2));
	
	
	std::cout << "\n\nInverted [1] = ";
	FracOutput(FracInvert(f1));
	std::cout << "\nInverted [2] = ";
	FracOutput(FracInvert(f2));
	
	
	std::cout << "\n\n[1] + [2] = ";
	FracOutput(FracAdd(f1, f2));
	
	if ((FracAdd(f1, f2).hi != FracReduce(FracAdd(f1, f2)).hi) && (FracAdd(f1, f2).lo != FracReduce(FracAdd(f1, f2)).lo)) {
		std::cout << " = ";
		FracOutput(FracReduce(FracAdd(f1, f2)));
	}
	
	
	std::cout << "\n\n[1] vs [2] = " << FracCmpr(f1, f2) << "\n";
	
	
	
	return 0;
}