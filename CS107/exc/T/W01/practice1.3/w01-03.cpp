#include <iostream>
#include <vector>


/// ------------------------------------------------------------------------ ///
///                                Definitions                               ///
/// ------------------------------------------------------------------------ ///
//TODO: Put custom structs here


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


/// -------------------------- Vector related fns -------------------------- ///
/* #region   */
template <typename T>
void Input(T &in) {
	std::cout << "Value = ";
	std::cin >> in;
}

template <typename T>
void Output(T out) {
	std::cout << out;
}

//TODO: Customize comparison rules
// > (1), < (-1), = (0)
template <typename T>
int Compare(T const &n1, T const &n2) {
	if (n1 > n2) {
		return 1;
	}
	
	else if (n1 < n2) {
		return -1;
	}
	
	else {
		return 0;
	}
}

// Must pass in a placeholder argument for array's elements' type.
template <typename V, typename T>
void VctInput(int const &size, V &input, T const &val_type) {
	for (int i = 0; i < size; i++) {
		std::cout << "\n[" << i << "]\n";
		
		T val;
		Input(val);
		
		input.push_back(val);
	}
}

template <typename V>
void VctOutput(V const &output) {
	for (int i = 0; i < output.size(); i++) {
		std::cout << "\n[" << i << "]: ";
		
		Output(output[i]);
	}
}

template <typename V>
void CopyVct(V const &from, V &to) {
	to.clear();
	
	for (int i = 0; i < from.size(); i++) {
		to.push_back(from[i]);
	}
}
/* #endregion */


/// ----------------------- Comparision condition fns ---------------------- ///
/* #region   */
template <typename T>
bool Incr(T const &a, T const &b) {
	return (Compare(a, b) != 1);
}

template <typename T>
bool Decr(T const &a, T const &b) {
	return (Compare(a, b) != -1);
}

//TODO: Put custom comparison condition funtions here, each takes 2 `const &` arguments.


/* #endregion */


/// -------------------------------- Sort() -------------------------------- ///
// Condition is passed as a parameter
// Algo: Bubble
template <typename T>
void Sort(std::vector<T> const &input, std::vector<T> &sorted, bool (*Cmpr)(T const &, T const &)) {
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
	std::vector<int> inpArr, srtIncArr, srtDcrArr;
	int n;
	
	std::cout << "Enter number of element to sort: ";
	std::cin >> n;
	
	VctInput(n, inpArr, inpArr[0]);
	
	
	std::cout << "\n\nSorted in increasing order:";
	Sort(inpArr, srtIncArr, Incr);
	VctOutput(srtIncArr);
	
	std::cout << "\n\nSorted in decreasing order:";
	Sort(inpArr, srtDcrArr, Decr);
	VctOutput(srtDcrArr);
	
	return 0;
}