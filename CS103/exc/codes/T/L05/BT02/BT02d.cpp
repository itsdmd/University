#include <iostream>
using namespace std;

int main()
{
    long long n, res = 1;
    cout << endl << "Nhap so nguyen duong n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Gia tri nhap vao khong hop le." << endl;
        main();
    }

    else
    {
        for (int i = 1; i <= n; i++)
        {
            res *= i;
        }

        cout << endl << "S4 = " << fixed << res << endl;
    }
    
    return 0;
}