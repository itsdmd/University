#include <iostream>
using namespace std;



double Calc(long long, char);

long long Factorial(long long);



/// -------------------------------------------------------------------------- ///
///                                    Menu                                    ///
/// -------------------------------------------------------------------------- ///
void menu()
{
    cout << endl;
    cout << "============================== Menu ==============================" << endl;
    cout << "1. S = 1 + 2 + ... + n                  4. S = 1 * 2 * ... * n" << endl;
    cout << "2. S = 1^2 + 2^2 + ... + n^2            5. S = 1! + 2! + ... + n!" << endl;
    cout << "3. S = 1 + 1/2 + ... + 1/n" << endl;
}


/// -------------------------------------------------------------------------- ///
///                                   main()                                   ///
/// -------------------------------------------------------------------------- ///
int main()
{
    int option;
    double res;
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
    } while (option < 1 || 5 < option);

    cout << endl << "Nhap n: ";
    cin >> inp;

    switch (option)
    {
        case 1: res = Calc(inp, 'n'); break;
        case 2: res = Calc(inp, 's'); break;
        case 3: res = Calc(inp, 'f'); break;
        case 4: res = Calc(inp, 'p'); break;
        case 5: res = Calc(inp, 'F'); break;
    }

    cout << endl << "S = " << fixed << res << endl;
    
    return 0;
}



/// -------------------------------------------------------------------------- ///
///                                   Calc()                                   ///
/// -------------------------------------------------------------------------- ///
double Calc(long long inp, char mode)
{
    double res = 0;

    for (double i = 1; i <= inp; i++)
    {
        switch (mode)
        {
            case 'n': res += i;             break;          // Normal
            case 's': res += i*i;           break;          // Square
            case 'f': res += 1/i;           break;          // Fraction
            case 'p': res *= i;             break;          // Product
            case 'F': res += Factorial(i);  break;          // Factorial
        }
    }

    return res;
}

/// -------------------------------------------------------------------------- ///
///                                 Factorial()                                ///
/// -------------------------------------------------------------------------- ///
long long Factorial(long long inp)
{
    long long res = 1;

    for (int i = 2; i <= inp; i++)
        res *= i;

    return res;
}