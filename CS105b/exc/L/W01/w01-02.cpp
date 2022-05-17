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

// Arrange the processes in order of arrival time
vector<int> FCFS(vector<Proc> &inp_p) {
	vector<int> res;
	
	std::sort(inp_p.begin(), inp_p.end(), compareStartTime);
	
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

// Arrange the processes in order of burst time
vector<int> SJF(vector<Proc> &inp_p) {
	vector<int> res;
	vector<Proc> queue;
	
	std::sort(inp_p.begin(), inp_p.end(), compareStartTime);
	
	int p_index = 0;	// Index of current process in inp_p
	int time = 0;		// Current time
	for (auto &p : inp_p) {
		int pending = (p.s - res.size());
		
		for (int i = 0; i < pending; i++) {
			res.push_back(-1);
			time++;
		}
		
		p.w = res.size() - p.s;
		for (int i = 0; i < p.b; i++) {
			res.push_back(p.pid);
			time++;
			
			// Loop through the queue to find if any processes have arrived
			for (int j = 0; j < (inp_p.size() - p_index); j++) {
				if ((time) == inp_p[p_index + j + 1].s) {
					queue.push_back(inp_p[p_index + j + 1]);
				}
			}
			
			if (queue.size() > 0) {
				// Sort the queue by burst time
				std::sort(queue.begin(), queue.end(), compareBurstTime);
			
				// Add the remaining processes to the queue
				for (int j = 0; j < (inp_p.size() - queue.size()); j++) {
					queue.push_back(inp_p[j + queue.size()]);
				}
				
				// Copy the queue to the input vector when the current process is done
				if (i == (p.b - 1)) {
					for (int j = 0; j < queue.size(); j++) {
						inp_p[p_index + j + 1] = queue[j];
					}
					
					queue.erase(queue.begin());
				}
			}
		}
		
		p.t = (res.size() - p.s);
		
		p_index++;
	}
	
	
	return res;
}


/// -------------------------------- main() -------------------------------- ///
int main() {
	string const inp_file_full = "/home/dmd/Documents/University/CS105b/exc/L/W01/processes.txt";
	string const inp_file = "processes.txt";
	vector<Proc> procList_og;
	vector<Proc> procList_cp;
	
	loadData(inp_file_full, procList_og);
	// loadData(inp_file, procList);
	
	procList_cp = procList_og;
	vector<int> res_fcfs = FCFS(procList_cp);
	printProcs(res_fcfs);
	printWT(procList_cp);
	
	procList_cp = procList_og;
	vector<int> res_sjf = SJF(procList_cp);
	printProcs(res_sjf);
	printWT(procList_cp);
	
	return 0;
}