#include <iostream>
using namespace std;

int main()
{
    long long a, b, n, res = 0;

    cout << "Nhap a, b, n (a, b < n): ";
    cin >> a >> b >> n;

    if (a >= n || b >= n)
    {
        cout << "Gia tri nhap vao khong hop le." << endl;
        main();
    }

    else
    {
        for (int i = 1; i < n; i++)
        {
            if ((i % a == 0) && (i % b != 0))
            {
                res += i;
            }
        }

        cout << endl << "S = " << res << endl;
    }

    
    return 0;
}