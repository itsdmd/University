
/*Lab 02 - BT 02:
- Viết hàm Nhập và Xuất thông tin của một sinh viên của một trường Đại học.
Biết mỗi sinh viên gồm các thông tin: MSSV, Họ Tên, Ngày tháng năm sinh, Điểm Tin.
Yêu cầu: ngày tháng năm sinh được quản lý bằng cấu trúc với 3 thành phần riêng biệt.
- Viết hàm Nhập và Xuất thông tin một danh sách sinh viên.
Yêu cầu: danh sách sử dụng con trỏ cấp phát động.
- Viết hàm in ra Họ Tên, MSSV và ngày tháng năm sinh (dd/mm/yyyy)
của những sinh viên có điểm Tin lớn hơn hoặc bằng 5.
- Viết hàm đếm số lượng sinh viên sinh vào tháng 6.

Họ Tên  : Đào Minh Đức
MSSV    : 2159003
*/
#include <iostream>
#include <string>

using namespace std;

struct DoB
{
    int d, m, y;
};

struct STUDENT
{
    long id;
    string name;
    DoB dob;
    int cs_score;
};

void Inpt(STUDENT &A)
{
    cout << "Nhap MSSV: ";
    cin >> A.id;
    cout << "Nhap ten: ";
    cin >> A.name;
    cout << "Nhap ngay thang nam sinh: ";
    cin >> A.dob.d >> A.dob.m >> A.dob.y;
    cout << "Nhap diem Tin: ";
    cin >> A.cs_score;
}

void Prnt(STUDENT A)
{
    cout << "MSSV: " << A.id << "\n";
    cout << "Ten: " << A.name << "\n";
    cout << "Ngay thang nam sinh: " << A.dob.d << "/";
    if (A.dob.m < 10)
        cout << "0";
    cout << A.dob.m << "/" << A.dob.y << "\n";
    cout << "Diem tin: " << A.cs_score << "\n";
}

void InptList(STUDENT *&ds, int &n)
{
    cout << "Nhap so luong Sinh vien: ";
    cin >> n;
    ds = new STUDENT[n]; // Cấp phát động mảng 1 chiều n phần tử
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin Sinh vien " << i << ":"
             << "\n";

        Inpt(ds[i]);
    }
}

void PrntList(STUDENT *ds, int n)
{
    for (int i = 0; i < n; i++)
    {
        Prnt(ds[i]);
    }
}

void PrntCond(STUDENT *ds, int n)
{
    for (int i = 0; i < n; i++)
    {
        int counter = 1;
        if (ds[i].cs_score >= 5)
        {
            cout << "[ " << counter << " ]\n";
            counter++;

            cout << "MSSV: " << ds[i].id << "\n";
            cout << "Ten: " << ds[i].name << "\n";
            cout << "Ngay sinh: " << ds[i].dob.d << "/" << ds[i].dob.m << "/" << ds[i].dob.y << "\n\n";
        }
    }
}

int Count(STUDENT *ds, int n)
{
    int dem = 0;

    for (int i = 0; i < n; i++)
    {
        if (ds[i].dob.m == 6)
        {
            dem++;
        }
    }

    return dem;
}

int main()
{
    STUDENT *ds;
    int n;
    InptList(ds, n);
    PrntList(ds, n);

    cout << "\n\n\n";

    cout << "Thong tin cac sinh vien co diem Tin lon hon hoac bang 5: \n";
    PrntCond(ds, n);
    cout << "\n\n";

    cout << "So sinh vien sinh vao thang 6: " << Count(ds, n) << "\n\n";

    return 0;
}