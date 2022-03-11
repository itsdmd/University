#include <iostream>
using namespace std;

int main()
{
    long long y;
    int m;
    bool leap = false;

    cout << endl << "Nhap vao thang, nam: ";
    cin >> m >> y;

    if (m <= 0 || 13 <= m)
    {
        cout << "Thang nhap vao khong hop le";
        main();
    }

    else
    {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        {
            cout << endl << "Thang nay co 31 ngay." << endl;
        }

        else if (m != 2)
        {
            cout << endl << "Thang nay co 30 ngay." << endl;
        }

        else
        {
            switch (y % 100 == 0)   // Check xem có phải năm thế kỷ không (vd: 100, 700, 2000, etc.)
            {
                case false:
                {
                    if (y % 4 == 0)
                    {
                        leap = true;
                    }

                    leap ? cout << endl << "Thang nay co 29 ngay." << endl : cout << endl << "Thang nay co 28 ngay." << endl;

                    break;
                }
                
                case true:
                {
                    if (y % 4 == 0 &&  y % 400 == 0)
                    {
                        leap = true;
                    }

                    leap ? cout << endl << "Thang nay co 29 ngay." << endl : cout << endl << "Thang nay co 28 ngay." << endl;

                    break;
                }
            }
            
        }
    }
    
    return 0;
}