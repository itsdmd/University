/*Lab 01 - BT 01: 
- Viết hàm đọc dãy số nguyên từ tập tin "Lab01-01.in" vào mảng 1 chiều.
Tập tin này có cấu trúc:
+ Dòng đầu tiên là một con số nguyên N là số lượng phần tử của dãy số.
+ Dòng tiếp theo là N con số nguyên cách nhau bởi khoảng trắng.
- Viết hàm xuất dãy số nguyên này ra màn hình
- Viết hàm tìm kiếm một số nguyên X có tồn tại trong dãy trên không?
- Viết hàm sắp xếp dãy số nguyên tăng dần.
- Viết hàm sắp xếp dãy số nguyên giảm dần.
- Viết hàm ghi kết quả vào tập tin "Lab01-01.out" với cú pháp:
+ Dòng đầu tiên ghi chữ "INCREASE"
+ Dòng thứ 2 ghi N số nguyên là kết quả sắp xếp tăng dần, cách nhau bằng khoảng trắng.
+ Dòng thứ 3 ghi chữ "DECREASE"
+ Dòng thứ 4 ghi N số nguyên là kết quả sắp xếp giảm dần, cách nhau bằng khoảng trắng.

Họ Tên  : Đào Minh Đức
MSSV    : 2159003
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream fs;

void DocTapTin(string tentaptin, int a[], int &n)
{
    string content, temp;
    int counter = 0;

    fs.open(tentaptin, fstream::in);

    fs >> n;

    for (int i = 0; i < n; i++)
    {
        fs >> a[counter];
        counter++;
    }

    fs.close();
}

void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << "\n";
}

bool TimKiem(int a[], int n, int x)
{
    bool res = false;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            res = true;
            break;
        }
    }

    return res;
}

// Kết quả sắp xếp được lưu trữ vào mảng mới b. Mảng a không thay đổi.
void SapXepTang(int a[], int n, int b[])
{
    for (int i = 0; i < n; i++)
        b[i] = a[i];

    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (b[j] > b[j + 1])
            {
                int temp = b[j];

                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}

// Kết quả sắp xếp được lưu trữ vào mảng mới b. Mảng a không thay đổi.
void SapXepGiam(int a[], int n, int b[])
{
    for (int i = 0; i < n; i++)
        b[i] = a[i];

    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (b[j] < b[j + 1])
            {
                int temp = b[j];

                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}

// b là mảng đã sắp xếp tăng dần, c là mảng đã sắp xếp giảm dần
void GhiTapTin(string tentaptin, int b[], int c[], int n)
{
    fs.open(tentaptin, fstream::out);

    fs << "INCREASE"
       << "\n";
    for (int i = 0; i < n; i++)
    {
        fs << b[i] << "\n";
    }

    fs << "DECREASE"
       << "\n";
    for (int i = 0; i < n; i++)
    {
        fs << c[i] << "\n";
    }

    fs.close();
}

int main()
{
    int a[100];
    int n;
    DocTapTin("Lab01-01.in", a, n);
    XuatMang(a, n);
    int x;
    cout << "Nhap vao so can tim: ";
    cin >> x;
    bool kq = TimKiem(a, n, x);

    cout << "\n";
    kq ? cout << "Tim thay" : cout << "Khong tim thay";

    int b[100], c[100];
    SapXepTang(a, n, b);
    SapXepGiam(a, n, c);
    GhiTapTin("Lab01-01.out", b, c, n);

    return 0;
}