#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n, res = 0;
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
            res += pow(i, 2);
        }

        cout << endl << "S2 = " << fixed << res << endl;
    }
    
    return 0;
}