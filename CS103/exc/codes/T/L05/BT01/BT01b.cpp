#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long inp, sqrted;

    cout << endl << "Nhap so nguyen duong: ";
    cin >> inp;

    if (inp < 0)
    {
        cout << endl << "So nhap vao khong hop le." << endl;
        main();
    }

    else
    {
        sqrted = sqrt(inp);
        (sqrted*sqrted == inp) ? (cout << endl << inp << " la so chinh phuong cua " << sqrted << "." << endl) : (cout << endl << inp << " khong phai la so chinh phuong." << endl);
    }

    return 0;
}