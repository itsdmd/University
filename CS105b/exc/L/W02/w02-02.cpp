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

// void RR_rotate(vector<Proc> &inp) {
// 	if (inp.size() == 0) return;
	
// 	Proc first;
	
// 	first = inp[0];
	
// 	for (int i = 0; i < (inp.size() - 1); i++) {
// 		inp[i] = inp[i + 1];
// 	}
	
// 	inp[inp.size() - 1] = first;
// }
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
			
			// Increment waiting time of processes
			for (int j = 0; j < temp.size(); j++) {
				// Find arrived processes except current one in temp
				//? Use temp since it had been sorted & finished processes had been deleted
				if ((inp_p[j].s < time) && (temp[j].pid != temp[i].pid)) {
					// Find matching process in inp_p
					for (int k = 0; k < inp_p.size(); k++) {
						if (inp_p[k].pid == temp[j].pid) {
							inp_p[k].w++;
						}
					}
				}
			}

			if (temp[i].b == 0) {
				for (int j = 0; j < inp_p.size(); j++) {
					if (inp_p[j].pid == temp[i].pid) {
						inp_p[j].t = time - inp_p[j].s;
					}
				}

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
	
	
	// Use temp to store all processes that haven't finished yet. A process is finished when its burst time is 0 and will be removed from temp.
	// Use queue to store processes that are currently waiting.
	// A process is enqueue if its burst isn't 0 when the rotate happens or when its start time <= current time.
	// The rotate happens when qt_counter == qt.
	// Every time qt_counter == qt, reset qt_counter to 0 and dequeue the first process in queue.
	// Start reducing the dequeued process' burst time qt times. Each time check if any processes join the queue by comparing their start time with the current time.
	// End when temp vector is empty.
	while (!temp.empty()) {
		sort (temp.begin(), temp.end(), compareStartTime);
		
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
				// Find matching process in temp
				int i_t = 0;		// Index of the current process in the temp vector.
				for (; i_t < temp.size(); i_t++) {
					if (queue[0].pid == temp[i_t].pid) {
						break;
					}
				}
				
				res.push_back(queue[0].pid);
				qt_counter++;
				time++;
				temp[i_t].b--;
				
				// Increment waiting time of waiting processes in the queue
				for (int j = 0; j < inp_p.size(); j++) {
					for (int k = 1; k < queue.size(); k++) {
						if (inp_p[j].pid == queue[k].pid) {
							inp_p[j].w++;
							break;
						}
					}
				}
				
				if (qt_counter == qt) {
					if (temp[i_t].b > 0) {
						queue.push_back(queue[0]);
					}
					
					else {
						for (int j = 0; j < inp_p.size(); j++) {
							if (inp_p[j].pid == temp[i_t].pid) {
								inp_p[j].t = time - inp_p[j].s;
							}
						}
						temp.erase(temp.begin() + i_t);
					}
					
					queue.erase(queue.begin());
					qt_counter = 0;
					
					continue;
				}
				
				// Push to queue + Increment waiting time of processes
				for (int j = 0; j < temp.size(); j++) {
					bool passed = false;
					
					if ((temp[j].pid != temp[i_t].pid) && (temp[j].s <= time) && (temp[j].b > 0)) { 				// (If it is not the same process and it has arrived and it will have burst time left after finished all of its queued)
						int total_queued_burst = 0;
						
						for (int k = 0; k < queue.size(); k++) {
							if (queue[k].pid == temp[j].pid) {
								total_queued_burst += queue[k].b;
							}
						}
						
						if ((qt - total_queued_burst) > 0) {
							passed = true;
						}
					} else if ((temp[j].pid == temp[i_t].pid) && (temp[j].b - (qt - qt_counter) > 0)) {				// XOR (If it is the same process and still has burst time left)
						passed = true;
					}
					
					if (passed) {
						if (temp[j].pid != queue[0].pid) {															// AND It's not the running process
							if (temp[j].pid != queue[queue.size() - 1].pid) {										// AND It's not the same as the last process in the queue
								queue.push_back(temp[j]);
								
								if (queue.size() > 1) {
									bool found = false;
									
									for (int m = 0; m < inp_p.size(); m++) {
										if (inp_p[m].pid == temp[j].pid) {
											inp_p[m].w++;
											
											found = true;
											break;
										}
										
										if (found) break;
									}
								}
							}
						}
					}
				}
				
				// Finished
				if (temp[i_t].b == 0) {
					for (int j = 0; j < inp_p.size(); j++) {
						if (inp_p[j].pid == temp[i_t].pid) {
							inp_p[j].t = time - inp_p[j].s;
						}
					}
					
					temp.erase(temp.begin() + i);
					
					queue.erase(queue.begin());
					qt_counter = 0;
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