/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 09 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int _case;      //  Tương ứng số nghiệm của ptr
    long int a, b, c;
    double x1, x2;

    cout << endl << "Nhap 3 so a, b, c: ";
    cin >> a >> b >> c;

    if (a == 0 && b ==0)
    {
        _case = 0;
    }

    else if (a == 0)
    {
        _case = 1;
    }

    else if ((b*b - 4*a*c) < 0)
    {
        _case = 0;
    }

    else
    {
        _case = 2;
    }

    switch (_case)
    {
        case 0: cout << endl << "Phuong trinh vo nghiem." << endl; break;
        
        case 1:
        {
            int ucln;               // Tìm UCLN để tối giản phân số
            ucln = __gcd(b, c);
        
            b /= ucln;
            c /= ucln;

            cout << endl << "Phuong trinh co 1 nghiem: x = " << fixed << -c << "/" << fixed << b << endl;

            break;
        }
        
        case 2:
        {
            x1 = (double(-b) + sqrt(pow(double(b), 2) - (4 * double(a) * double(c))) ) / (2 * double(a));
            x2 = (double(-b) - sqrt(pow(double(b), 2) - (4 * double(a) * double(c))) ) / (2 * double(a));

            cout << endl << "Phuong trinh co 2 nghiem: x1 = " << fixed << x1 << "; x2 = " << fixed << x2 << endl;

            break;
        }

    }
    
    return 0;
}