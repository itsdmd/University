/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
-------------------------------- Bài tập 2 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
using namespace std;

long long a, b;

int main()
{
    cout << "Nhap 2 so nguyen a, b: ";
    cin >> a >> b;
    cout << "a + b = " << fixed << setprecision(3) << a + b << endl;
    
    return 0;
}