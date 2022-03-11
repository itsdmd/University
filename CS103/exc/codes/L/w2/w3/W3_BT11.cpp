/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 11 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <cmath>
using namespace std;


//// Lấy từ câu 7c
bool isPrime_11(long long inp)
{
    bool prime = true;

    if (inp < 0 || inp == 0 || inp == 1)
    {
        prime = false;
    }

    else
    {
        for(int i = 2; i <= int(sqrt(inp)); i++)
        {
            if(inp % i == 0)
            {
                prime = false;
                break;
            }
        }
    }

    return prime;
}

int main()
{
    long long inp;

    cout << endl << "Nhap 1 so nguyen duong: ";
    cin >> inp;

    if (inp <= 0)
    {
        cout << "So nhap vao phai la so nguyen duong." << endl;
        main();
    }

    else
    {
        cout << endl << "Cac uoc so nguyen to cua so nguyen duong do la: " << endl;

        for (long long i = 1; i <= inp; i++)
        {
            if (inp % i == 0)
            {
                if (isPrime_11(i))
                {
                    cout << i << " ";
                }
            }
        }

        cout << endl;
    }
    
    return 0;
}