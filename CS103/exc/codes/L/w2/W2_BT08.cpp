/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
-------------------------------- Bài tập 8 -------------------------------
------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int _age;
string _name;

int get_cur_yr()
{
    time_t now = time(0);           // Store timestamp định dạng unix
    tm *lct = localtime(&now);      // Tạo con trỏ tới địa chỉ của giá trị tương tự với biến timestamp của hàm localtime() [sử dụng alias để đỡ convert var type]
    int yr = 1900 + lct->tm_year;   // Trích xuất member _year
    
    return yr;
}

int nhap(string mode)
{
    if (mode =="n")
    {
        cout << endl << "Nhap ho va ten: ";
        getline(cin, _name);
    }

    else if (mode == "y")
    {
        int cur_yr = get_cur_yr();
    
        int yob;
        cout << endl << "Nhap nam sinh: ";
        cin >> yob;
        
        if (yob > cur_yr)
        {
            cout << "Nam sinh khong hop le" << endl;
            nhap("y");
        }

        else
        {
            _age = cur_yr - yob;
        }
    }

    return 0;
}

int main()
{
    nhap("n");
    nhap("y");

    cout << endl << "Tuoi hien tai cua " << _name << " la " << _age << endl;
    
    return 0;
}