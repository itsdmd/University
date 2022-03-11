/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 19 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


vector <int> _sort(vector <int> inp, int size)
{
    int i, j, min, temp;

    for (i = 0; i < (size - 1); i++)
    {
        min = i;                                // Vị trí đang xét

        for (j = i + 1; j < size; j++)
        {
            if (inp[j] < inp[min])              // Duyệt qua cả mảng xem có số nào nhỏ hơn ko
            {
                min = j;
            }
        }

        // Hoán vị
        temp = inp[i];
        inp[i] = inp[min];
        inp[min] = temp;
    }

    return inp;
}

int main()
{
    vector <int> arr;       //? Giúp rút gọn code và tiết kiệm bộ nhớ, thay vì phải lưu input vào biến tạm thời r sau đó khai báo mảng với độ lớn biết trước
    bool cont = true;
    int counter = 1, pos;

    cout << endl << "Nhap day so nguyen duong ket thuc bang -1: ";

    while (cont)
    {
        cout << endl << "Nhap so thu " << counter << ": ";

        int t;
        cin >> t;

        if (t == -1)
        {
            cont = false;
            break;
        }

        else if (counter == 1)
        {
            arr.push_back(t);
            counter += 1;
        }

        else
        {
            arr.push_back(t);
            counter += 1;
        }
    }

    cout << endl << "Nhap n: ";
    cin >> pos;

    pos -= 1;       //? Arrray bắt đầu từ 0

    /// -------------------------------------------------------------------------- ///
    ///                         Tìm số lớn thứ n trong dãy                         ///
    /// -------------------------------------------------------------------------- ///

    //sort(begin(arr), end(arr));

    arr = _sort(arr, arr.size());

    //? Log
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << "[" << i << "]" << " " << arr[i] << endl;
    // }

    cout << endl << "So lon thu " << pos << " trong day vua nhap la: " << arr[pos] << endl;

    return 0;
}