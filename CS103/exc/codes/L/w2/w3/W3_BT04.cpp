/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 04 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long inp, og, mod = 0, temp;

    cout << endl << "Nhap so nguyen duong: ";
    cin >> inp;

    if (inp < 0)
    {
        cout << endl << "So nhap vao khong hop le." << endl;
        main();
    }

    else
    {
        og = inp;

        while(inp > 0)
        {
            temp = inp % 10;            // Lấy chữ số cuối của inp
            mod = (mod*10) + temp;      // ... và thêm vào cuối biến mod
            inp = inp / 10;             // Bỏ đi chữ số vừa lấy từ inp
        }

        cout << endl << "So dao nguoc cua so nguyen vua nhap la: " << mod << endl;
    }
}