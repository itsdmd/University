#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::setw;
using std::string;
using std::vector;


/// ------------------------------------------------------------------------ ///
///                                  Structs                                 ///
/// ------------------------------------------------------------------------ ///
struct Proc {
	int pid = 0;
	
	int s = 0;		// Start
	int b = 0;		// Burst
	
	int w = 0;		// Waiting
	int t = 0;		// Turn around
};


/// ------------------------------------------------------------------------ ///
///                                 Functions                                ///
/// ------------------------------------------------------------------------ ///

/// ---------------------------------- I/O --------------------------------- ///
// Reads the input file and stores the processes in a vector
// First line is the number of processes
// Each line after is a process with the following format: pid, s, b
void loadData(string const &filename, vector<Proc> &inp_proc) {
	std::ifstream inp(filename);
	
	if (!inp.is_open()) {
		std::cout << "Error opening file: " << filename << std::endl;
		return;
	}
	
	int n;
	
	inp >> n;
	
	for (int i = 0; i < n; i++) {
		Proc proc;
		
		inp >> proc.pid;
		inp >> proc.s;
		inp >> proc.b;
		
		inp_proc.push_back(proc);
	}
}

// Print list of processes
void printProcs(vector<int> const &inp_i) {
	for (int i = 0; i < inp_i.size(); i++) {
		cout << i << " " << inp_i[i] << "\n";
	}
}

// Print list of processes' waiting and turn around times
void printWT(vector<Proc> const &inp_p) {
	cout << "PID" << std::setw(15) << "Waiting time" << std::setw(20) << "Turn around time" << "\n";
	
	for (auto p : inp_p) {
		cout << p.pid << setw(10) << p.w << setw(20) << p.t << "\n";
	}
}

/// ------------------------------ Calculation ----------------------------- ///
// Compare processes' arrival time
bool compareStartTime(Proc const &p1, Proc const &p2) {
	if (p1.s < p2.s) {
		return true;
	}
	
	else if (p1.s > p2.s) {
		return false;
	}
	
	return (p1.pid < p2.pid);
}

// Arrange the processes in order of arrival time
vector<int> FCFS(vector<Proc> &inp_p) {
	std::sort(inp_p.begin(), inp_p.end(), compareStartTime);
	vector<int> res;
	
	for (auto &p : inp_p) {
		int pending = (p.s - res.size());
		
		for (int i = 0; i < pending; i++) {
			res.push_back(-1);
		}
		
		p.w = res.size() - p.s;
		for (int i = 0; i < p.b; i++) {
			res.push_back(p.pid);
		}
		
		p.t = (res.size() - p.s);
	}
	
	
	return res;
}


/// -------------------------------- main() -------------------------------- ///
int main() {
	string const inp_file_full = "/home/dmd/Documents/University/CS105b/exc/L/W01/processes.txt";
	string const inp_file = "processes.txt";
	vector<Proc> procList;
	
	loadData(inp_file_full, procList);
	// loadData(inp_file, procList);
	
	vector<int> res = FCFS(procList);
	printProcs(res);
	printWT(procList);
	
	
	return 0;
}