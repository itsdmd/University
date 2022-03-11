/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
-------------------------------- Bài tập 7 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
using namespace std;

double m, d;

int main()
{
    
    cout << endl << "Nhap khoi luong (kg) va khoi luong rieng (kg/m^3) cua vat: ";
    cin >> m >> d;

    if (m <= 0 || d <= 0)
    {
        cout << "Cac gia tri nhap vao phai lon hon 0" << endl;
        main();
    }

    else
    {
        cout << endl << "The tich cua vat: " << fixed << setprecision(3) << m / d << endl;
    }
    
    return 0;
}