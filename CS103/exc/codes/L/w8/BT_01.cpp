/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 01 -------------------------------
------------------------------------------------------------------------*/


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

typedef FRAC FRAC_ARR[200];


FRAC FracCompare(FRAC, FRAC, char);

void FracInput(FRAC &), FracPrinter(FRAC), FracSimplify(FRAC &),
     FracArrInput(FRAC_ARR &, int &), FracArrPrinter(FRAC_ARR, int);



int main()
{
    int option, size;
    FRAC_ARR inp;

    cout << endl;
    FracArrInput(inp, size);
    cout << endl;


    FRAC min = inp[0];

    for (int i = 1; i < size; i++)
        min = FracCompare(min, inp[i], 'm');
    
    cout << endl << "Phan so nho nhat trong mang la: ";
    FracPrinter(min);
    cout << endl;
    
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
///                              FracArrInput()                              ///
/// ------------------------------------------------------------------------ ///
void FracArrInput(FRAC_ARR &target, int &size)
{
    do
    {
        cout << endl << "Nhap so phan tu cua mang: ";
        cin >> size;

    } while(size <= 0);

    for (int i = 0; i < size; i++)
    {
        cout << "===== Phan so " << i+1 << " =========";
        FracInput(target[i]);
    }
}


/// ------------------------------------------------------------------------ ///
///                             FracArrPrinter()                             ///
/// ------------------------------------------------------------------------ ///
void FracArrPrinter(FRAC_ARR inp, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << endl << "[" << i+1 << "] = ";
        FracPrinter(inp[i]);
    }

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