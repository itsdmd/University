#include <iostream>
#include <ctime>
using namespace std;

int get_cur_yr()
{
    time_t now = time(0);           // Store timestamp định dạng unix
    tm *lct = localtime(&now);      // Tạo con trỏ tới địa chỉ của giá trị tương tự với biến timestamp của hàm localtime() [sử dụng alias để đỡ convert var type]
    int yr = 1900 + lct->tm_year;   // Trích xuất member _year
    
    return yr;
}

int main()
{
    int cur_yr = get_cur_yr();
    
    int yob;
    cout << endl << "Nhap nam sinh: ";
    cin >> yob;
    
    if (yob > cur_yr)
    {
        cout << "Nam sinh khong hop le" << endl;
        main();
    }

    else
    {
        cout << endl << "Tuoi: " << cur_yr - yob << endl;
    }
    
    return 0;
}