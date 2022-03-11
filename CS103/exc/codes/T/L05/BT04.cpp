#include <iostream>
using namespace std;

int main()
{
    int n, res = 2;     //? 2 là số nguyên tố đầu tiên và vòng lặp bên dưới bỏ qua số 2 (giảm độ phức tạp về điều kiện xét)

    cout << endl << "Nhap so nguyen duong n (0 < n < 50): ";
    cin >> n;

    if (n < 0)
    {
        cout << "Gia tri nhap vao khong hop le." << endl;
        main();
    }

    else
    {
        for (int i = 2; i <= n; ++i)
        {
            int j = 2;

            for (; j <= (i-1); j++)
            {
                if(i % j == 0)
                    break;
            }

            if (i == j && j != 2)
                res += i;
        }

        cout << endl << "S = " << res << endl;
    }

    
    return 0;
}