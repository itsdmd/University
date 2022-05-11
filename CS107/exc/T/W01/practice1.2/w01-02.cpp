#include <iostream>
#include <numeric> // std::gcd
#include <vector>


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

template <typename T>
void FracVctInput(int const &size, std::vector<Frac<T>> &input) {
	for (int i = 0; i < size; i++) {
		std::cout << "\n[" << i << "]\n";
		
		Frac<T> f;
		FracInput(f);
		
		input.push_back(f);
	}
}

template <typename T>
void FracVctOutput(std::vector<Frac<T>> const &output) {
	for (int i = 0; i < output.size(); i++) {
		std::cout << "\n[" << i << "]: ";
		
		FracOutput(output[i]);
	}
}

template <typename T>
void CopyVct(T const &from, T &to) {
	to.clear();
	
	for (int i = 0; i < from.size(); i++) {
		to.push_back(from[i]);
	}
}
/* #endregion */


/// -------------------- Comparision condition funtions -------------------- ///
/* #region   */
template <typename T>
bool FracIncr(Frac<T> const &a, Frac<T> const &b) {
	if (FracCmpr(a, b) == 1) {
		return false;
	}
	
	return true;
}

template <typename T>
bool FracDecr(Frac<T> const &a, Frac<T> const &b) {
	if (FracCmpr(a, b) == -1) {
		return false;
	}
	
	return true;
}
/* #endregion */


/// -------------------------------- Sort() -------------------------------- ///
// Condition is passed as a parameter
// Algo: Bubble
template <typename T>
void Sort(std::vector<Frac<T>> const &input, std::vector<Frac<T>> &sorted, bool (*Cmpr)(Frac<T> const &, Frac<T> const &)) {
	CopyVct(input, sorted);
	
	for (int i = 0; i < (input.size() - 1); i++) {
		for (int j = 0; j < (input.size() - 1 - i); j++) {
			if (!Cmpr(sorted[j], sorted[j + 1])) {
				Swap(sorted[j], sorted[j + 1]);
			}
		}
	}
}



/// -------------------------------- main() -------------------------------- ///
int main() {
	std::vector<Frac<int>> inp, inc, dcr;
	int n;
	
	std::cout << "Enter number of fraction to sort: ";
	std::cin >> n;
	
	FracVctInput(n, inp);
	
	
	std::cout << "\n\nSorted in increasing order:";
	Sort(inp, inc, FracIncr);
	FracVctOutput(inc);
	
	std::cout << "\n\nSorted in decreasing order:";
	Sort(inp, dcr, FracDecr);
	FracVctOutput(dcr);
	
	return 0;
}