#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    long long n;
    double res = 0;
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
            res += 1 / double(i);
        }

        cout << endl << "S3 = " << fixed << setprecision(6) << res << endl;
    }
    
    return 0;
}