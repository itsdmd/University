/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 08 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



void ComplexCalc(char), ComplexCalc(char, double, double, double, double, double &, double &);



/// -------------------------------------------------------------------------- ///
///                                    Menu                                    ///
/// -------------------------------------------------------------------------- ///
void menu()
{
    cout << endl;
    cout << "=============================== Menu ===============================" << endl;
    cout << "1. Tong 2 so phuc                  4. Thuong 2 so phuc" << endl;
    cout << "2. Hieu 2 so phuc                  5. Luy thua bac n cua mot so phuc" << endl;
    cout << "3. Tich 2 so phuc" << endl;
}

int main()
{
    menu();

    int mode;

    do
    {
        cout << endl << "Nhap ma so (-1 de thoat): ";
        cin >> mode;

        if (mode == -1)
        {
            return 0;
        }
    } while (mode < 1 || 5 < mode);

    cout << endl << "========== [" << mode << "] ==========";


    double r_1, i_1, r_2, i_2;

    switch (mode)
    {
        case 1: ComplexCalc('+'); break;
        case 2: ComplexCalc('-'); break;
        case 3: ComplexCalc('*'); break;
        case 4: ComplexCalc('/'); break;
        case 5:
        {
            double r, i, n, res_r, res_i;

            cout << endl << "Nhap phan thuc: "; cin >> r;
            cout << "Nhap phan ao: "; cin >> i;
            
            do
            {
                cout << "Nhap bac n: "; cin >> n;
            } while (n < 1);

            res_r = r; res_i = i;

            for (double k = 1; k < n; k++)
            {
                ComplexCalc('*', r, i, res_r, res_i, res_r, res_i);
            }

            
            (i >= 0) ? cout << endl << "(" << r << " + " << i << "i)" : cout << endl << "(" << r << " - " << -i << "i)";
            cout << "^" << n << " = ";
            (res_i >= 0) ? cout << res_r << " + " << res_i << "i " : cout << res_r << " - " << -res_i << "i ";
            cout << endl;
        }
    }
    
    return 0;
}



/// -------------------------------------------------------------------------- ///
///                                ComplexCalc()                               ///
/// -------------------------------------------------------------------------- ///
void ComplexCalc(char mode)
{
    double r_1, i_1, r_2, i_2, res_r, res_i;

    cout << endl << "Nhap phan thuc cua so phuc 1: "; cin >> r_1;
    cout << "Nhap phan ao cua so phuc 1: "; cin >> i_1;
    cout << endl << "Nhap phan thuc cua so phuc 2: "; cin >> r_2;
    cout << "Nhap phan ao cua so phuc 2: "; cin >> i_2;

    (i_1 >= 0) ? cout << endl << "(" << r_1 << " + " << i_1 << "i) " : cout << endl << "(" << r_1 << " - " << -i_1 << "i) ";


    switch (mode)
    {
        case '+': cout << "+"; res_r = r_1 + r_2; res_i = i_1 + i_2; break;
        case '-': cout << "-"; res_r = r_1 - r_2; res_i = i_1 - i_2; break;
        case '*': cout << "*"; res_r = (r_1*r_2 - i_1*i_2); res_i = (r_1*i_2 + r_2*i_1); break;
        case '/': cout << "/"; res_r = (r_1*r_2 + i_1*i_2) / (r_2*r_2 + i_2*i_2); res_i = (r_1*r_2 - i_1*i_2) / (r_2*r_2 + i_2*i_2); break;
    }


    (i_2 >= 0) ? cout << " (" << r_2 << " + " << i_2 << "i)" : cout << " " << r_2 << " - " << -i_2 << "i)";
    (res_i >= 0) ? cout << " = " << res_r << " + " << res_i << "i" : cout << " = " << res_r << " - " << -res_i << "i";
    cout << endl;
}

/// --------------------------- No prompt overload --------------------------- ///
void ComplexCalc(char mode, double r_1, double i_1, double r_2, double i_2, double &res_r, double &res_i)
{
    switch (mode)
    {
        case '+': res_r = r_1 + r_2; res_i = i_1 + i_2; break;
        case '-': res_r = r_1 - r_2; res_i = i_1 - i_2; break;
        case '*': res_r = (r_1*r_2 - i_1*i_2); res_i = (r_1*i_2 + r_2*i_1); break;
        case '/': res_r = (r_1*r_2 + i_1*i_2) / (r_2*r_2 + i_2*i_2); res_i = (r_1*r_2 - i_1*i_2) / (r_2*r_2 + i_2*i_2); break;
    }
}