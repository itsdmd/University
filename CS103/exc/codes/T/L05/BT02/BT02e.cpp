#include <iostream>
using namespace std;

int main()
{
    long long n, temp = 1, res = 1;
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
            for (int j = 1; j <= i; j++)
            {
                temp *= j;
            }
            res += temp;
        }

        cout << endl << "S5 = " << fixed << res << endl;
    }
    
    return 0;
}