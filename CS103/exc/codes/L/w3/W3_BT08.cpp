/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 08 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long int a, b;
    cout << "Nhap a, b: ";
    cin >> a >> b;

    if (a == 0)
    {
        cout << "Phuong trinh vo nghiem.";
    }

    else if (a == 0 && b == 0)
    {
        cout << "Phuong trinh vo so nghiem.";
    }
    
    else
    {
        int ucln;               // Tìm UCLN để tối giản phân số
        ucln = __gcd(a, b);
    
        a /= ucln;
        b /= ucln;

        cout << "x = " << fixed << -b << "/" << fixed << a;
    }
    
    return 0;
}