#include <iostream>
#include <cmath>
using namespace std;



bool IsSquareNum(long long), IsPrime(long long), IsOdd(long long);

long long ReverseNum(long long), NumeralCondSum(long long, char);



/// -------------------------------------------------------------------------- ///
///                                    Menu                                    ///
/// -------------------------------------------------------------------------- ///
void menu()
{
    cout << endl;
    cout << "==================================== Menu ====================================" << endl;
    cout << "1. Tra ve so nghich dao                        4. Co phai la so nguyen to" << endl;
    cout << "2. Co phai la so doi xung?                     5. Tong cac chu so le" << endl;
    cout << "3. Co phai la so chinh phuong?                 6. Tong cac chu so chinh phuong" << endl;
}

/// -------------------------------------------------------------------------- ///
///                                   main()                                 ///
/// -------------------------------------------------------------------------- ///
int main()
{
    int option;
    long long inp;

    menu();

    do
    {
        if (option == -1)
            return 0;

        else
        {
            cout << endl << "Nhap ma so (-1 de thoat): ";
            cin >> option;
        }
    } while (option < 1 || 6 < option);

    cout << endl << "----------[ " << option << " ]----------" << endl;

    cout << endl << "Nhap vao mot so nguyen: ";
    cin >> inp;

    switch (option)
    {
        case 1:
        {
            cout << endl << "So nghich dao cua " << inp << " la: " << ReverseNum(inp) << endl;
            break;
        }

        case 2:
        {
            cout << endl << inp;
            (inp == ReverseNum(inp)) ? cout << " la so doi xung" << endl : cout << " khong phai la so doi xung" << endl;
            break;
        }

        case 3:
        {
            cout << endl << inp;
            IsSquareNum(inp) ? cout << " la so chinh phuong" << endl : cout << " khong phai la so chinh phuong" << endl;
            break;
        }

        case 4:
        {
            cout << endl << inp;
            IsPrime(inp) ? cout << " la so nguyen to" << endl : cout << " khong phai la so nguyen to" << endl;
            break;
        }

        case 5:
        {
            cout << endl << "Tong cac chu so le cua " << inp << " la: " << NumeralCondSum(inp, 'o') << endl;
            break;
        }

        case 6:
        {
            cout << endl << "Tong cac chu so chinh phuong cua " << inp << " la: " << NumeralCondSum(inp, 's') << endl;
            break;
        }
    }
    
    return 0;
}



/// -------------------------------------------------------------------------- ///
///                                IsSquareNum()                               ///
/// -------------------------------------------------------------------------- ///
bool IsSquareNum(long long inp)
{
    inp = double (inp);

    if (sqrt(inp) == (long long)sqrt(inp))
        return true;
    
    else
        return false;
}

/// -------------------------------------------------------------------------- ///
///                                  IsPrime()                                 ///
/// -------------------------------------------------------------------------- ///
bool IsPrime(long long inp)
{  
    long long checkPnt = 0;
    checkPnt = inp/2;

    for(int i = 2; i <= checkPnt; i++)
    {  
        if(inp % i == 0)
        {  
            return false;
        }
    }

    return true;
}

/// -------------------------------------------------------------------------- ///
///                                   IsOdd()                                  ///
/// -------------------------------------------------------------------------- ///
bool IsOdd(long long inp)
{
    if (inp % 2 == 0)
        return false;
    
    else
        return true;
}

/// -------------------------------------------------------------------------- ///
///                                 ReverseNum()                               ///
/// -------------------------------------------------------------------------- ///
long long ReverseNum(long long inp)
{
    long long temp, mod;

    while(inp > 0)
    {
        temp = inp % 10;          // Lấy chữ số cuối của inp
        mod = (mod*10) + temp;    // ... và thêm vào cuối biến mod
        inp = inp / 10;           // Bỏ đi chữ số vừa lấy từ inp
    }

    return mod;
}

/// -------------------------------------------------------------------------- ///
///                              NumeralCondSum()                              ///
/// -------------------------------------------------------------------------- ///
long long NumeralCondSum(long long inp, char mode)
{
    long long res = 0;

    while (inp != 0)
    {
        int temp = inp % 10;
        
        switch (mode)
        {
            case 'o': if (IsOdd(temp))          res += temp; break;
            case 's': if (IsSquareNum(temp))    res += temp; break;
            case 'p': if (IsPrime(temp))        res += temp; break;
        }
        
        inp /= 10;
    }

    return res;
}