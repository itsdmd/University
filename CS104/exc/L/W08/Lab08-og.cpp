/*Họ và tên SV:
  MSSV:

  1. Viết chương trình C++ cài đặt 5 thuật toán sắp xếp: interchange Sort, selection Sort, heap Sort, quick Sort, merge Sort
  Cài đặt với kiểu dữ liệu trừu tượng để có thể thực hiện được câu 2 và câu 3 bên dưới chỉ bằng cách đổi file đầu vào
  2. So sánh thời gian chạy của mỗi thuật toán và điền kết quả bên dưới
Đầu vào lấy dữ liệu từ file input.txt, file chứa 10000 phần tử số nguyên cách nhau bởi kí tự xuống dòng
Điền thời gian chạy mỗi thuật toán vào phần sau đây:
- interchange Sort : 1.197
- selection Sort   : 
- heap Sort        : 
- quick Sort       : 
- merge Sort       : 
  3. So sánh thời gian chạy của mỗi thuật toán và điền kết quả bên dưới
Đầu vào lấy dữ liệu từ file f_input.txt, file chứa 10000 phần tử số thực cách nhau bởi kí tự xuống dòng
Điền kết quả vào phần sau đây:
- interchange Sort : 1.233
- selection Sort   :
- heap Sort        :
- quick Sort       :
- merge Sort       :
*/
#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
void printArray(T a[], int n) {
    //TODO: Code here   
    cout << "\nMang gom cac phan tu sau:" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << "\t";
}

template <typename T>
void swap1(T& a, T& b) {
    //TODO: Code here
    T t = a;
    a = b;
    b = t;
}

//Cài đặt lại thuật toán Interchange Sort với  kiểu dữ liệu trừu tượng
template <typename T>
void interchangeSort(T a[], int n) {
    //TODO: Code here
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap1(a[i], a[j]);
}

//Cài đặt lại thuật toán Selection Sort với  kiểu dữ liệu trừu tượng

//Cài đặt lại thuật toán Heap Sort với  kiểu dữ liệu trừu tượng

//Cài đặt lại thuật toán Quick Sort với  kiểu dữ liệu trừu tượng

//Cài đặt lại thuật toán merge Sort với  kiểu dữ liệu trừu tượng

int main() {
    int n = 10000;
    int a[10000];
     //float a[10000];
    fstream f;
    f.open("input.txt", ios::in); //đọc dữ liệu số nguyên
     //f.open("f_input.txt", ios::in); //đọc dữ liệu số thực
    if (f.fail()) {
        cout << "khong mo dc file";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        f >> a[i];        
    }

    clock_t t;        
    t = clock();    
    interchangeSort(a, n);
    t = clock() - t;
    printArray(a, n);
    cout << "\nThoi gian thuc hien săp xep voi interchange Sort : " << ((float)t) / CLOCKS_PER_SEC;
    
    return 0;
}