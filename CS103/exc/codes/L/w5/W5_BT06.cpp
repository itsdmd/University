/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 06 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>            //? __gcd()
using namespace std;


void FracSimplify(int, int, int &, int &), DivEqualize(int, int, int, int, int &, int &, int &), FracCalc(char);


/// -------------------------------------------------------------------------- ///
///                                   menu()                                   ///
/// -------------------------------------------------------------------------- ///
void menu()
{
    cout << endl;
    cout << "======================= Menu =======================" << endl;
    cout << "1. Rut gon phan so                  5. (a/b) - (c/d)" << endl;
    cout << "2. Phan so toi gian?                6. (a/b) * (c/d)" << endl;
    cout << "3. Dong quy 2 phan so               7. (a/b) / (c/d)" << endl;
    cout << "4. (a/b) + (c/d)" << endl;
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
    } while (mode < 1 || 7 < mode);

    cout << endl << "========== [" << mode << "] ==========";
    

    int t_1, m_1, t_2, m_2;

    switch (mode)
    {
        case 1:
        {
            cout << endl << "Nhap tu so: "; cin >> t_1;
            cout << "Nhap mau so: "; cin >> m_1;

            FracSimplify(t_1, m_1, t_2, m_2);

            cout << endl << "Phan so toi gian cua " << t_1 << "/" << m_1 << " la: " << t_2 << "/" << m_2 << endl;

            break;
        }

        case 2:
        {
            cout << endl << "Nhap tu so: "; cin >> t_1;
            cout << "Nhap mau so: "; cin >> m_1;

            FracSimplify(t_1, m_1, t_2, m_2);

            ((t_1 == t_2) && (m_1 == m_2)) ? cout << t_1 << "/" << m_1 << " la phan so toi gian" : cout << t_1 << "/" << m_1 << " khong phai la phan so toi gian";
            cout << endl;

            break;
        }

        case 3:
        {
            cout << endl << "Nhap tu so cua phan so 1: "; cin >> t_1;
            cout << "Nhap mau so cua phan so 1: "; cin >> m_1;
            cout << endl << "Nhap tu so cua phan so 2: "; cin >> t_2;
            cout << "Nhap mau so cua phan so 2: "; cin >> m_2;

            if (m_1 == m_2)
                cout << t_1 << "/" << m_1 << " va " << t_2 << "/" << m_2 << " co chung mau so." << endl;
            
            else
            {
                DivEqualize(t_1, m_1, t_2, m_2, t_1, t_2, m_1);

                cout << "2 phan so sau khi quy dong la: " << t_1 << "/" << m_1 << " va " << t_2 << "/" << m_1 << endl;
            }

            break;
        }

        case 4: FracCalc('+'); break;

        case 5: FracCalc('-'); break;

        case 6: FracCalc('*'); break;

        case 7: FracCalc('/'); break;
    }
    
    return 0;
}



/// -------------------------------------------------------------------------- ///
///                               FracSimplify()                               ///
/// -------------------------------------------------------------------------- ///
void FracSimplify(int a, int b, int &s_a, int &s_b)
{
    s_a = a / __gcd(a, b);
    s_b = b / __gcd(a, b);
}

/// -------------------------------------------------------------------------- ///
///                                DivEqualize()                               ///
/// -------------------------------------------------------------------------- ///
void DivEqualize(int t_1, int m_1, int t_2, int m_2, int &res_t_1, int &res_t_2, int &res_m)
{
    res_t_1 = t_1 * m_2;
    res_t_2 = t_2 * m_1;

    res_m = m_1 * m_2;
}

/// -------------------------------------------------------------------------- ///
///                                 FracCalc()                                 ///
/// -------------------------------------------------------------------------- ///
void FracCalc(char mode)
{
    int t_1, m_1, t_2, m_2;

    cout << endl << "Nhap tu so cua phan so 1: "; cin >> t_1;
    cout << "Nhap mau so cua phan so 1: "; cin >> m_1;
    cout << endl << "Nhap tu so cua phan so 2: "; cin >> t_2;
    cout << "Nhap mau so cua phan so 2: "; cin >> m_2;

    int temp_t_2 = t_2, temp_m_2 = m_2,
        res_t, res_m;

    cout << "(" << t_1 << "/" << m_1 << ") ";

    switch (mode)
    {
        case '+': cout << "+"; DivEqualize(t_1, m_1, t_2, m_2, t_1, t_2, res_m); res_t = t_1 + t_2; break;
        case '-': cout << "-"; DivEqualize(t_1, m_1, t_2, m_2, t_1, t_2, res_m); res_t = t_1 - t_2; break;

        case '*': cout << "*"; res_t = t_1 * t_2; res_m = m_1 * m_2; break;
        case '/': cout << "/"; res_t = t_1 * m_2; res_m = t_2 * m_1; break;
    }

    FracSimplify(res_t, res_m, res_t, res_m);

    cout << " (" << temp_t_2 << "/" << temp_m_2 << ") = " << res_t << "/" << res_m;
}