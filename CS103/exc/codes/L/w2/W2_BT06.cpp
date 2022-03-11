/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
-------------------------------- Bài tập 6 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

double r;

int main()
{
    cout << endl << "Nhap ban kinh duong tron: ";
    cin >> r;

    if (r <= 0)
    {
        cout << "Ban kinh duong tron phai lon hon 0." << endl;
        main();
    }

    else
    {
        double p = 2 * M_PI *r;
        double s = M_PI * pow(r, 2);
        cout << endl << "Chu vi: " << fixed << setprecision(3) << p << endl << "Dien tich: " << fixed << setprecision(3) << s << endl;
    }
    
    return 0;
}