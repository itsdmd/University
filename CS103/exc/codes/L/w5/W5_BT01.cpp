/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 01 -------------------------------
------------------------------------------------------------------------*/


#include <iostream>
using namespace std;



long long PowerSum(int, int, bool), PowerSumAlt(int, int), ProdSum(int);



/// -------------------------------------------------------------------------- ///
///                                  menu()                                    ///
/// -------------------------------------------------------------------------- ///

void menu()
{
    cout << endl;
    cout << "======================================= Menu =======================================" << endl;
    cout << " 1. S(n) = 1 + 2 + ... + n            3. S(n) = 1 + 1*2 + 1*2*3 + ... + 1*2*3*...*n" << endl;
    cout << " 2. S(n) = 1^2 + 2^2 + ... + n^2      4. S(n) = x + x^2 + x^3 + ... + x^n" << endl;
}



/// -------------------------------------------------------------------------- ///
///                                   main()                                   ///
/// -------------------------------------------------------------------------- ///
int main()
{
    menu();

    int mode, n;

    do
    {
        cout << endl << "Nhap ma so (-1 de thoat): ";
        cin >> mode;

        if (mode == -1)
        {
            return 0;
        }
    } while (mode < 1 || 4 < mode);

    cout << endl << "========== [" << mode << "] ==========";
    do
    {
        cout << endl << "Nhap so nguyen duong n: ";
        cin >> n;
    } while (n < 1);

    switch (mode)
    {
        case 1: cout << "S(" << n << ") = " << PowerSum(n, 1, false); break;
        case 2: cout << "S(" << n << ") = " << PowerSum(n, 2, false); break;
        case 3: cout << "S(" << n << ") = " << ProdSum(n); break;
        case 4:
        {
            int x;

            do
            {
                cout << "Nhap so nguyen duong x: ";
                cin >> x;
            } while (x < 1);

            cout << endl << "S(" << n << ") = " << PowerSum(x, n, true);

            break;
        }
    }
    
    return 0;
}




/// -------------------------------------------------------------------------- ///
///                                 PowerSum()                                 ///
/// -------------------------------------------------------------------------- ///
long long PowerSum(int base, int power, bool const_base)        //// This func only consider base xor power to be const, not either
{
    long long res = 0;

    for (int i = 1; const_base ? (i <= power) : (i <= base); i++)
    {
        int temp;
        const_base ? (temp = base) : (temp = i);

        for (int j = 1; const_base ? (j < i) : (j < power); j++)
        {
            const_base ? (temp *= base) : (temp *= i);
        }

        res += temp;
    }

    return res;
}

/// -------------------------------------------------------------------------- ///
///                                  ProdSum()                                 ///
/// -------------------------------------------------------------------------- ///
long long ProdSum(int range)
{
    long long res = 0;

    for (int i = 1; i <= range; i++)
    {
        int cur = i;

        for (int j = 1; j < i; j++)
        {
            cur *= j;
        }

        res += cur;
    }

    return res;
}
