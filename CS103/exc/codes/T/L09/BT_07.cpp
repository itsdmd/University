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


FRAC FracCalc(FRAC, FRAC, char), FracCompare(FRAC, FRAC, char);

void FracInput(FRAC &), FracPrinter(FRAC), FracSimplify(FRAC &), FracArrInput(FRAC_ARR &, int &),
     FracArrPrinter(FRAC_ARR, int), FracArrElementSorter(FRAC_ARR, int, char, FRAC_ARR &, int &),DivEqualize(FRAC, FRAC, FRAC &, FRAC &);




void menu()
{
    cout << endl;
    cout << "====================================== Menu ======================================" << endl;
    cout << "1. Rut gon moi phan so trong mang              5. Tim phan so lon nhat trong mang"  << endl;
    cout << "2. Dem so luong phan so am/duong trong mang    6. Sap xep mang tang dan"            << endl;
    cout << "3. Tim phan so duong dau tien trong mang       7. Sap xep mang giam dan"            << endl;
    cout << "4. Tim phan so nho nhat trong mang             8. Nhap/Xuat mang phan so"           << endl;
}

int main()
{
    int option,
        size_1, size_2;
    FRAC_ARR inp_1, inp_2;
    
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
    } while (option < 1 || 8 < option);

    cout << endl;
    FracArrInput(inp_1, size_1);
    cout << endl;


    switch (option)
    {
       case 1:
       {
            for (int i = 0; i < size_1; i++)
                FracSimplify(inp_1[i]);

            cout << endl << "Mang phan so sau khi rut gon la: ";
            FracArrPrinter(inp_1, size_1);
            cout << endl;

            break;
       }

       case 2:
       {
            int pos = 0, neg = 0;

            for (int i = 0; i < size_1; i++)
            {
                if (FracCompare(inp_1[i], F_ZERO, 'M') == inp_1[i])
                    pos++;
                
                else if (FracCompare(inp_1[i], F_ZERO, 'm') == inp_1[i])
                    neg--;
            }

            cout << endl << "Mang co " << pos << " phan so duong va " << neg << " phan so am" << endl;

            break;
       }

       case 3:
       {
            for (int i = 0; i < size_1; i++)
            {
                if (FracCompare(inp_1[i], F_ZERO, 'M') == inp_1[i])
                {
                    cout << endl << "Phan so duong dau tien trong mang la: ";
                    FracPrinter(inp_1[i]);
                    cout << endl;

                    break;
                }
            }

            break;
       }

       case 4:
       {
            FRAC min = inp_1[0];

            for (int i = 1; i < size_1; i++)
                min = FracCompare(min, inp_1[i], 'm');
            
            cout << endl << "Phan so nho nhat trong mang la: ";
            FracPrinter(min);
            cout << endl;

            break;
       }

       case 5:
       {
            FRAC max = inp_1[0];

            for (int i = 1; i < size_1; i++)
                max = FracCompare(max, inp_1[i], 'M');
            
            cout << endl << "Phan so lon nhat trong mang la: ";
            FracPrinter(max);
            cout << endl;

            break;
       }

       case 6:
       {
            FracArrElementSorter(inp_1, size_1, 'i', inp_2, size_2);

            cout << endl << "Mang sau khi duoc sap xep tang dan la: ";
            FracArrPrinter(inp_2, size_2);

            break;
       }

       case 7:
       {
            FracArrElementSorter(inp_1, size_1, 'd', inp_2, size_2);

            cout << endl << "Mang sau khi duoc sap xep giam dan la: ";
            FracArrPrinter(inp_2, size_2);

            break;
       }

       case 8:
       {
           cout << endl << "Mang phan so vua nhap la: ";
           FracArrPrinter(inp_1, size_1);

           break;
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
///                          FracArrElementSorter()                          ///
/// ------------------------------------------------------------------------ ///
void FracArrElementSorter(FRAC_ARR inp, int size_in, char mode, FRAC_ARR &outp, int &size_out)
{
    int cur_pos = 0;

    size_out = size_in;

    for (int i = 0; i < size_in; i++)
        outp[i] = inp[i];

    switch (mode)
    {
        case 'i':                                                       // Increment
        {
            for(int i = 0; i < (size_in - 1); i++)
            {
                for(int j = 0; j < (size_in - i - 1); j++)
                {
                    if(FracCompare(outp[j], outp[j + 1], 'M') == outp[j])
                    {
                        FRAC temp = outp[j];

                        outp[j] = outp[j + 1];
                        outp[j + 1] = temp;
                    }
                }
            }

            break;
        }

        case 'd':                                                       // Decrement
        {
            for (int i = 0; i < size_out; i++)
            {
                for (int j = i + 1; j < size_out; j++)
                {
                    if (FracCompare(outp[i], outp[j], 'm') == outp[i])
                    {
                        FRAC temp = outp[i];

                        outp[i] = outp[j];
                        outp[j] = temp;
                    }
                }
            }

            break;
        }
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