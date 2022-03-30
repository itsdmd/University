/*Viết chương trình C++ cài đặt thuật toán tìm cây khung nhỏ nhất
  Họ và tên SV: Đào Minh Đức
  MSSV: 2159003
*/
#include <iostream>
#include <fstream>
#include <string>

#define MAX_VERTEX 100
#define MAX_EDGE 100
#define INT_MAX 2147483647


/// ------------------------------------------------------------------------ ///
///                                  structs                                 ///
/// ------------------------------------------------------------------------ ///
struct Graph {
    int NumOfVertex;
    int Data[MAX_VERTEX][MAX_VERTEX];
};

struct Edge {
    int x, y, w;
};


/// ------------------------------------------------------------------------ ///
///                                    I/O                                   ///
/// ------------------------------------------------------------------------ ///
void inputGraph(std::string filename, Graph &g) {
    std::ifstream fin;
    fin.open(filename);
    
    if (!fin.is_open()) {
        std::cout << "Khong mo duoc file" << filename << "\n";
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

void printGraph(Graph g) {
    for (int i = 0; i < g.NumOfVertex; i++) {
        for (int j = 0; j < g.NumOfVertex; j++) {
            std::cout << g.Data[i][j] << " ";
        }
        
        std::cout << "\n";
    }
}

void printEdges(Graph g) {
    for (int i = 0; i < g.NumOfVertex; i++) {
        for (int j = 0; j < g.NumOfVertex; j++) {
            if (g.Data[i][j] != 0) {
                std::cout << "(" << i << "," << j << "," << g.Data[i][j] << ") ";
            }
        }
        
        std::cout << "| ";
    }
    
    std::cout << "\n";
}

/// ------------------------------------------------------------------------ ///
///                            Graph Calculations                            ///
/// ------------------------------------------------------------------------ ///
int totalWeight(Edge e[], int n) {
    int totalWeight = 0;
    
    for (int i = 0; i < n; i++) {
        totalWeight += e[i].w;
    }
    
    return totalWeight;
}

int totalEdges(Edge e[], int n) {
    #define N n
    
    int edges = 0;
    bool counted[N][N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            counted[i][j] = false;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (e[i].w != 0 && !counted[i][j] && e[i].x == e[j].x && e[i].y == e[j].y) {
                edges++;
                counted[i][j] = true;
                counted[j][i] = true;
            }
        }
    }
    
    return edges;
}


/// ------------------------------------------------------------------------ ///
///                                   Prim                                   ///
/// ------------------------------------------------------------------------ ///
void primAlgorithm(Graph g){
    #define VERTICES g.NumOfVertex
    
    int n_ST = 0;
    Edge ST[MAX_EDGE];
    
    bool visited[VERTICES];
    
    for (int i = 0; i < VERTICES; i++) {
        visited[i] = false;
    }
    
    visited[0] = true;
    
    
    while (n_ST < VERTICES - 1) {
        int min = INT_MAX;
        int vtx_i = 0;                  //Visited
        int vtx_j = 0;                  //Un-visited
        
        //Check all visited vertices that connect to un-visited vertices
        for (int i = 0; i < VERTICES; i++) {
            if (visited[i]) {
                for (int j = 0; j < VERTICES; j++) {
                    if (visited[j] == false && g.Data[i][j] < min && g.Data[i][j] > 0) {
                        min = g.Data[i][j];
                        vtx_i = i;
                        vtx_j = j;
                    }
                }
            }
        }
        
        ST[n_ST].x = vtx_i;
        ST[n_ST].y = vtx_j;
        ST[n_ST].w = min;
        
        n_ST++;
        visited[vtx_j] = true;
    }
    
    
    std::cout << "[Prim] Minimum spanning tree:\n";
    for (int i = 0; i < n_ST; i++) {
        std::cout << ST[i].x + 1 << " " << ST[i].y + 1 << " " << ST[i].w << "\n";
    }
    
    std::cout << "MST weight: " << totalWeight(ST, n_ST) << "\n";
}


/// ------------------------------------------------------------------------ ///
///                                  Kruskal                                 ///
/// ------------------------------------------------------------------------ ///
void kruskalAlgorithm(Graph g) {
    #define VERTICES g.NumOfVertex
    
    int n_ST = 0;
    Edge ST[MAX_EDGE];
    Edge graphEdges[MAX_EDGE];
    
    bool visited[VERTICES][VERTICES];               //Mảng chứa trạng thái đã xét của các cạnh
    
    for (int i = 0; i < VERTICES; i++) {
        for (int j = 0; j < VERTICES; j++) {
            visited[i][j] = 0;
        }
    }
    
    //Add all edges to graphEdges
    int n = 0;
    for (int i = 0; i < g.NumOfVertex; i++) {
        for (int j = 0; j < g.NumOfVertex; j++) {
            if (g.Data[i][j] > 0) {
                graphEdges[n].x = i;
                graphEdges[n].y = j;
                graphEdges[n].w = g.Data[i][j];
                n++;
            }
        }
    }
    
    //Sort edges by weight, increment
    for (int i = 0; i < (n - 1); i++) {
        for (int j = i + 1; j < n; j++) {
            if (graphEdges[i].w > graphEdges[j].w) {
                Edge temp = graphEdges[i];
                graphEdges[i] = graphEdges[j];
                graphEdges[j] = temp;
            }
        }
    }
    
    
    int edges = totalEdges(graphEdges, VERTICES);
    for (int i = 0; i < edges*2; i++) {                             //edges*2 since each edge is added twice, (i,j) and (j,i)
        if (n_ST >= g.NumOfVertex - 1) break;
        
        bool valid = true;
        
        if (graphEdges[i].w == 0) {
            valid = false;
        }
        
        else if (visited[graphEdges[i].x][graphEdges[i].y] == true) {
            valid = false;
        }
        
        else if (graphEdges[i].w == INT_MAX) {
            valid = false;
        }
        
        else {
            //Check if graph create cycle (2 about-to-be-connected vertices connect to the same third vertice)
            for (int j = 0; j < VERTICES; j++) {
                if (visited[graphEdges[i].x][j] == visited[graphEdges[i].y][j] && visited[graphEdges[i].x][j] != 0) {
                    valid = false;
                    break;
                }
            }
        }
        
        
        if (valid) {
            ST[n_ST].x = graphEdges[i].x;
            ST[n_ST].y = graphEdges[i].y;
            ST[n_ST].w = graphEdges[i].w;
            n_ST++;
            
            visited[graphEdges[i].x][graphEdges[i].y] = true;
            visited[graphEdges[i].y][graphEdges[i].x] = true;
        }
    }
    
    
    std::cout << "[Kruskal] Minimum spanning tree:\n";
    for (int i = 0; i < n_ST; i++) {
        std::cout << ST[i].x + 1 << " " << ST[i].y + 1 << " " << ST[i].w << "\n";
    }
    
    std::cout << "MST weight: " << totalWeight(ST, n_ST) << "\n";
}



/// ------------------------------------------------------------------------ ///
///                                   main                                   ///
/// ------------------------------------------------------------------------ ///
int main() {
    Graph g;
    
    inputGraph("/home/dmd/Documents/University/CS104/exc/L/W09/graph.txt", g);
    // inputGraph("graph.txt", g);
    
    std::cout << "Input:\n";
    printGraph(g);
    std::cout << "-----\nEdges:\n";
    printEdges(g);
    std::cout << "\n";
    
    primAlgorithm(g);
    std::cout << "\n";
    kruskalAlgorithm(g);

    return 0;
}