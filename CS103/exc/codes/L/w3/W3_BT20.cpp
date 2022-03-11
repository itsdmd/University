/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 20 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

int main()
{
    const int   p0 = 25000, p1 = 600, p2 = 400, p3 = 200,
                s1 = 50, s2 = 51, s3 = 200, s4 = 201;
    long long t, p;

    cout << endl << "Nhap thoi gian goi (phut): ";
    cin >> t;

    if (t <= 0)
    {
        cout << endl << "Du lieu nhap vao phai lon hon 0." << endl;
        main();
    }

    else
    {
        if (t <= s1)
        {
            p = p0 + p1*t;
        }

        else if (s2 <= t && t <= s3)
        {
            p = p0 + p1*s1 + ((t-s2) * p2);
        }

        else
        {
            p = p0 + p1*s1 + ((s3-s2) * p2) + ((t-s4) * p3);
        }

        cout << "Tong tien phai tra la: " << fixed << p << endl;
    }
    
    return 0;
}