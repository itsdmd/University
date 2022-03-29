/*Viết chương trình C++ cài đặt thuật toán tìm cây khung nhỏ nhất
  Họ và tên SV: Đào Minh Đức
  MSSV: 2159003
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MaxVertex 100
#define MaxEdge 100
#define INT_MAX 2147483647

struct Graph {
    int NumOfVertex;                        //Số đỉnh của đồ thị
    int Data[MaxVertex][MaxVertex];         //Ma trận kề của đồ thị
};

struct Edge {   //Cấu trúc mô tả một cạnh của đồ thị
    int x;
    int y;
    int w;
};

/*Câu 1:
- Đọc dữ liệu đồ thị từ tập tin graph.txt và lưu trữ vào ma trận
- In ma trận kề ra màn hình để kiểm tra
*/
void inputGraph(string filename, Graph &g) {
    ifstream fin;
    fin.open(filename);
    if (!fin.is_open()) {
        cout << "Khong mo duoc file" << filename << endl;
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
            cout << g.Data[i][j] << " ";
        }
        cout << endl;
    }
}

void printEdges(Graph g) {
    for (int i = 0; i < g.NumOfVertex; i++) {
        for (int j = 0; j < g.NumOfVertex; j++) {
            if (g.Data[i][j] != 0) {
                cout << "(" << i << "," << j << "," << g.Data[i][j] << ") ";
            }
        }
        
        cout << "| ";
    }
    cout << endl;
}

/*Câu 2:
- Viết thuật toán Prim tìm cây khung có trọng số nhỏ nhất
*/
void primAlgorithm(Graph g){
    int nSpanningTree = 0;                  //Số cạnh cây khung ban đầu bằng 0
    Edge spanningTree[MaxEdge];             //Danh sách cạnh của cây khung

    bool visited[MaxEdge];                  //Mảng đánh dấu đỉnh đã xét
    
    for (int i = 0; i < g.NumOfVertex; i++) {
        visited[i] = false;
    }
    
    visited[0] = true;
    
    nSpanningTree = 1;
    
    //Xét từng đỉnh của đồ thị
    for (int i = 0; i < g.NumOfVertex; i++) {
        
        int minWeight = INT_MAX;                //Trọng số nhỏ nhất của cây khung ban đầu
        int minWeightIndex = 0;                 //Chỉ số đỉnh có trọng số nhỏ nhất
        
        //Xét từng cạnh của đồ thị
        for (int j = 0; j < g.NumOfVertex; j++) {
            if ((visited[i] == false || visited[j] == false) && g.Data[i][j] < minWeight && 0 < g.Data[i][j]) {
                minWeight = g.Data[i][j];
                minWeightIndex = j;
            }
        }
        
        if (minWeight != INT_MAX)               // == INT_INT là trường hợp không tìm thấy cạnh nào nối đỉnh đang xét với đồ thị
        {
            //Thêm cạnh (i, minWeightIndex) vào cây khung
            spanningTree[nSpanningTree].x = i;
            spanningTree[nSpanningTree].y = minWeightIndex;
            spanningTree[nSpanningTree].w = minWeight;
            nSpanningTree++;
            
            //Đánh dấu cạnh nối đỉnh đang xét với minWeightIndex đã xét
            visited[minWeightIndex] = true;
            visited[i] = true;
        }
    }
    
    //In cây khung ra màn hình
    cout << "[Prim] Cay khung co trong so nho nhat la:\n";
    for (int i = 1; i < nSpanningTree; i++) {
        cout << spanningTree[i].x << " " << spanningTree[i].y << " " << spanningTree[i].w << endl;
    }
    
    // Tính tổng trọng số của cây khung
    int totalWeight = 0;
    for (int i = 0; i < nSpanningTree; i++) {
        totalWeight += spanningTree[i].w;
    }
    cout << "Sum w = " << totalWeight << "\n";
}

/*Câu 3:
- Viết thuật toán Kruskal tìm cây khung có trọng số nhỏ nhất
*/
void sortEdges(Graph g, Edge e[MaxEdge]) {
    for (int i_e = 0; i_e < MaxEdge; i_e++) {
        for (int i = 0; i < g.NumOfVertex; i++) {
            for (int j = 0; j < g.NumOfVertex; j++) {
                if (g.Data[i][j] < e[i_e].w) {
                    e[i_e].x = i;
                    e[i_e].y = j;
                    e[i_e].w = g.Data[i][j];
                }
            }
        }
    }
}

// void kruskalAlgorithm(Graph g) {
//     int nSpanningTree = 0;          //Số cạnh cây khung ban đầu bằng 0
//     Edge spanningTree[MaxEdge];     //Danh sách cạnh của cây khung

//     bool visited[MaxVertex];        //Mảng đánh dấu đỉnh đã xét

//     Edge graphEdges[MaxEdge];       //Mảng chứa danh sách cạnh của đồ thị

//     /*TODO: bổ sung lần lượt cạnh trong danh sách trên vào cây khung sao cho không phát sinh chu trình.
//     Lặp lại khi số cạnh cây khung vẫn còn nhỏ hơn N - 1.
//     Lưu danh sách cạnh của cây khung trong mảng spanningTree*/
    
//     /*
//     + Bước 1: Sắp xếp các cạnh của đồ thị theo thứ tự trọng số tăng dần
//     + Bước 2: Bổ sung lần lượt các cạnh đã được sắp xếp ở bước 1 vào cây khung sao
//     cho không phát sinh chu trình.
//     + Bước 3: Nếu số cạnh của cây khung < N – 1, lặp lại bước 2. Ngược lại, dừng thuật
//     toán.
//     */
    
//     //Sắp xếp các cạnh của đồ thị theo thứ tự trọng số tăng dần
//     sortEdges(g, graphEdges);
    
//     //Tạo cây khung ban đầu
//     spanningTree[0].x = 0;
//     spanningTree[0].y = 1;
//     spanningTree[0].w = g.Data[0][1];
    
//     // Bổ sung lần lượt các cạnh đã được sắp xếp ở bước 1 vào cây khung sao cho không phát sinh chu trình. Nếu số cạnh của cây khung < N – 1, lặp lại. Ngược lại, dừng thuật toán.
//     while (nSpanningTree < g.NumOfVertex - 1) {
//         //Bổ sung cạnh vào cây khung
//         spanningTree[nSpanningTree].x = spanningTree[nSpanningTree - 1].y;
//         spanningTree[nSpanningTree].y = graphEdges[nSpanningTree].y;
//         spanningTree[nSpanningTree].w = graphEdges[nSpanningTree].w;
        
//         //Gán visited[graphEdges[nSpanningTree].y] = true
//         visited[graphEdges[nSpanningTree].y] = true;
        
//         //Nếu số cạnh của cây khung < N – 1, lặp lại bước 2. Ngược lại, dừng thuật toán.
//         if (nSpanningTree < g.NumOfVertex - 1) {
//             for (int i = 0; i < g.NumOfVertex; i++) {
//                 if (visited[i] == false) {
//                     spanningTree[nSpanningTree + 1].x = spanningTree[nSpanningTree].y;
//                     spanningTree[nSpanningTree + 1].y = i;
//                     spanningTree[nSpanningTree + 1].w = g.Data[spanningTree[nSpanningTree].y][i];
//                     nSpanningTree++;
//                 }
//             }
//         }
//     }
    
    

//     //In cây khung ra màn hình
//     cout << "[Krukal] Cay khung co trong so nho nhat la:\n";
//     for (int i = 0; i < nSpanningTree; i++) {
//         cout << spanningTree[i].x << " " << spanningTree[i].y << " " << spanningTree[i].w << endl;
//     }
// }

int main() {
    Graph g;
    
    inputGraph("/home/dmd/Documents/University/CS104/exc/L/W09/graph.txt", g);
    // inputGraph("./graph.txt", g);
    
    cout << "OG:\n";
    printGraph(g);
    cout << "-----\n";
    printEdges(g);
    cout << "\n";
    
    primAlgorithm(g);
    cout << "\n";
    // kruskalAlgorithm(g);

    return 0;
}