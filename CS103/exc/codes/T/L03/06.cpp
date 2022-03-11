#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

unsigned long long n, p;
string _name;

int nhap(string mode)
{
    cout << endl;
    
    if (mode == "name")
    {
        cout << "Nhap ten san pham: ";
        getline(cin, _name);
    }

    else if (mode == "n")
    {
        cout << "Nhap so luong: ";
        cin >> n;

        if (n < 0)
        {
            cout << "So luong khong duoc nho hon 0" << endl;
            nhap(mode);
        }
    }

    else if (mode == "p")
    {
        cout << "Nhap don gia: ";
        cin >> p;

        if (p < 0)
        {
            cout << "Don gia khong duoc nho hon 0" << endl;
            nhap(mode);
        }
    }

    return 0;
}

int main()
{
    nhap("name");
    nhap("n");
    nhap("p");
    cout << endl << "Ten san pham: " << _name << endl << "So tien phai tra: " << fixed << n * p << endl << "Thue gia tri gia tang phai tra: " << fixed << setprecision(3) << double(n) * double(p) * 0.1 << endl;
    
    return 0;
}