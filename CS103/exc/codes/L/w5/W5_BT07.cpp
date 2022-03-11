/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 07 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>            //? __gcd()
using namespace std;


void FracSimplify(int, int, int &, int &), DivEqualize(int, int, int, int, int &, int &, int &), FracCalc(char),
     MixedToFrac(int, int, int, int &, int &), FracToMixed(int, int, int &, int &, int &), MixedSimplify(int, int, int, int &, int &, int &), MixedCalc(char);


/// -------------------------------------------------------------------------- ///
///                                   menu()                                   ///
/// -------------------------------------------------------------------------- ///
void menu()
{
    cout << endl;
    cout << "======================= Menu =======================" << endl;
    cout << "1. Rut gon hon so                 5. a(b/c) - d(e/f)" << endl;
    cout << "2. Hon so toi gian?               6. a(b/c) * d(e/f)" << endl;
    cout << "3. Dong quy 2 hon so              7. a(b/c) / d(e/f)" << endl;
    cout << "4. a(b/c) + d(e/f)" << endl;
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
    

    int n_1, n_2, t_1, m_1, t_2, m_2;

    switch (mode)
    {
        case 1:
        {
            cout << endl << "Nhap phan nguyen: "; cin >> n_1;
            cout << "Nhap tu so: "; cin >> t_1;
            cout << "Nhap mau so: "; cin >> m_1;

            MixedSimplify(n_1, t_1, t_2, n_2, t_2, m_2);

            cout << endl << "Hon so toi gian cua " << n_1 << "(" << t_1 << "/" << m_1 << ") la: " << n_2 << "(" << t_2 << "/" << m_2 << ")" << endl;

            break;
        }

        case 2:
        {
            cout << endl << "Nhap phan nguyen: "; cin >> n_1;
            cout << "Nhap tu so: "; cin >> t_1;
            cout << "Nhap mau so: "; cin >> m_1;

            MixedSimplify(n_1, t_1, t_2, n_2, t_2, m_2);

            ((n_1 == n_2) && (t_1 == t_2) && (m_1 == m_2)) ? cout << n_1 << "(" << t_1 << "/" << m_1 << ") la hon so toi gian" : cout << n_1 << "(" << t_1 << "/" << m_1 << ") khong phai la hon so toi gian";
            cout << endl;

            break;
        }

        case 3:
        {
            cout << endl << "Nhap phan nguyen cua hon so 1: "; cin >> n_1;
            cout << "Nhap tu so cua hon so 1: "; cin >> t_1;
            cout << "Nhap mau so cua hon so 1: "; cin >> m_1;
            cout << endl << "Nhap hon nguyen cua hon so 2: "; cin >> n_2;
            cout << "Nhap tu so cua hon so 2: "; cin >> t_2;
            cout << "Nhap mau so cua hon so 2: "; cin >> m_2;

            if (m_1 == m_2)
                cout << n_1 << "(" << t_1 << "/" << m_1 << ") va " << n_2 << "(" << t_2 << "/" << m_2 << ") co chung mau so." << endl;
            
            else
            {
                MixedToFrac(n_1, t_1, m_1, t_1, m_1);
                MixedToFrac(n_2, t_2, m_2, t_2, m_2);
                DivEqualize(t_1, m_1, t_2, m_2, t_1, t_2, m_1);
                
                //! Do đã quy đồng nên chỉ xài m_1
                FracToMixed(t_1, m_1, n_1, t_1, m_1);
                FracToMixed(t_2, m_1, n_2, t_2, m_1);

                cout << "2 hon so sau khi quy dong la: " << n_1 << "(" << t_1 << "/" << m_1 << ") va " << n_2 << "(" << t_2 << "/" << m_1 << ")" << endl;
            }

            break;
        }

        case 4: MixedCalc('+'); break;

        case 5: MixedCalc('-'); break;

        case 6: MixedCalc('*'); break;

        case 7: MixedCalc('/'); break;
    }
    
    return 0;
}



/// -------------------------------------------------------------------------- ///
///                               FracSimplify()                               ///
/// -------------------------------------------------------------------------- ///
void FracSimplify(int a, int b, int &res_a, int &res_b)
{
    res_a = a / __gcd(a, b);
    res_b = b / __gcd(a, b);
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

/// -------------------------------------------------------------------------- ///
///                                MixedToFrac()                               ///
/// -------------------------------------------------------------------------- ///
void MixedToFrac(int n, int t, int m, int &f_t, int &f_m)
{
    f_t = t + n*m;
    f_m = m;
}

/// -------------------------------------------------------------------------- ///
///                                FracToMixed()                               ///
/// -------------------------------------------------------------------------- ///
void FracToMixed(int f_t, int f_m, int &n, int &t, int &m)
{
    n = f_t / f_m;
    t = f_t % f_m;
    m = f_m;
}

/// -------------------------------------------------------------------------- ///
///                               MixedSimplify()                              ///
/// -------------------------------------------------------------------------- ///
void MixedSimplify(int n, int t, int m, int &res_n, int &res_t, int &res_m)
{
    MixedToFrac(n, t, m, res_t, res_m);
    FracSimplify(res_t, res_m, res_t, res_m);
    FracToMixed(res_t, res_m, res_n, res_t, res_m);
}

/// -------------------------------------------------------------------------- ///
///                                 MixedCalc()                                ///
/// -------------------------------------------------------------------------- ///
void MixedCalc(char mode)
{
    int n_1, t_1, m_1, n_2, t_2, m_2;

    cout << endl << "Nhap phan nguyen cua hon so 1: "; cin >> n_1;
    cout << "Nhap tu so cua hon so 1: "; cin >> t_1;
    cout << "Nhap mau so cua hon so 1: "; cin >> m_1;
    cout << endl << "Nhap hon nguyen cua hon so 2: "; cin >> n_2;
    cout << "Nhap tu so cua hon so 2: "; cin >> t_2;
    cout << "Nhap mau so cua hon so 2: "; cin >> m_2;

    int temp_n_2 = n_2, temp_t_2 = t_2, temp_m_2 = m_2,
        res_n, res_t, res_m;

    cout << n_1 << "(" << t_1 << "/" << m_1 << ") ";

    MixedToFrac(n_1, t_1, m_1, t_1, m_1);
    MixedToFrac(n_2, t_2, m_2, t_2, m_2);

    switch (mode)
    {
        case '+': cout << "+"; DivEqualize(t_1, m_1, t_2, m_2, t_1, t_2, res_m); res_t = t_1 + t_2; break;
        case '-': cout << "-"; DivEqualize(t_1, m_1, t_2, m_2, t_1, t_2, res_m); res_t = t_1 - t_2; break;

        case '*': cout << "*"; res_t = t_1 * t_2; res_m = m_1 * m_2; break;
        case '/': cout << "/"; res_t = t_1 * m_2; res_m = t_2 * m_1; break;
    }

    FracSimplify(res_t, res_m, res_t, res_m);
    FracToMixed(res_t, res_m, res_n, res_t, res_m);

    cout << temp_n_2 << " (" << temp_t_2 << "/" << temp_m_2 << ") = " << res_n << "(" << res_t << "/" << res_m << ")";
}