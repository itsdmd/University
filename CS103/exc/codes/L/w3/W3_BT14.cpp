/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 14 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

long long getFactorial_14(int _inp)
{
    long long outp = 1;

    for (int i = 1; i <= _inp; i++)
    {
        outp *= i;
    }

    return outp;
}

int main()
{
    int inp;

    cout << endl << "Nhap mot so nguyen duong: ";
    cin >> inp;

    switch (inp < 0)
    {
        case false: cout << fixed << getFactorial_14(inp) << endl; main(); break;

        case true: break;
    }
    
    return 0;
}