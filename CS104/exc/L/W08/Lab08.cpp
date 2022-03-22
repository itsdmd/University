/*Họ và tên SV: Đào Minh Đức
  MSSV: 2159003

  1. Viết chương trình C++ cài đặt 5 thuật toán sắp xếp: interchange Sort, selection Sort, heap Sort, quick Sort, merge Sort
  Cài đặt với kiểu dữ liệu trừu tượng để có thể thực hiện được câu 2 và câu 3 bên dưới chỉ bằng cách đổi file đầu vào
  2. So sánh thời gian chạy của mỗi thuật toán và điền kết quả bên dưới
Đầu vào lấy dữ liệu từ file input.txt, file chứa 10000 phần tử số nguyên cách nhau bởi kí tự xuống dòng
Điền thời gian chạy mỗi thuật toán vào phần sau đây:
- interchange Sort : 0.30913
- selection Sort   : 0.27133
- heap Sort        :
- quick Sort       :
- merge Sort       :
  3. So sánh thời gian chạy của mỗi thuật toán và điền kết quả bên dưới
Đầu vào lấy dữ liệu từ file f_input.txt, file chứa 10000 phần tử số thực cách nhau bởi kí tự xuống dòng
Điền kết quả vào phần sau đây:
- interchange Sort : 0.27133
- selection Sort   : 0.27133
- heap Sort        :
- quick Sort       :
- merge Sort       :
*/
#include <iostream>
#include <fstream>


template <typename T>
void printArray(T a[], int n) {
    std::cout << "\nMang gom cac phan tu sau:\n";
    for (int i = 0; i < n; i++)
        std::cout << a[i] << "\t";
}

template <typename T>
void copyArray(T a[], int n, T b[]) {
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}

template <typename T>
void swap1(T& a, T& b) {
    T t = a;
    a = b;
    b = t;
}

/// ------------------------------------------------------------------------ ///
///                             Interchange Sort                             ///
/// ------------------------------------------------------------------------ ///
template <typename T>
void interchangeSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap1(a[i], a[j]);
}

/// ------------------------------------------------------------------------ ///
///                              Selection Sort                              ///
/// ------------------------------------------------------------------------ ///
template <typename T>
void selectionSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap1(a[i], a[min]);
    }
}

/// ------------------------------------------------------------------------ ///
///                                 Heap Sort                                ///
/// ------------------------------------------------------------------------ ///
template <typename T>
void heapify(T a[], T n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int max = i;
    
    if (left < n && a[left] > a[max]) max = left;
    if (right < n && a[right] > a[max]) max = right;
    
    if(max != i) {
        swap1(a[i], a[max]);
        heapify(a, n, max);
    }
}

template <typename T>
void heapSort(T a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
        
    for (int i = n - 1; i >= 0; i--) {
        swap1(a[0], a[i]);
        heapify(a, i, 0);
    }
}

/// ------------------------------------------------------------------------ ///
///                                Quick Sort                                ///
/// ------------------------------------------------------------------------ ///
template <typename T>
void quickSort(T a[], int n) {
    if (n <= 1) return;
    int pivot = a[0];
    int i = 0, j = n - 1;
    while (i < j) {
        while (i < j && a[j] >= pivot) j--;
        a[i] = a[j];
        while (i < j && a[i] <= pivot) i++;
        a[j] = a[i];
    }
    a[i] = pivot;
    quickSort(a, i);
}


/// ------------------------------------------------------------------------ ///
///                                Merge Sort                                ///
/// ------------------------------------------------------------------------ ///
template <typename T>
void mergeSort(T a[], int n, int m) {
    T i = 0, j = n - m, k = 0;
    T *temp = new T[n];
    
    while (i < n && j < n) {
        if (a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    
    while (i < n) temp[k++] = a[i++];
    while (j < n) temp[k++] = a[j++];
    
    for (i = 0; i < n; i++) a[i] = temp[i];
    
    delete[] temp;
}

template <typename T>
void SortCollection(T inp[], int n, int mode){
    clock_t t;
    t = clock();
    
    switch(mode){
        case 1:
            std::cout << "\n========== Interchange Sort ==========\n";
            interchangeSort(inp, n);
            break;
        case 2:
            std::cout << "\n========== Selection Sort ==========\n";
            selectionSort(inp, n);
            break;
        // case 3:
        //     std::cout << "\n========== Heap Sort ==========\n";
        //     heapSort(inp, n);
        //     break;
        // case 4:
        //     std::cout << "\n========== Quick Sort ==========\n";
        //     quickSort(inp, n);
        //     break;
        // case 5:
        //     std::cout << "\n========== Merge Sort ==========\n";
        //     mergeSort(inp, n, n / 2);
        //     break;
        default: break;
    }
    
    // printArray(inp, n);
    t = clock() - t;
    std::cout << "\nThoi gian thuc hien sap xep voi ";
    switch (mode){
        case 1:
            std::cout << "Interchange Sort";
            break;
        case 2:
            std::cout << "Selection Sort";
            break;
        case 3:
            std::cout << "Heap Sort";
            break;
        case 4:
            std::cout << "Quick Sort";
            break;
        case 5:
            std::cout << "Merge Sort";
            break;
        default: break;
    }
    std::cout <<": " << ((float)t) / CLOCKS_PER_SEC;
}



int main() {
    int n = 10000;
    int a_i[10000], t_i[10000];
    float a_f[10000], t_f[10000];
    
    std::fstream f_i, f_f;
    //f.open("input.txt", std::ios::in); //đọc dữ liệu số nguyên
    //f.open("f_input.txt", ios::in); //đọc dữ liệu số thực
    f_i.open("/home/dmd/Documents/University/CS104/exc/L/W08/input.txt", std::ios::in); //đọc dữ liệu số nguyên
    if (f_i.fail()) {
        std::cout << "Khong mo dc file";
        return 0;
    }
    for (int i = 0; i < n; i++){
        f_i >> a_i[i];
    }
    f_i.close();


    f_f.open("/home/dmd/Documents/University/CS104/exc/L/W08/f_input.txt", std::ios::in); //đọc dữ liệu số thực
    if (f_f.fail()) {
        std::cout << "Khong mo dc file";
        return 0;
    }
    for (int i = 0; i < n; i++){
        f_f >> a_f[i];
    }
    f_f.close();
    
    
    
    for (int i = 1; i <= 5; i++) {
        copyArray(a_i, n, t_i);
        copyArray(a_f, n, t_f);
        
        SortCollection(t_i, n, i);
        SortCollection(t_f, n, i);
    }
    

    return 0;
}