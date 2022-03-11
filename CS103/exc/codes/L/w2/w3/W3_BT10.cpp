/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 10 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

int main()
{
    long long inp;

    cout << endl << "Nhap 1 so nguyen duong: ";
    cin >> inp;

    if (inp <= 0)
    {
        cout << "So nhap vao phai la so nguyen duong." << endl;
        main();
    }

    else
    {
        cout << endl << "Cac uoc so cua so nguyen duong do la: " << endl;

        for (long long i = 1; i <= inp; i++)
        {
            if (inp % i == 0)
            {
                cout << i << " ";
            }
        }

        cout << endl;
    }
    
    return 0;
}