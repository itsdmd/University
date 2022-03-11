#include <iostream>
using namespace std;



void PrintFibb(int);



int main()
{
    int inp;

    do
    {
        cout << endl << "Nhap so phan tu dau tien cua day Fibonacci can in: ";
        cin >> inp;

        if (inp <= 0)
        {
            cout << "So nhap vao phai la so nguyen lon hon 0." << endl;
            continue;
        }
    } while (inp <= 0);

    PrintFibb(inp);
    
    return 0;
}



void PrintFibb(int inp)
{
    int pprev = 0, prev = 1, outp = 1;

    cout << endl << "1 ";
    for (int i = 0; i <= inp; i++)
    {
        outp = pprev + prev;
        pprev = prev;
        prev = outp;
        cout << outp << " ";
    }

    cout << endl;
}