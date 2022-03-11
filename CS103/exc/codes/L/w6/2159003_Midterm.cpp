#include <iostream>
using namespace std;



// Global vars


bool IsUglyNum(int);

long long SequentialSum_For(int), SequentialSum_While(int), SequentialSum_Recursion(int);

void BuffaloProblem(int, int &, int &, int &);




/* -------------------------------------------------------------------------- */
/*                                    Menu                                    */
/* -------------------------------------------------------------------------- */
void menu()
{
    cout << endl;
    cout << "================ Menu ================" << endl;
    cout << "1. S = 1 + 2 + 3 + ... + n" << endl;
    cout << "2. Kiem tra 1 so ca phai so xau xi khong" << endl;
    cout << "3. Bai toan tram trau tram co" << endl;
}

int main()
{
    int mode;

    menu();

    do
    {
        cout <<  endl << "Nhap ma so: ";
        cin >> mode;
    } while (mode < 1 && 3 < mode);

    cout << endl;

    switch (mode)
    {
        case 1:
        {
            int inp;

            do
            {
                cout << "Nhap so nguyen duong n: ";
                cin >> inp;
            } while (inp < 1);

            cout << SequentialSum_For(inp) << endl << SequentialSum_While(inp) << endl << SequentialSum_Recursion(inp);

            break;
        }

        case 2:
        {
            int inp;

            do
            {
                cout << "Nhap so nguyen duong n: ";
                cin >> inp;
            } while (inp < 1);

            cout << endl;
            IsUglyNum(inp) ? cout << inp << " la so xau xi." : cout << inp << " khong phai la so xau xi";

            break;
        }

        case 3:
        {
            int d, n, g;

            BuffaloProblem(1, d, n, g);
            cout << endl << "Nghiem thu nhat: Trau dung = " << d << " ;  Trau nam = " << n << " ;  Trau gia = " << g;
            BuffaloProblem(2, d, n, g);
            cout << endl << "Nghiem thu hai: Trau dung = " << d << " ;  Trau nam = " << n << " ;  Trau gia = " << g;
            BuffaloProblem(3, d, n, g);
            cout << endl << "Nghiem thu ba: Trau dung = " << d << " ;  Trau nam = " << n << " ;  Trau gia = " << g;
            BuffaloProblem(4, d, n, g);
            cout << endl << "Nghiem thu tu: Trau dung = " << d << " ;  Trau nam = " << n << " ;  Trau gia = " << g;
            BuffaloProblem(5, d, n, g);
            cout << endl << "Nghiem thu nam: Trau dung = " << d << " ;  Trau nam = " << n << " ;  Trau gia = " << g;
        }

    }


    return 0;
}




long long SequentialSum_For(int n)
{
    long long res = 0;

    for (int i = 1; i <= n; i++)
        res += i;
    
    return res;
}

long long SequentialSum_While(int n)
{
    long long res = 0;
    int i = 1;

    while (i <= n)
    {
        res += i;
        i++;
    }

    return res;
}

long long SequentialSum_Recursion(int n)
{
    if (n != 0)
        return (n + SequentialSum_Recursion(n-1));
    
    return 0;
}


bool IsUglyNum(int inp)
{
    if (inp == 1 || inp == 2 || inp == 3 || inp == 5)
        return true;

    else if ((inp % 2) == 0 && IsUglyNum(inp/2))
        return true;

    else if ((inp % 3) == 0 && IsUglyNum(inp/3))
        return true;
    
    else if ((inp % 5) == 0 && IsUglyNum(inp/5))
        return true;


    return false;
}


void BuffaloProblem(int num, int &res_d, int &res_n, int &res_g)
{
    int counter = 0;

    for (int d = 0; d < 100; d++)
    {
        for (int n = 0; n < 100; n++)
        {
            for (int g = 0; g < 100; g++)
            {
                if ((float(5*d) + float(3*n) + float(g/3) == 100) && (d+n+g) == 100 && (g % 3 == 0))
                    counter++;
                
                if (counter == num)
                {
                    res_d = d;
                    res_n = n;
                    res_g = g;

                    break;
                }
            }
            
            if (counter == num) break;
        }
        
        if (counter == num) break;
    }
}