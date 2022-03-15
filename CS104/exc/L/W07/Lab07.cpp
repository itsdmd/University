/*Viết chương trình C++ cài đặt các thuật toán sắp xếp
  Họ và tên SV:
  MSSV:  
*/
#include <iostream>
#include <stdlib.h>

using namespace std;

void printArray(int a[], int n) {
    //TODO: Code here    
}

void swap(int &a, int &b) {
    //TODO: Code here
}

/*Cài đặt thuật toán InterchangeSort - 
thuật toán sắp xếp đã từng thực hành trong môn học trước*/
void interchangeSort(int a[], int n) {
    //TODO: Code here
}

/*Cài đặt thuật toán SelectionSort*/
void selectionSort(int a[], int n) {
    //TODO: Code here
}

/*Cài đặt hàm Hiệu chỉnh node thứ i thỏa mãn max-heap*/
void heapify(int a[], int n, int i) {
    /*Gọi left và right là 2 phần tử liên đới (2 con) của node i
    int left = ...
    int right = ....*/
    //TODO: code here

    /*Tìm giá trị lớn nhất giữa cha (node i) và 2 con (left và right)
    Lưu ý: cần kiểm tra left và right hợp lệ*/
    int max = i;
    //TODO: code here
    
    /*Nếu giá trị lớn nhất không phải cha (node i)*/
    if(max != i) { 
        /*
        - Hoán vị giá trị lớn nhất với cha
        - Gọi đệ quy hiệu chỉnh lan truyền tại node con
        */
       //TODO: code here
    }
}

/*Cài đặt thuật toán HeapSort*/
void heapSort(int a[], int n) {
    /*Xây dựng max-heap
    Hiệu chỉnh các node theo thứ tự từ vị trí n/2-1 -> 0*/
    //TODO: code here
    
    for (int i = n-1; i >= 0; i--){
        /*
        - Hoán vị node gốc về vị trí đúng (vị trí i)
        - Gọi đệ quy hiệu chỉnh node gốc
        */
       //TODO: code here
    }
}

int main() {
    /*Random ngẫu nhiên n số nguyên từ 1-100*/
    srand (time(NULL));
    int n = 10;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100 + 1;
    }


    
    /*Hoàn thiện hàm main để sắp xếp bằng các thuật toán trên*/
    //TODO: code here
    return 0;
}