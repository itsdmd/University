/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 07 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <cmath>
using namespace std;

bool checkSquared(long long inp_s)
{
    long long sqrted;
    bool satisfied;

    if (inp_s < 0)
    {
        satisfied = false;
    }

    else
    {
        sqrted = sqrt(inp_s);
        (sqrted*sqrted == inp_s) ? (satisfied = true) : (satisfied = false);
    }

    return satisfied;
}

bool checkLeap(long long y)
{
    bool leap = false;

    switch (y % 100 == 0)   // Check xem có phải năm thế kỷ không (vd: 100, 700, 2000, etc.)
    {
        case false:
        {
            if (y % 4 == 0)
            {
                leap = true;
            }
            break;
        }
        
        case true:
        {
            if (y % 4 == 0 && y % 400 == 0)
            {
                leap = true;
            }
            break;
        }
    }

    return leap;
}

bool checkPrime(long long inp_p)
{
    bool prime = true;

    if (inp_p < 0 || inp_p == 0 || inp_p == 1)
    {
        prime = false;
    }

    else
    {
        for(int i = 2; i <= int(sqrt(inp_p)); i++)
        {
            if(inp_p % i == 0)
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
    
    cout << "Nhap so nguyen duong: ";
    cin >> inp;

    cout << endl;
    checkSquared(inp) ? (cout << inp << " la so chinh phuong." << endl) : (cout << inp << " khong phai la so chinh phuong." << endl);
    checkLeap(inp) ? (cout << "Nam " << inp << " la nam nhuan." << endl) : (cout << "Nam " << inp << " khong phai la nam nhuan." << endl);
    checkPrime(inp) ? (cout << inp << " la so nguyen to." << endl) : (cout << inp << " khong phai la so nguyen to." << endl);
    
    return 0;
}