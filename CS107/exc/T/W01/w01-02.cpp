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

	std::cout << "Divisor = ";
	std::cin >> f.lo;
}

template <typename T>
void OutputFrac(Frac<T> const &f) {
	std::cout << f.hi << "/" << f.lo;
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
void FracVctInput(int const &size, std::vector<Frac<T>> &out) {
	for (int i = 0; i < size; i++) {
		std::cout << "\n[" << i << "]\n";
		
		Frac<T> f;
		FracInput(f);
		
		out.push_back(f);
	}
}

template <typename T>
void FracVctOutput(std::vector<Frac<T>> const &v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << "\n[" << i << "]: ";
		
		OutputFrac(v[i]);
	}
}

template <typename T>
void CopyVct(T const &in, T &out) {
	for (int i = 0; i < in.size(); i++) {
		out.push_back(in[i]);
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
void Sort(std::vector<Frac<T>> const &in, std::vector<Frac<T>> &out, bool (*Cmpr)(Frac<T> const &, Frac<T> const &)) {
	CopyVct(in, out);
	
	for (int i = 0; i < in.size() - 1; i++) {
		for (int j = 0; j < (in.size() - 1 - i); j++) {
			if (!Cmpr(out[j], out[j + 1])) {
				Swap(out[j], out[j + 1]);
			}
		}
	}
}



/// -------------------------------- main() -------------------------------- ///
int main() {
	std::vector<Frac<int>> f_inp, f_inc, f_dcr;
	int n_frac;
	
	std::cout << "Enter number of fractions to sort: ";
	std::cin >> n_frac;
	
	FracVctInput(n_frac, f_inp);
	
	
	std::cout << "\n\nSorted in increasing order:";
	Sort(f_inp, f_inc, FracIncr);
	FracVctOutput(f_inc);
	
	std::cout << "\n\nSorted in decreasing order:";
	Sort(f_inp, f_dcr, FracDecr);
	FracVctOutput(f_dcr);
	
	return 0;
}