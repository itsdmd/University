/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 17 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

bool checkLeap(int y)
{
    bool leap;

    switch (y >= 100)
    {
        case true:
        {
            switch (y % 100 == 0)
            {
                case true:
                {
                    switch (y % 400 == 0)
                    {
                        case true: leap = true; break;
                        case false: leap = false; break;
                    }

                    switch (y % 4 == 0)
                    {
                        case true: leap = true; break;
                        case false: leap = false; break;
                    }
                }
            }

            break;
        }

        case false:
        {
            switch (y % 4 == 0)
            {
                case true: leap = true; break;
                case false: leap = false; break;
            }

            break;
        }
    }

    return leap;
}

//? Dùng cthuc Zeller
int checkWeekday(int _d, int _m, int _y)
{
    if(_m == 1)
    {
        _m = 13;
        _y--;
    }

    if (_m == 2)
    {
        _m = 14;
        _y--;
    }

    int wkd = (_d + (13 * (_m + 1) / 5) + (_y % 100) + ((_y % 100) / 4) + ((_y / 100) / 4) + (5 * (_y / 100))) % 7;

    return wkd;
}

int main()
{
    int d, m, y;
    bool valid = true;

    cout << endl << "Nhap ngay, thang, nam: ";
    cin >> d >> m >> y;

    if ((d <= 0) || (d >= 32) || (m <= 0) || (m >= 13))
    {
        valid = false;
    }

    if ((m == 2) && (d >= 29))
    {
        valid = false;
    }

    if (((m == 2) || (m == 4) || (m == 6) || (m == 9) || (m == 11)) && (d == 31))
    {
        valid = false;
    }

    if ((m == 2) && (d == 29))
    {
        valid = checkLeap(y);
    }

    

    if (valid)
    {
        cout << endl << "Ngay do la ngay ";
        
        switch (checkWeekday(d, m, y))
        {
            case 0: cout << "Thu bay.";     break;
            case 1: cout << "Chu nhat.";    break;
            case 2: cout << "Thu hai.";     break;
            case 3: cout << "Thu ba.";      break;
            case 4: cout << "Thu tu.";      break;
            case 5: cout << "Thu nam.";     break;
            case 6: cout << "Thu sau.";     break;
        }

        cout << endl;
    }

    else
    {
        cout << endl << "Ngay nhap vao khong hop le." << endl;
    }
    
    return 0;
}