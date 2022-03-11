#include <iostream>
#include <algorithm>
using namespace std;



struct FRAC
{
    int tu, mau;

    bool operator==(FRAC &other)
    {
        if ((this->tu == other.tu) && (this->mau == other.mau))
            return true;
        
        else
            return false;
    }
    
    bool operator==(const FRAC &other)
    {
        if ((this->tu == other.tu) && (this->mau == other.mau))
            return true;
        
        else
            return false;
    }
};

const FRAC F_ZERO {0,0};


FRAC FracCalc(FRAC, FRAC, char), FracCompare(FRAC, FRAC, char);

void FracInput(FRAC &), FracPrinter(FRAC), FracSimplify(FRAC &), DivEqualize(FRAC, FRAC, FRAC &, FRAC &);




void menu()
{
    cout << endl;
    cout << "========================== Menu ==========================" << endl;
    cout << "1. Rut gon phan so            5. Kiem tra phan so am/duong" << endl;
    cout << "2. Tinh toan 2 phan so        6. So sanh 2 phan so"         << endl;
    cout << "3. Kiem tra phan so toi gian  7. Nhap/Xuat phan so"         << endl;
    cout << "4. Quy dong 2 phan so" << endl;
}

int main()
{
    int option;
    FRAC inp_1, inp_2;
    
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



    switch (option)
    {
       case 1:
       {
           FracInput(inp_1);
           FracSimplify(inp_1);

           cout << endl << "Phan so sau khi rut gon la: ";
           FracPrinter(inp_1);
           cout << endl;

           break;
       }

       case 2:
       {
           char mode;

           cout << endl << "===== Phan so 1 =====";
           FracInput(inp_1);
           cout << endl << "===== Phan so 2 =====";
           FracInput(inp_2);
           
           do
           {
               cout << endl << "Nhap phep toan: ";
               cin >> mode;
           } while (mode != '+' && mode != '-' && mode != '*' && mode != '/');

           cout << endl << "(";
           FracPrinter(inp_1); cout << ") " << mode << " ("; FracPrinter(inp_2); cout << ") = ";

           FracPrinter(FracCalc(inp_1, inp_2, mode));
           cout << endl;

           break;
       }

       case 3:
       {
           FracInput(inp_1);
           
           inp_2 = inp_1;
           FracSimplify(inp_2);

           cout << endl;
           if (inp_1 == inp_2)
           {
               FracPrinter(inp_1); cout << " la phan so toi gian";
           }

           else
           {
               FracPrinter(inp_1); cout << " la phan so chua toi gian";
           }

           cout << endl;

           break;
       }

       case 4:
       {
            cout << endl << "===== Phan so 1 =====";
            FracInput(inp_1);
            cout << endl << "===== Phan so 2 =====";
            FracInput(inp_2);

            cout << endl << endl << "2 phan so sau khi quy dong la: "; FracPrinter(inp_1); cout << " va "; FracPrinter(inp_2);
            cout << endl;

            break;
       }

       case 5:
       {
            FracInput(inp_1);

            cout << endl;
            FracPrinter(inp_1);
            (FracCompare(inp_1, F_ZERO, 'M') == inp_1) ? cout << " la phan so duong": cout << " la phan so am";
            cout << endl;

            break;
       }

       case 6:
       {
            cout << endl << "===== Phan so 1 =====";
            FracInput(inp_1);
            cout << endl << "===== Phan so 2 =====";
            FracInput(inp_2);


            cout << endl;
            FracPrinter(inp_1);

            if (FracCompare(inp_1, inp_2, 'M') == inp_1)
                cout << " > ";
            else if (FracCompare(inp_1, inp_2, 'M') == F_ZERO)
                cout << " = ";
            else
                cout << " < ";

            FracPrinter(inp_2);
            cout << endl;

            break;
       }

       case 7:
       {
           FracInput(inp_1);

           cout << endl << "Phan so vua nhap la: ";
           FracPrinter(inp_1);
       }
    }
    
    return 0;
}



/// ------------------------------------------------------------------------ ///
///                                FracInput()                               ///
/// ------------------------------------------------------------------------ ///
void FracInput(FRAC &target)
{
    cout << endl;
    cout << "Nhap tu so: "; cin >> target.tu;
    cout << "Nhap mau so: "; cin >> target.mau;
    cout << endl;
}


/// ------------------------------------------------------------------------ ///
///                               FracPrinter()                              ///
/// ------------------------------------------------------------------------ ///
void FracPrinter(FRAC inp)
{
    if (inp.mau == 1)
        cout << inp.tu;
    
    else if (inp.tu == 0)
        cout << 0;

    else
        cout << inp.tu << "/" << inp.mau;
}


/// ------------------------------------------------------------------------ ///
///                              FracSimplify()                              ///
/// ------------------------------------------------------------------------ ///
void FracSimplify(FRAC &inp)
{
    int ucln;
    ucln = __gcd(inp.tu, inp.mau);

    inp.tu /= ucln;
    inp.mau /= ucln;
}


/// -------------------------------------------------------------------------- ///
///                                DivEqualize()                               ///
/// -------------------------------------------------------------------------- ///
void DivEqualize(FRAC inp_1, FRAC inp_2, FRAC &res_1, FRAC &res_2)
{
    res_1.tu = inp_1.tu * inp_2.mau;
    res_2.tu = inp_2.tu * inp_1.mau;

    res_1.mau = inp_1.mau * inp_2.mau;
    res_2.mau = res_1.mau;
}


/// -------------------------------------------------------------------------- ///
///                                 FracCalc()                                 ///
/// -------------------------------------------------------------------------- ///
FRAC FracCalc(FRAC inp_1, FRAC inp_2, char mode)
{
    FRAC res;

    switch (mode)
    {
        case '+': DivEqualize(inp_1, inp_2, inp_1, inp_2); res.tu = inp_1.tu + inp_2.tu; res.mau = inp_1.mau; break;
        case '-': DivEqualize(inp_1, inp_2, inp_1, inp_2); res.tu = inp_1.tu - inp_2.tu; res.mau = inp_1.mau; break;

        case '*': res.tu = inp_1.tu * inp_2.tu; res.mau = inp_1.mau * inp_2.mau; break;
        case '/': res.tu = inp_1.tu * inp_2.mau; res.mau = inp_2.tu * inp_1.mau; break;
    }

    FracSimplify(res);

    return res;
}


/// ------------------------------------------------------------------------ ///
///                               FracCompare()                              ///
/// ------------------------------------------------------------------------ ///
FRAC FracCompare(FRAC inp_1, FRAC inp_2, char mode)
{
    FRAC res = F_ZERO;
    float n_1, n_2;

    if (inp_1 == F_ZERO)
        n_1 = 0;
    else
        n_1 = float(inp_1.tu) / float(inp_1.mau);
    
    if (inp_2 == F_ZERO)
        n_2 = 0;
    else
        n_2 = float(inp_2.tu) / float(inp_2.mau);



    switch (mode)
    {
        case 'm':
        {
            if (n_1 < n_2)
                res = inp_1;
            else if (n_1 > n_2)
                res = inp_2;

            break;
        }
        
        case 'M':
        {
            if (n_1 > n_2)
                res = inp_1;
            else if (n_1 < n_2)
                res = inp_2;
                
            break;
        }
    }

    return res;
}