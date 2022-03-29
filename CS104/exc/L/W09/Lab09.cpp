/*Viết chương trình C++ cài đặt thuật toán tìm cây khung nhỏ nhất
  Họ và tên SV: Đào Minh Đức
  MSSV: 2159003
*/
#include <iostream>
#include <fstream>
#include <string>

#define MaxVertex 100
#define MaxEdge 100
#define INT_MAX 2147483647


/// ------------------------------------------------------------------------ ///
///                                  structs                                 ///
/// ------------------------------------------------------------------------ ///
struct Graph {
    int NumOfVertex;                        //Số đỉnh của đồ thị
    int Data[MaxVertex][MaxVertex];         //Ma trận kề của đồ thị
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

int totalWeight(Edge e[], int n) {
    int totalWeight = 0;
    
    for (int i = 0; i < n; i++) {
        totalWeight += e[i].w;
    }
    
    return totalWeight;
}


/// ------------------------------------------------------------------------ ///
///                                   Prim                                   ///
/// ------------------------------------------------------------------------ ///
void primAlgorithm(Graph g){
    int nSpanningTree = 0;
    Edge spanningTree[MaxEdge];

    bool visited[MaxEdge];
    
    
    for (int i = 0; i < g.NumOfVertex; i++) {
        visited[i] = false;
    }
    
    //Xét từng đỉnh của đồ thị
    for (int i = 0; i < g.NumOfVertex; i++) {
        int minWeight = INT_MAX;
        int minWeightIndex = 0;
        
        //Xét từng cạnh của đồ thị
        for (int j = 0; j < g.NumOfVertex; j++) {
            if ((visited[i] == false || visited[j] == false) && g.Data[i][j] < minWeight && g.Data[i][j] > 0) {
                minWeight = g.Data[i][j];
                minWeightIndex = j;
            }
        }
        
        if (minWeight != INT_MAX)               // == INT_MAX là trường hợp không tìm thấy cạnh nào nối đỉnh đang xét với đồ thị
        {
            spanningTree[nSpanningTree].x = i;
            spanningTree[nSpanningTree].y = minWeightIndex;
            spanningTree[nSpanningTree].w = minWeight;
            nSpanningTree++;
            
            visited[minWeightIndex] = true;
            visited[i] = true;
        }
    }
    
    
    std::cout << "[Prim] Cay khung co trong so nho nhat:\n";
    for (int i = 0; i < nSpanningTree; i++) {
        std::cout << spanningTree[i].x << " " << spanningTree[i].y << " " << spanningTree[i].w << "\n";
    }
    
    std::cout << "Tong trong cua cay khung nho nhat: " << totalWeight(spanningTree, nSpanningTree) << "\n";
}


/// ------------------------------------------------------------------------ ///
///                                  Kruskal                                 ///
/// ------------------------------------------------------------------------ ///
void kruskalAlgorithm(Graph g) {
    int nSpanningTree = 0;
    Edge spanningTree[MaxEdge];
    Edge graphEdges[MaxEdge];
    
    
    for (int i = 0; i < g.NumOfVertex; i++) {
        for (int j = i + 1; j < g.NumOfVertex; j++) {
            if (g.Data[i][j] < g.Data[j][i] && g.Data[i][j] != 0) {
                int temp = g.Data[i][j];
                g.Data[i][j] = g.Data[j][i];
                g.Data[j][i] = temp;
            }
        }
    }
    
    for (int i = 0; i < MaxEdge; i++) {
        if (nSpanningTree < g.NumOfVertex - 1) {
            spanningTree[nSpanningTree] = graphEdges[i];
            nSpanningTree++;
        }
        else {
            break;
        }
    }

    //In cây khung ra màn hình
    std::cout << "[Kruskal] Cay khung co trong so nho nhat:\n";
    for (int i = 0; i < nSpanningTree; i++) {
        std::cout << spanningTree[i].x << " " << spanningTree[i].y << " " << spanningTree[i].w << "\n";
    }
    
    std::cout << "Tong trong cua cay khung nho nhat: " << totalWeight(spanningTree, nSpanningTree) << "\n";
}

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