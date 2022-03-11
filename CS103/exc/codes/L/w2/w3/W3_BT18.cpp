/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 18 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;


int main()
{
    string inp, temp;

    cout << "Nhap day so nguyen duong ket thuc bang -1: ";
    getline(cin, inp);

    /// -------------------------------------------------------------------------- ///
    ///                        Tạo mảng cho dãy số vừa nhập                        ///
    /// -------------------------------------------------------------------------- ///

    int arr_size = 0, arr_pos_counter = 0;

    for (int i = 0; i <= inp.length(); i++)
    {
        if (inp.at(i) == ' ')
        {
            arr_size += 1;
        }
    }

    int arr[arr_size];

    temp += inp.at(0);

    for (int j = 1; j <= inp.length(); j++)
    {
        if (inp.at(j+2) == '-')
        {
            break;
        }

        else
        {
            while (inp.at(j+1) != ' ', j++)       // Nối các chữ số liền kề nhau      //? Do dùng kí tự '-' nên không sợ lỗi OOR.
            {
                temp += inp.at(j+1);
            }

            arr[arr_pos_counter] = stoi(temp);                              // Đổi qua int và nhét vào mảng
            temp = "";
            arr_pos_counter += 1;
        }
    }


    /// -------------------------------------------------------------------------- ///
    ///                         Tìm số lớn thứ 3 trong dãy                         ///
    /// -------------------------------------------------------------------------- ///

    int max_1 = 0, max_2 = 0, res = arr[0];

    for (int i = 1; i < sizeof(arr); i++)
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
    }

    cout << endl << "So lon thu 3 trong day so vua nhap la: " << res << endl;;
    
    return 0;
}