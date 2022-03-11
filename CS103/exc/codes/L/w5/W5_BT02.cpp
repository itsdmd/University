/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 02 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;


int DigitCounter(long long);

long long Factorial(long long), Fibbo(long long), RecursiveEquation(long long);


/// -------------------------------------------------------------------------- ///
///                                   menu()                                   ///
/// -------------------------------------------------------------------------- ///
void menu()
{
    cout << endl;
    cout << "================================ Menu =================================" << endl;
    cout << " 1. Giai thua mot so nguyen duong      3. S(n) = 2*S(n-1) + 3" << endl;
    cout << " 2. So Fibbonacci thu n                4. So chu so mot cua so nguyen n" << endl;
}



/// -------------------------------------------------------------------------- ///
///                                   main()                                   ///
/// -------------------------------------------------------------------------- ///
int main()
{
    menu();

    int mode;
    long long n;

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
        case 1: cout << endl << Factorial(n); break;
        case 2: cout << endl << Fibbo(n); break;
        case 3: cout << endl << RecursiveEquation(n); break;
        case 4: cout << endl << DigitCounter(n); break;
    }
    
    return 0;
}




/// -------------------------------------------------------------------------- ///
///                                 Factorial()                                ///
/// -------------------------------------------------------------------------- ///
long long Factorial(long long inp)
{
    long long res = 0;

    for (int i = 1; i <= inp; i++)
    {
        res *= i;
    }

    return res;
}

/// -------------------------------------------------------------------------- ///
///                                   Fibbo()                                  ///
/// -------------------------------------------------------------------------- ///
long long Fibbo(long long inp)
{
    int pprev = 0, prev = 1, res = 1;

    for (int i = 0; i <= (inp - 2); i++)        //? Trừ 2 số đầu là pprev và prev
    {
        res = pprev + prev;
        pprev = prev;
        prev = res;
    }
    
    return res;
}

/// -------------------------------------------------------------------------- ///
///                             RecursiveEquation()                            ///
/// -------------------------------------------------------------------------- ///
long long RecursiveEquation(long long inp)
{
    long long res;

    if (inp == 1)
        res = 4;
    
    else
        res = 2*RecursiveEquation(inp - 1) + 3;

    return res;
}

/// -------------------------------------------------------------------------- ///
///                                DigitCounter()                              ///
/// -------------------------------------------------------------------------- ///
int DigitCounter(long long inp)
{
    //// Nếu làm kiểu /=10 thì sẽ gặp lỗi khi có số 0 bên trong số đang xét
    return to_string(inp).length();
}