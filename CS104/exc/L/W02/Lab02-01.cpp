
/*Lab 02 - BT 01: 
- Viết hàm Nhập và Xuất tọa độ 2 điểm trong mặt phẳng Oxy. 
- Tính khoảng cách giữa 2 điểm.

Họ Tên  : Đào Minh Đức
MSSV    : 2159003
*/
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct DIEM
{
    float x, y;
};

void NhapToaDo(DIEM &A)
{
    cout << "Nhap x: ";
    cin >> A.x;

    cout << "Nhap y: ";
    cin >> A.y;
}

void XuatToaDo(DIEM A)
{
    cout << "Toa do cua diem: (" << A.x << ", " << A.y << ")" << endl;
}

float TinhKhoangCach(DIEM A, DIEM B)
{
    float kc = 0;

    kc = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));

    return kc;
}

int main()
{
    DIEM A;
    NhapToaDo(A);
    XuatToaDo(A);
    DIEM B;
    NhapToaDo(B);
    XuatToaDo(B);
    float kc = TinhKhoangCach(A, B);
    cout << "Khoang cach: " << kc << endl;
    return 0;
}