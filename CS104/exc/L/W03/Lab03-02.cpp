/*Lab 03 - BT 02: (6điểm)
Làm lại bài tập lab02-02 sử dụng DANH SÁCH LIÊN KẾT yêu cầu chi tiết như sau:
Mỗi sinh viên gồm các thông tin: MSSV, Họ Tên, Ngày tháng năm sinh, Điểm Tin.
Yêu cầu: ngày tháng năm sinh được quản lý bằng cấu trúc với 3 thành phần riêng biệt.
1 Viết hàm Nhập và Xuất thông tin danh sách sinh viên.
Yêu cầu: Sử dụng danh sách liên kết đơn, mỗi Node trong danh sách liên kết chứa thông tin 1 sinh viên
2 Viết hàm in ra danh sách sinh viên vừa nhập
3 Viết hàm in ra thông tin 1 sinh viên Họ Tên, MSSV và ngày tháng năm sinh (dd/mm/yyyy)
của những sinh viên có điểm Tin lớn hơn hoặc bằng 5.
4 Viết hàm đếm số lượng sinh viên sinh vào tháng 6.

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
    float cs_score;

    STUDENT *pNext;
};


STUDENT *CreateStudent()
{
    STUDENT *p = new STUDENT;
    long id;
    string name;
    DoB dob;
    float cs_score;

    cout << "Nhap MSSV: ";
    cin >> id;
    cout << "Nhap ten: ";
    cin.ignore(); getline(cin, name);
    cout << "Nhap ngay thang nam sinh: ";
    cin >> dob.d >> dob.m >> dob.y;
    cout << "Nhap diem tin: ";
    cin >> cs_score;
    
    p->id = id;
    p->name = name;
    p->dob = dob;
    p->cs_score = cs_score;
    p->pNext = NULL;

    return p;
}

void AddStudent(STUDENT *&pHead, STUDENT *pNew)
{
    if (pHead == NULL)
    {
        pHead = pNew;
    }
    else
    {
        STUDENT *p = pHead;
        while (p->pNext != NULL)
        {
            p = p->pNext;
        }
        p->pNext = pNew;
    }
}

void Prnt(STUDENT *A)
{
    cout << "MSSV: " << A->id << "\n";
    cout << "Ten: " << A->name << "\n";
    cout << "Ngay thang nam sinh: " << A->dob.d << "/" << A->dob.m << "/" << A->dob.y << "\n";
    cout << "Diem tin: " << A->cs_score << "\n";
}

void PrntList(STUDENT *pHead)
{
    STUDENT *p = pHead;

    while (p != NULL)
    {
        Prnt(p);
        p = p->pNext;
    }
}

void PrntCond(STUDENT *pHead)
{
    STUDENT *p = pHead;

    while (p != NULL)
    {
        if (p->cs_score >= 5)
        {
            Prnt(p);
        }
        p = p->pNext;
    }
}

int Count(STUDENT *pHead)
{
    STUDENT *p = pHead;
    int count = 0;

    while (p != NULL)
    {
        if (p->dob.m == 6)
        {
            count++;
        }
        p = p->pNext;
    }
    
    return count;
}

int main()
{
    STUDENT *pHead = NULL;
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            pHead = CreateStudent();
        }
        else
        {
            AddStudent(pHead, CreateStudent());
        }
    }

    cout << "\n\n\nDanh sach sinh vien:\n";
    PrntList(pHead);

    cout << "\n\n\n";

    cout << "Thong tin cac sinh vien co diem Tin lon hon hoac bang 5: \n";
    PrntCond(pHead);
    cout << "\n\n";

    cout << "So sinh vien sinh vao thang 6: " << Count(pHead) << "\n\n";

    return 0;
}