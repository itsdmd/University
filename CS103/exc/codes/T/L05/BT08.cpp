#include <iostream>
using namespace std;

int main()
{
    int n, pprev = 0, prev = 1, outp = 1;

    cout << endl << "Nhap so phan tu dau tien cua day Fibonacci can in: ";
    cin >> n;

    if (n <= 1)
    {
        cout << endl << "So nhap vao phai la so nguyen lon hon 0.";
        main();
    }

    else
    {
        cout << 1 << endl;
        for (int i = 1; i < n; i++)
        {
            outp = pprev + prev;
            pprev = prev;
            prev = outp;

            cout << outp << endl;
        }
    }
    
    return 0;
}

// print fibbonaci