/*Họ và tên SV: Đào Minh Đức
  MSSV: 2159003

    1. Viết chương trình C++ cài đặt 5 thuật toán sắp xếp: interchange Sort, selection Sort, heap Sort, quick Sort, merge Sort
    Cài đặt với kiểu dữ liệu trừu tượng để có thể thực hiện được câu 2 và câu 3 bên dưới chỉ bằng cách đổi file đầu vào
    2. So sánh thời gian chạy của mỗi thuật toán và điền kết quả bên dưới
        Đầu vào lấy dữ liệu từ file input.txt, file chứa 10000 phần tử số nguyên cách nhau bởi kí tự xuống dòng
        Điền thời gian chạy mỗi thuật toán vào phần sau đây:
            - interchange Sort : 0.307814
            - selection Sort   : 0.112652
            - heap Sort        : 0.002074
            - quick Sort       : 0.001728
            - merge Sort       : 0.001638
        3. So sánh thời gian chạy của mỗi thuật toán và điền kết quả bên dưới
        Đầu vào lấy dữ liệu từ file f_input.txt, file chứa 10000 phần tử số thực cách nhau bởi kí tự xuống dòng
        Điền kết quả vào phần sau đây:
            - interchange Sort : 0.275871
            - selection Sort   : 0.110269
            - heap Sort        : 0.002121
            - quick Sort       : 0.001630
            - merge Sort       : 0.001700
*/

// Test CM dup detection #02

#include <iostream>
#include <fstream>
#include <typeinfo>     // Get var type


/// ------------------------------------------------------------------------ ///
///                               Array-related                              ///
/// ------------------------------------------------------------------------ ///
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
bool testArray(T a[], int n) {
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return false;
    return true;
}


/// ------------------------------------------------------------------------ ///
///                                   swap1                                  ///
/// ------------------------------------------------------------------------ ///
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
/// ----------------------------- From 104.L.07 ---------------------------- ///
template <typename T>
void heapify(T a[], int n, int m) {
    int l = 2 * m + 1;
    int r = 2 * m + 2;

    int max = m;

    if (l < n && a[l] > a[max]) max = l;
    if (r < n && a[r] > a[max]) max = r;

    if(max != m) {
        swap1(a[m], a[max]);
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
void quickSort(T a[], int l, int r)
{
    if (l >= r) return;
    
    int pv = a[l],      // Head pos pivot
        count = 0;      // No. of to-be-swapped elements
    
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= pv)
            count++;
    }
    
    // Init pivot index
    int pv_idx = l + count;
    swap1(a[pv_idx], a[l]);
    
    
    int i = l, j = r;

    while (i < pv_idx && pv_idx < j) {
        while (a[i] <= pv)
            i++;

        while (a[j] > pv) j--;

        if (i < pv_idx && j > pv_idx)
            swap1(a[i++], a[j--]);
    }
 
    quickSort(a, l, pv_idx - 1);
    quickSort(a, pv_idx + 1, r);
}


/// ------------------------------------------------------------------------ ///
///                                Merge Sort                                ///
/// ------------------------------------------------------------------------ ///
template <typename T>
void merger(T a[], int n, int l, int m, int r) {
    T tmp_l[n],
      tmp_r[n];
    int x = 0,
        y = 0;
    
    for (int i = l; i <= m; i++)
        tmp_l[x++] = a[i];
    for (int i = m + 1; i <= r; i++)
        tmp_r[y++] = a[i];
    
    int i = 0,
        j = 0,
        k = l;
    
    while (i < x && j < y) {
        if (tmp_l[i] <= tmp_r[j])
            a[k++] = tmp_l[i++];
        else
            a[k++] = tmp_r[j++];
    }
    while (i < x)
        a[k++] = tmp_l[i++];
    while (j < y)
        a[k++] = tmp_r[j++];
}

template <typename T>
void mergeSort(T a[], int n, int l, int r) {
    if (l >= r) return;
    
    int m = (l + r) / 2;
    mergeSort(a, n, l, m);           // L
    mergeSort(a, n, m + 1, r);       // R

    merger(a, n, l, m, r);
}


/// ------------------------------------------------------------------------ ///
///                              SortCollection                              ///
/// ------------------------------------------------------------------------ ///
template <typename T>
void SortCollection(T inp[], int n, int type, bool print){
    clock_t t;
    t = clock();

    switch(type){
        case 1:
            std::cout << "\n========== Interchange Sort (" << typeid(inp[0]).name() << ") ==========\n";
            interchangeSort(inp, n);
            // std::cout << "Success: " << testArray(inp, n);
            if (print) printArray(inp, n);
            break;
        case 2:
            std::cout << "\n========== Selection Sort (" << typeid(inp[0]).name() << ") ==========\n";
            selectionSort(inp, n);
            // std::cout << "Success: " << testArray(inp, n);
            if (print) printArray(inp, n);
            break;
        case 3:
            std::cout << "\n========== Heap Sort (" << typeid(inp[0]).name() << ") ==========\n";
            heapSort(inp, n);
            // std::cout << "Success: " << testArray(inp, n);
            if (print) printArray(inp, n);
            break;
        case 4:
            std::cout << "\n========== Quick Sort (" << typeid(inp[0]).name() << ") ==========\n";
            quickSort(inp, 0, n);
            // std::cout << "Success: " << testArray(inp, n);      //* Ignore 0 for float array
            if (print) printArray(inp, n);
            break;
        case 5:
            std::cout << "\n========== Merge Sort (" << typeid(inp[0]).name() << ") ==========\n";
            mergeSort(inp, n, 0, n);
            // std::cout << "Success: " << testArray(inp, n);
            if (print) printArray(inp, n);
            break;
        default: break;
    }

    t = clock() - t;
    std::cout << "\nThoi gian thuc hien sap xep voi ";
    switch (type){
        case 1:
            std::cout << "Interchange Sort (" << typeid(inp[0]).name() << ")";
            break;
        case 2:
            std::cout << "Selection Sort (" << typeid(inp[0]).name() << ")";
            break;
        case 3:
            std::cout << "Heap Sort (" << typeid(inp[0]).name() << ")";
            break;
        case 4:
            std::cout << "Quick Sort (" << typeid(inp[0]).name() << ")";
            break;
        case 5:
            std::cout << "Merge Sort (" << typeid(inp[0]).name() << ")";
            break;
        default: break;
    }
    std::cout <<": " << ((float)t) / CLOCKS_PER_SEC << "s\n";
}


/// ------------------------------------------------------------------------ ///
///                                   main                                   ///
/// ------------------------------------------------------------------------ ///
int main() {
    int n = 10000;
    int a_i[10000], t_i[10000];
    float a_f[10000], t_f[10000];
    
    
    /// ------------------------------- Read data ------------------------------ ///
    std::fstream f_i, f_f;
    // f_i.open("input.txt", std::ios::in); //đọc dữ liệu số nguyên
    f_i.open("./res/input.txt", std::ios::in);  //* Use Run instead of Debug
    if (f_i.fail()) {
        std::cout << "Khong mo duoc file";
        return 1;
    }
    for (int i = 0; i < n; i++) {
        f_i >> a_i[i];
    }
    f_i.close();
    
    // f_f.open("f_input.txt", std::ios::in); //đọc dữ liệu số thực
    f_f.open("./res/f_input.txt", std::ios::in);
    if (f_f.fail()) {
        std::cout << "Khong mo duoc file";
        return 1;
    }
    for (int i = 0; i < n; i++) {
        f_f >> a_f[i];
    }
    f_f.close();
    
    
    /// -------------------------------- Sorting ------------------------------- ///
    for (int i = 1; i <= 5; i++) {
        // Change to 'true' to print the array after each sort
        bool print = false;
        
        copyArray(a_i, n, t_i);
        copyArray(a_f, n, t_f);

        SortCollection(t_i, n, i, print);
        SortCollection(t_f, n, i, print);
    }


    return 0;
}