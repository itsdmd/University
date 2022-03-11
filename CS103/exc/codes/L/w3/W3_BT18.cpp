/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 18 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
    vector <int> arr;       // Giúp rút gọn code và tiết kiệm bộ nhớ, thay vì phải lưu input vào biến tạm thời r sau đó khai báo mảng với độ lớn biết trước
    bool cont = true;
    int counter = 1;

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
            arr.push_back(t);       //? Tránh lỗi bị hụt cho lần push back khởi tạo
            arr.push_back(t);
            counter += 1;
        }

        else
        {
            arr.push_back(t);
            counter += 1;
        }
    }

    /// -------------------------------------------------------------------------- ///
    ///                         Tìm số lớn thứ 3 trong dãy                         ///
    /// -------------------------------------------------------------------------- ///

    //? Ở đây, do thứ tự về độ lớn đã được biết trước và tương đới nhỏ nên không cần sort để giảm runtime
    
    int max_1 = 0, max_2 = 0, res = arr[0];

    for (int i = 1; i <= arr.size(); i++)
    {
        if (arr[i] >= max_1)
        {
            res = max_2;
            max_2 = max_1;
            max_1 = arr[i];
        }

        else if (arr[i] >= max_2)
        {
            res = max_2;
            max_2 = arr[i];
        }

        else if (arr[i] >= res)
        {
            res = arr[i];
        }

        //? Log thuật toán
        // cout << "max_1 = " << max_1 << " | max_2 = " << max_2 << " | res = " << res << endl;
    }

    cout << endl << "So lon thu 3 trong day so vua nhap la: " << res << endl;
    
    return 0;
}