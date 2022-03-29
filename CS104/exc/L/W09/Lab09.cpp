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
    int NumOfVertex;                        //Số đỉnh của đồ thị
    int Data[MAX_VERTEX][MAX_VERTEX];       //Ma trận kề của đồ thị
};

struct Edge {                               //Cấu trúc mô tả một cạnh của đồ thị
    int x;
    int y;
    int w;
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
    int n_ST = 0;
    Edge ST[MAX_EDGE];

    bool visited[MAX_VERTEX];
    
    
    for (int i = 0; i < g.NumOfVertex; i++) {
        visited[i] = false;
    }
    
    //Xét từng đỉnh của đồ thị
    for (int i = 0; i < g.NumOfVertex; i++) {
        if (n_ST >= g.NumOfVertex) break;
        
        int minW = INT_MAX;
        int minW_index = 0;
        
        //Xét từng cạnh của đồ thị
        for (int j = 0; j < g.NumOfVertex; j++) {
            if ((visited[i] == false || visited[j] == false) && g.Data[i][j] < minW && g.Data[i][j] > 0) {
                minW = g.Data[i][j];
                minW_index = j;
            }
        }
        
        if (minW != INT_MAX)               //== INT_MAX là trường hợp không tìm thấy cạnh nào nối đỉnh đang xét với đồ thị
        {
            ST[n_ST].x = i;
            ST[n_ST].y = minW_index;
            ST[n_ST].w = minW;
            n_ST++;
            
            visited[minW_index] = true;
            visited[i] = true;
        }
    }
    
    
    std::cout << "[Prim] Cay khung co trong so nho nhat:\n";
    for (int i = 0; i < n_ST; i++) {
        std::cout << ST[i].x << " " << ST[i].y << " " << ST[i].w << "\n";
    }
    
    std::cout << "Tong trong cua cay khung nho nhat: " << totalWeight(ST, n_ST) << "\n";
}


/// ------------------------------------------------------------------------ ///
///                                  Kruskal                                 ///
/// ------------------------------------------------------------------------ ///
void kruskalAlgorithm(Graph g) {
    #define VERTICES g.NumOfVertex
    
    int n_ST = 0;
    Edge ST[MAX_EDGE];
    Edge graphEdges[MAX_EDGE];
    
    int child[VERTICES];                            //Mảng chứa đỉnh con của đỉnh tại index n (eg. child[2] = 4 tức đỉnh 2 có con là đỉnh 4)
    bool visitedEdges[VERTICES][VERTICES];          //Mảng chứa trạng thái đã xét của các cạnh
    
    for (int i = 0; i < VERTICES; i++) {
        child[i] = i;
    }
    
    for (int i = 0; i < VERTICES; i++) {
        for (int j = 0; j < VERTICES; j++) {
            visitedEdges[i][j] = false;
        }
    }
    
    
    //Lưu các cạnh của đồ thị vào mảng graphEdges
    int n = 0;
    for (int i = 0; i < VERTICES; i++) {
        for (int j = 0; j < VERTICES; j++) {
            if (g.Data[i][j] != 0) {
                graphEdges[n].x = i;
                graphEdges[n].y = j;
                graphEdges[n].w = g.Data[i][j];
                
                n++;
            }
        }
    }
    
    //Sắp xếp các cạnh theo thứ tự tăng dần theo trọng số
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graphEdges[i].w > graphEdges[j].w) {
                Edge temp = graphEdges[i];
                graphEdges[i] = graphEdges[j];
                graphEdges[j] = temp;
            }
        }
    }
    
    
    int edges = totalEdges(graphEdges, VERTICES);
    for (int i = 0; i < edges*2; i++) {                             //edges*2 do mỗi cặp điểm tạo ra một cặp cạnh giống nhau
        if (n_ST >= g.NumOfVertex) break;
        
        bool valid = true;
        
        if (graphEdges[i].w == 0) {
            valid = false;
        }
        
        else if (visitedEdges[graphEdges[i].x][graphEdges[i].y] == true) {
            valid = false;
        }
        
        else if (child[graphEdges[i].x] == child[graphEdges[i].y]) {
            valid = false;
        }
        
        else if (graphEdges[i].w == INT_MAX) {
            valid = false;
        }
        
        
        if (valid) {
            ST[n_ST].x = graphEdges[i].x;
            ST[n_ST].y = graphEdges[i].y;
            ST[n_ST].w = graphEdges[i].w;
            n_ST++;
            
            child[graphEdges[i].x] = graphEdges[i].y;
            child[graphEdges[i].y] = graphEdges[i].x;
            visitedEdges[graphEdges[i].x][graphEdges[i].y] = true;
            visitedEdges[graphEdges[i].y][graphEdges[i].x] = true;
        }
    }
    
    
    std::cout << "[Kruskal] Cay khung co trong so nho nhat:\n";
    for (int i = 0; i < n_ST; i++) {
        std::cout << ST[i].x << " " << ST[i].y << " " << ST[i].w << "\n";
    }
    
    std::cout << "Tong trong cua cay khung nho nhat: " << totalWeight(ST, n_ST) << "\n";
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