#include <iostream>
#include <cmath>            //? sqrt(), pow()
#include <cstdlib>          //? swap()
using namespace std;



char UpToLowCase(char);

long long MinVal(long long, long long), MaxVal(long long, long long);

void FirstDegreeFnSolver(double, double, int &, double &), SecondDegreeFnSolver(double, double, double, int &, double &, double &),
     Sort_4_Elements(long long &, long long &, long long &, long long &);



/// -------------------------------------------------------------------------- ///
///                                    Menu                                    ///
/// -------------------------------------------------------------------------- ///
void menu()
{
    cout << endl;
    cout << "================================================ Menu ================================================" << endl;
    cout << "1. Doi ki tu hoa sang ki tu thuong                        4. Tim so nho nhat trong 4 so nguyen" << endl;
    cout << "2. Giai phuong trinh bac nhat                             5. Hoan vi 2 so nguyen" << endl;
    cout << "3. Giai phuong trinh bac hai                              6. Sap xep 4 so nguyen theo thu tu tang dan" << endl;
}

/// -------------------------------------------------------------------------- ///
///                                   main()                                   ///
/// -------------------------------------------------------------------------- ///
int main()
{
    int option;

    menu();

    cout << endl << "Nhap ma so (-1 de thoat): ";
    cin >> option;

    while (option < 1 || 6 < option)
    {
        if (option == -1)
            return 0;

        else
        {
            cout << "Lua chon khong hop le." << endl;

            cout << endl << "Nhap ma so (-1 de thoat): ";
            cin >> option;
        }
    }

    cout << endl << "----------[ " << option << " ]----------" << endl;

    switch (option)
    {
        case 1: 
        {
            char inp;
            cout << endl << "Nhap ki tu: ";
            cin >> inp;

            cout << UpToLowCase(inp);
            
            break;
        }

        case 2:
        {
            int _case;
            double in_1, in_2, res;

            cout << endl << "Nhap a, b: ";
            cin >> in_1 >> in_2;
            
            FirstDegreeFnSolver(in_1, in_2, _case, res);

            switch(_case)
            {
                case -1: cout << endl << "Phuong trinh vo nghiem" << endl; break;
                case  0: cout << endl << "Phuong trinh vo so nghiem" << endl; break;
                case  1: cout << endl << "Nghiem cua phuong trinh la " << fixed << res << endl; break;
            }

            break;
        }

        case 3:
        {
            double in_1, in_2, in_3, res_1, res_2;
            int _case;

            cout << endl << "Nhap a, b, c: ";
            cin >> in_1 >> in_2 >> in_3;
            
            SecondDegreeFnSolver(in_1, in_2, in_3, _case, res_1, res_2);

            switch (_case)
            {
            case -1: cout << endl << "Phuong trinh vo so nghiem" << endl; break;
            case  0: cout << endl << "Phuong trinh vo nghiem" << endl; break;
            case  1: cout << endl << "Phuong trinh co mot nghiem: x = " << res_1 << endl; break;
            case  2: cout << endl << "Phuong trinh co hai nghiem: x1 = " << fixed << res_1 << " ;   x2 = " << res_2 << endl; break; 
            }

            break;
        }

        case 4:
        {
            long long _min, _temp, in_1, in_2, in_3, in_4;

            cout << "Nhap vao 4 so nguyen: ";
            cin >> in_1 >> in_2 >> in_3 >> in_4;

            cout << endl << "So nho nhat la: " << fixed << MinVal(in_1, MinVal(in_2, MinVal(in_3, in_4))) << endl;

            break;
        }

        case 5:
        {
            long long in_1, in_2;

            cout << "Nhap 2 so nguyen: ";
            cin >> in_1 >> in_2;

            swap(in_1, in_2);

            cout << endl << "Hoan vi cua 2 so nguyen vua nhap la: " << fixed << in_1 << "    " << in_2 << endl;

            break;
        }

        case 6:
        {
            long long num_1, num_2, num_3, num_4;

            cout << "Nhap vao 4 so nguyen: ";
            cin >> num_1 >> num_2 >> num_3 >> num_4;

            Sort_4_Elements(num_1, num_2, num_3, num_4);

            cout << endl << "Thu tu tang dan cua 4 so nguyen vua nhap la: " << fixed << num_1 << "  " << num_2 << "  " << num_3 << "  " << num_4 << endl;

            break;
        }
    
    }
    
    return 0;
}


/// -------------------------------------------------------------------------- ///
///                               UpToLowCase()                                ///
/// -------------------------------------------------------------------------- ///
char UpToLowCase(char inp)
{
    char outp;
    int code = int(inp);

    if (64 <= code && code <= 90)
    {
        code += 32;
        outp = char(code);
    }
    
    return outp;
}

/// -------------------------------------------------------------------------- ///
///                                  MinVal()                                  ///
/// -------------------------------------------------------------------------- ///
long long MinVal(long long in_1, long long in_2)
{
    if (in_1 < in_2)
        return in_1;

    else
        return in_2;
}

/// -------------------------------------------------------------------------- ///
///                            FirstDegreeFnSolver()                           ///
/// -------------------------------------------------------------------------- ///
void FirstDegreeFnSolver(double in_1, double in_2, int &_case, double &res)
{
    if (in_1 == 0)                      // Vô nghiệm
        _case = 0;

    else if (in_1 == 0 && in_2 == 0)    // Vô số nghiệm
        _case = -1;
    
    else
    {
        _case = 1;
        res = -in_1 / in_2;
    }
}

/// -------------------------------------------------------------------------- ///
///                           SecondDegreeFnSolver()                           ///
/// -------------------------------------------------------------------------- ///
void SecondDegreeFnSolver(double in_1, double in_2, double in_3, int &_case, double &res_1, double &res_2)
{
    if (in_1 == 0 && in_2 ==0 && in_3 == 0)
        _case = -1;

    else if (in_1 == 0 && in_2 ==0)
        _case = 0;

    else if (in_1 == 0)
        _case = 1;

    else if ((in_2*in_2 - 4*in_1*in_3) < 0)
        _case = 0;

    else
        _case = 2;

    
    switch (_case)
    {
        case  1: res_1 = -in_3/in_2; break;
        
        case  2:
        {
            res_1 = (double(-in_2) + sqrt(pow(double(in_2), 2) - (4 * double(in_1) * double(in_3))) ) / (2 * double(in_1));
            res_2 = (double(-in_2) - sqrt(pow(double(in_2), 2) - (4 * double(in_1) * double(in_3))) ) / (2 * double(in_1));

            break;
        }

        default: break;
    }
}

/// -------------------------------------------------------------------------- ///
///                              Sort_4_Elements()                             ///
/// -------------------------------------------------------------------------- ///
void Sort_4_Elements(long long &num_1, long long &num_2, long long &num_3, long long &num_4)
{
    if (num_1 > num_2)
        swap(num_1, num_2);

    if (num_3 > num_4)
        swap(num_3, num_4);

    if (num_1 > num_3)
        swap(num_1, num_3);

    if (num_2 > num_4)
        swap(num_2, num_4);

    if (num_2 > num_3)
        swap(num_2, num_3);
}