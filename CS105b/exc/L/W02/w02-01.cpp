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
	
	int s = 0; // Start
	int b = 0; // Burst
	
	int w = 0; // Waiting
	int t = 0; // Turn around
};

/// ------------------------------------------------------------------------ ///
///                                 Functions                                ///
/// ------------------------------------------------------------------------ ///

/// ---------------------------------- I/O --------------------------------- ///
/* #region   */
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
	
	inp.close();
}

// Print list of processes
void printProcs(vector<int> const &inp_i) {
	for (int i = 0; i < inp_i.size(); i++) {
		cout << i << " " << inp_i[i] << "\n";
	}
}

// Print list of processes' waiting and turn around times
void printWT(vector<Proc> const &inp_p) {
	cout << "PID" << setw(15) << "Waiting time" << setw(20) << "Turn around time" << "\n";
	
	for (auto p : inp_p) {
		cout << p.pid << setw(10) << p.w << setw(20) << p.t << "\n";
	}
}
/* #endregion */

/// ------------------------------ Calculation ----------------------------- ///
/* #region   */
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

// Compare processes' burst time
bool compareBurstTime(Proc const &p1, Proc const &p2) {
	if (p1.b < p2.b) {
		return true;
	}
	
	else if (p1.b > p2.b) {
		return false;
	}
	
	return (p1.pid < p2.pid);
}

int findMatchingPid(Proc const &proc, vector<Proc> const &vt) {
	for (int i = 0; i < vt.size(); i++) {
		if (vt[i].pid == proc.pid) {
			return i;
		}
	}
	
	return -1;
}
/* #endregion */

// Arrange the processes in order of remaining burst time
vector<int> SRTF(vector<Proc> &inp_p) {
	vector<Proc> temp = inp_p;
	vector<int> res;
	
	int time = 0;
	
	while (!temp.empty()) {
		sort(temp.begin(), temp.end(), compareBurstTime);
		
		int i = 0;
		
		for (; i < temp.size(); i++) {
			if (temp[i].s <= res.size()) {
				break;
			}
		}
		
		if (i == temp.size()) {
			res.push_back(-1);
			time++;
		} else {
			res.push_back(temp[i].pid);
			temp[i].b--;
			time++;
			
			if (temp[i].b == 0) {
				int ip_i = findMatchingPid(temp[i], inp_p);
				inp_p[ip_i].t = (time - inp_p[ip_i].s);
				inp_p[ip_i].w = (inp_p[ip_i].t - inp_p[ip_i].b);
				
				temp.erase(temp.begin() + i);
			}
		}
	}
	
	return res;
}

/// -------------------------------- main() -------------------------------- ///
int main() {
	string const inp_file_full = "/home/dmd/Documents/University/CS105b/exc/L/W02/processes.txt";
	string const inp_file = "processes.txt";
	vector<Proc> procList_og;
	vector<Proc> procList_cp;
	
	loadData(inp_file_full, procList_og);
	// loadData(inp_file, procList_og);
	
	procList_cp = procList_og;
	vector<int> res_srtf = SRTF(procList_cp);
	printProcs(res_srtf);
	printWT(procList_cp);
	
	
	return 0;
}