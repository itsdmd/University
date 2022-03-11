#include <iostream>
using namespace std;

int main()
{
    long long n;

    cout << endl << "Nhap so nguyen duong n: ";
    cin >> n;

    if (n <= 1)
    {
        cout << "Gia tri nhap vao khong hop le." << endl;
        main();
    }

    else
    {
        cout << endl << "Cac so nguyen to tu 0 den " << n << " la:" << endl << "2 ";     //? Để đỡ phải tạo trường hợp đặc biệt cho 2

        for (int i = 2; i <= n; ++i)
        {
            int j = 2;

            for (; j <= (i-1); j++)
            {
                if(i % j == 0)
                    break;
            }

            if (i == j && j != 2)
                cout << fixed << i << " ";
        }

        cout << endl;
    }

    
    return 0;
}