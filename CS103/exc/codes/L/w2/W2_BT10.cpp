/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 10 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
using namespace std;

double vat = 0.1, n, p;

int main()
{
    cout << endl << "Nhap don gia chua co thue gia tri gia tang va so luong san pham: ";
    cin >> p >> n;

    if (p < 0 || n < 0)
    {
        cout << endl << "Cac gia tri nhap vao phai lon hon 0" << endl;
        main();
    }

    else
    {
        cout << endl << "So tien phai tra: " << fixed << setprecision(3) << (n * p) + (n * p * vat) << endl;
    }
    
    return 0;
}