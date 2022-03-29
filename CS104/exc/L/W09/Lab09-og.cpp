/*Viết chương trình C++ cài đặt thuật toán tìm cây khung nhỏ nhất
  Họ và tên SV:
  MSSV:  
*/
#include <iostream>
#include <string>

using namespace std;

#define MaxVertex 100
#define MaxEdge 100

struct Graph {
    int NumOfVertex;    //Số đỉnh của đồ thị
    int Data[MaxVertex][MaxVertex]; //Ma trận kề của đồ thị
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
    //TODO: Code here
}

void printGraph(Graph &g) {
    //TODO: Code here
}

/*Câu 2:
- Viết thuật toán Prim tìm cây khung có trọng số nhỏ nhất
*/
void primAlgorithm(Graph g){
    int nSpanningTree = 0; //Số cạnh cây khung ban đầu bằng 0
    EDGE spanningTree[MaxEdge]; //Danh sách cạnh của cây khung

    bool visited[MaxVertex];    //Mảng đánh dấu đỉnh đã xét
    
    /*TODO: Code theo ý tưởng trong bài hướng dẫn. 
    Lưu danh sách cạnh của cây khung trong mảng spanningTree*/

    //TODO: in danh sách cây khung để kiểm tra
}

/*Câu 3:
- Viết thuật toán Kruskal tìm cây khung có trọng số nhỏ nhất
*/
void kruskalAlgorithm(Graph g){
    int nSpanningTree = 0; //Số cạnh cây khung ban đầu bằng 0
    EDGE spanningTree[MaxEdge]; //Danh sách cạnh của cây khung

    bool visited[MaxVertex];    //Mảng đánh dấu đỉnh đã xét

    Edge graphEdges[MaxEdge];  //Mảng chứa danh sách cạnh của đồ thị
    
    //TODO: lần lượt đưa các cạnh của đồ thị G vào danh sách cạnh graphEdges

    //TODO: sắp xếp danh sách graphEdges theo thứ tự trọng số w tăng dần

    /*TODO: bổ sung lần lượt cạnh trong danh sách trên vào cây khung sao cho không phát sinh chu trình. 
    Lặp lại khi số cạnh cây khung vẫn còn nhỏ hơn N - 1. 
    Lưu danh sách cạnh của cây khung trong mảng spanningTree*/

    //TODO: in danh sách cây khung để kiểm tra
}

int main() {
    //TODO: Code here

    return 0;
}