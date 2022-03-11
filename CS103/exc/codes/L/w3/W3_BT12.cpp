/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 12 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

int main()
{
    int n, pprev = 0, prev = 1, outp = 1;

    cout << endl << "Nhap so phan tu dau tien cua day Fibonacci can in: ";
    cin >> n;

    if (n <= 0)
    {
        cout << endl << "So nhap vao phai la so nguyen lon hon 0.";
        main();
    }

    else
    {
        cout << 1;
        for (int i = 0; i <= n; i++)
        {
            outp = pprev + prev;
            pprev = prev;
            prev = outp;
        }
        
        cout << outp << endl;
    }
    
    return 0;
}