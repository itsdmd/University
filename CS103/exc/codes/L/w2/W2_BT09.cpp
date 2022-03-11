/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
-------------------------------- Bài tập 9 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

double v, s, t;

int nhap()
{
    cout << endl << "Nhap van toc (km/h) va quang duong (km): ";
    cin >> v >> s;

    if (v == 0 || s == 0)
    {
        cout << "Du lieu nhap vao phai lon hon 0" << endl;
        nhap();
    }

    return 0;
}

int main()
{
    nhap();

    t = s / v;

    // Lấy phần nguyên
    long t_h = long(t);

    // Cho phần nguyên = 0 rồi lấy đến số thập phân đầu tiên * 60
    int t_m = int( (t - long(t)) * 60 );

    // Cho phần nguyên và số thập phân đầu tiên = 0 rồi lấy đến số thập phân thứ 2 * 60
    int t_s = int( ( ( (t - long(t)) * 60 ) - long( (t - long(t)) * 60 ) ) * 60 );
    
    cout << "Thoi gian Jun di tu nha den truong la " << t_h << " gio " << t_m << " phut " << t_s << " giay." << endl;
    
    return 0;
}