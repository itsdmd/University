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
	cout << "PID" << setw(15) << "Waiting time" << setw(20) << "Turn around time"
		 << "\n";

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

// Arrange the processes using Round Robin method
vector<int> RR(vector <Proc> &inp_p, int qt) {
	vector<Proc> temp = inp_p;
	vector<Proc> queue;
	vector<int> res;

	int time = 0;
	int qt_counter = 0;
	
	
	// Use `temp` to store all processes that haven't finished yet. A process is finished when its burst time == 0.
	// Use `queue` to store processes that are currently running and waiting.
	// Loop through each process in `temp`. Process' .w and .t will be calculated when the it's finished.
	// Two initial conditions for a process to be enqueued:
	// 			1. If it has different pid as indexing process in temp then:
	// 					- start time <= current time
	// 					- still have burst time
	// 					- total burst time in queue is less than its burst time
	//			2. Otherwise, it still have burst time after finished the quantum
	// If ONE out of two (not both) condition is met, then it will be enqueue if it's:
	// 			- not the running process
	// 			- not the same as the last process in the queue
	// 			- not already in queue
	// The rotate happens when 1 quantum is finished OR the running process' burst reaches 0.
	// At the rotation:
	// 			1. If process still have burst time left, enqueue it.
	// 			2. Else, remove it from `temp` and update turn around time in `inp_p`.
	// End when `temp` is empty.
	//! Segmentation error when qt=1
	while (!temp.empty()) {
		sort (temp.begin(), temp.end(), compareStartTime);
		
		// Init queue
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i].s <= time) {
				queue.push_back(temp[i]);
			}
		}
		sort (queue.begin(), queue.end(), compareStartTime);
		
		
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
			while (temp[i].b > 0) {
				// Index of the current process in the `temp`.
				int i_t = findMatchingPid(queue[0], temp);
				
				res.push_back(queue[0].pid);
				qt_counter++;
				time++;
				temp[i_t].b--;
				
				// Increment waiting time of waiting processes in the queue.
				for (int j = 1; j < queue.size(); j++) {
					inp_p[findMatchingPid(queue[j], inp_p)].w++;
				}
				
				// When a quantum is finished OR process's burst reaches 0
				if ((qt_counter == qt) || (temp[i_t].b == 0)) {
					// (For finishing a quantum) If process still have burst time left, enqueue it.
					if (temp[i_t].b > 0) {
						queue.push_back(queue[0]);
					}
					
					// Else remove it from `temp` and assign turn around time to the according process in `inp_p`.
					else {
						int ip_i = findMatchingPid(temp[i_t], inp_p);
						inp_p[ip_i].t = (time - inp_p[ip_i].s);
						inp_p[ip_i].w = (inp_p[ip_i].t - inp_p[ip_i].b);
						
						temp.erase(temp.begin() + i_t);
					}
					
					queue.erase(queue.begin());
					qt_counter = 0;
					
					continue;
				}
				
				// Push to `queue` + Increment waiting time of processes.
				for (int j = 0; j < temp.size(); j++) {
					bool passed = false;
					
					// (If it is not the same process and it has arrived and has positive burst time
					if ((temp[j].pid != temp[i_t].pid) && (temp[j].s <= time) && (temp[j].b > 0)) {
						int total_queued_burst = 0;					// Process' total queued burst time
						
						for (int k = 0; k < queue.size(); k++) {
							if (queue[k].pid == temp[j].pid) {
								total_queued_burst += queue[k].b;
							}
						}
						
						// and will have burst time left after finished all of its queued)
						if ((temp[j].b - total_queued_burst) > 0) {
							passed = true;
						}
					}
					// XOR (If it is the same process and still has burst time left after finished the current quantum).
					else if ((temp[j].pid == temp[i_t].pid) && (temp[j].b - (qt - qt_counter) > 0)) {
						passed = true;
					}
					
					if (passed) {
						// AND It's not the running process (since running process will be handled when [qt_counter == qt] OR [its burst == 0])
						if (temp[j].pid != queue[0].pid) {
							// AND It's not the same as the last process in `queue` (avoid duplicates).
							if (temp[j].pid != queue[queue.size() - 1].pid) {
								queue.push_back(temp[j]);
							}
						}
					}
				}
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
	// loadData(inp_file, procList);
	
	procList_cp = procList_og;
	vector<int> res_srtf = SRTF(procList_cp);
	printProcs(res_srtf);
	printWT(procList_cp);
	
	
	int qt = 0;
	cout << "\nEnter quantum: ";
	do {
		try {
			cin >> qt;
		}
		
		catch (...) {
			cout << "Invalid input" << "\n";
			continue;
		}
	} while (qt <= 0);
	
	procList_cp = procList_og;
	vector<int> res_rr = RR(procList_cp, qt);
	printProcs(res_rr);
	printWT(procList_cp);

	return 0;
}