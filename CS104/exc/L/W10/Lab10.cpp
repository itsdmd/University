/*
  Họ và tên SV: Đào Minh Đức
  MSSV: 2159003
*/

#include <iostream>
#include <fstream>
#include <string>

#define MAX_VERTEX 100

struct Graph {
	int NumOfVertex;
	int Data[MAX_VERTEX][MAX_VERTEX];
};



/// ------------------------------------------------------------------------ ///
///                                    I/O                                   ///
/// ------------------------------------------------------------------------ ///
void inputGraph(std::string filename, Graph &g) {
	std::ifstream fin;
	fin.open(filename);

	if (!fin.is_open()) {
		std::cout << "ERROR: Can't open file!" << filename << "\n";
		return;
	}

	fin >> g.NumOfVertex;
	for (int i = 0; i < g.NumOfVertex; i++) {
		for (int j = 0; j < g.NumOfVertex; j++) {
			fin >> g.Data[i][j];
		}
	}

	fin.close();
}



/// ------------------------------------------------------------------------ ///
///                                 Dijkstra                                 ///
/// ------------------------------------------------------------------------ ///
void dijkstra(Graph g, int startVrtx, int endVrtx) {
	if (startVrtx >= g.NumOfVertex || startVrtx < 0) {
		std::cout << "ERROR: Invalid start vertex!" << "\n";
		return;
	}

	if (endVrtx >= g.NumOfVertex || endVrtx < 0) {
		std::cout << "ERROR: Invalid end vertex!" << "\n";
		return;
	}

	if (startVrtx == endVrtx) {
		std::cout << "Start is End. Stopped." << "\n";
		return;
	}

	bool visited[MAX_VERTEX];
	int path[MAX_VERTEX];
	int cost[MAX_VERTEX]; // For weight calculation

	// Initialize arrays
	for (int i = 0; i < g.NumOfVertex; i++) {
		visited[i] = false;
		path[i] = -1;
		cost[i] = -1;
	}

	cost[startVrtx] = 0;
	while (visited[endVrtx] == false) {
		int minValue = -1;
		int minVertex = -1;

		// Check all connected, un-visited vertices. Update min value and vertex.
		for (int i = 0; i < g.NumOfVertex; i++) {
			if ((visited[i] == false) && (cost[i] != -1) && ((cost[i] < minValue) || (minValue == -1))) {
				minValue = cost[i];
				minVertex = i;
			}
		}

		if (minValue == -1) {
			std::cout << "No path found. Stopped." << "\n";
			return;
		}

		// Assign cost of min vertex to respective vertex's index in visited array
		cost[minVertex] = minValue;
		visited[minVertex] = true;

		// Update path's weight
		for (int i = 0; i < g.NumOfVertex; i++) {
			if ((visited[i] == false) && (g.Data[minVertex][i] != 0)) {
				// 1st cond.: Check whether the cost of the path to the vertex is -1. If it is, update the cost of the path to the vertex.
				// 2nd cond.: If there is and cost less, update the value
				if ((cost[i] == -1) || (cost[i] > (cost[minVertex] + g.Data[minVertex][i]))) {
					cost[i] = cost[minVertex] + g.Data[minVertex][i];
					path[i] = minVertex;
				}
			}
		}
	}

	if (path[endVrtx] == -1)
		std::cout << "No path from " << startVrtx << " to " << endVrtx << " can be found.\n";

	else {
		int temp = endVrtx; // Look-back

		// Start from end vertex
		std::cout << endVrtx << "<=";

		while (path[temp] != startVrtx) {
			std::cout << path[temp] << "<=";
			temp = path[temp];
		}

		std::cout << startVrtx << "\n";
	}
}



/// ------------------------------------------------------------------------ ///
///                                   main                                   ///
/// ------------------------------------------------------------------------ ///
int main() {
	Graph g;
	int s, e;

	inputGraph("/home/dmd/Documents/University/CS104/exc/L/W10/graph.txt", g);
	// inputGraph("graph.txt", g);

	std::cout << "Start: ";
	std::cin >> s;
	std::cout << "End: ";
	std::cin >> e;

	dijkstra(g, s, e);

	return 0;
}