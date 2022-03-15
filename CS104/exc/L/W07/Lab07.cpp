/*Viết chương trình C++ cài đặt các thuật toán sắp xếp
  Họ và tên SV: Đào Minh Đức
  MSSV: 2159003
*/


#include <iostream>
#include <stdlib.h>

using namespace std;

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    cout << endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

/*Cài đặt thuật toán InterchangeSort -
thuật toán sắp xếp đã từng thực hành trong môn học trước*/
void interchangeSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

/*Cài đặt thuật toán SelectionSort*/
void selectionSort(int a[], int n) {
    
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        
        swap(a[i], a[min]);
    }
}

/*Cài đặt hàm Hiệu chỉnh node thứ i thỏa mãn max-heap*/
void heapify(int a[], int n, int i) {
    /*Gọi left và right là 2 phần tử liên đới (2 con) của node i
    int left = ...
    int right = ....*/
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    /*Tìm giá trị lớn nhất giữa cha (node i) và 2 con (left và right)
    Lưu ý: cần kiểm tra left và right hợp lệ*/
    int max = i;
    
    if (left < n && a[left] > a[max]) max = left;
    if (right < n && a[right] > a[max]) max = right;
    
    /*Nếu giá trị lớn nhất không phải cha (node i)*/
    if(max != i) {
        /*
        - Hoán vị giá trị lớn nhất với cha
        - Gọi đệ quy hiệu chỉnh lan truyền tại node con
        */
        swap(a[i], a[max]);
        heapify(a, n, max);
    }
}

/*Cài đặt thuật toán HeapSort*/
void heapSort(int a[], int n) {
    /*Xây dựng max-heap
    Hiệu chỉnh các node theo thứ tự từ vị trí n/2-1 -> 0*/
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    
    for (int i = n-1; i >= 0; i--) {
        /*
        - Hoán vị node gốc về vị trí đúng (vị trí i)
        - Gọi đệ quy hiệu chỉnh node gốc
        */
        swap(a[0], a[i]);
        heapify(a, i, 0);
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
    cout << "Day so truoc khi sap xep: ";
    printArray(a, n);
    
    interchangeSort(a, n);
    cout << "\nSap xep bang Interchange Sort: ";
    printArray(a, n);
    
    selectionSort(a, n);
    cout << "\nSap xep bang Selection Sort: ";
    printArray(a, n);
    
    heapSort(a, n);
    cout << "\nSap xep bang Heap Sort: ";
    printArray(a, n);
    
    return 0;
}