/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 16 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

int main()
{
    float dtb;
    char tier;

    cout << endl << "Nhap diem trung binh: ";
    cin >> dtb;

    if (dtb < 0 || dtb > 10)
    {
        cout << "Du lieu nhap vao khong hop le." << endl;
        main();
    }

    else
    {
        if (dtb >= 9)
        {
            tier = 'A';
        }

        else if (dtb >= 7)
        {
            tier = 'B';
        }

        else if (dtb >= 5)
        {
            tier = 'C';
        }

        else
        {
            tier = 'F';
        }

        cout << endl << "Hoc sinh dat hang " << tier << endl;
    }
    
    return 0;
}