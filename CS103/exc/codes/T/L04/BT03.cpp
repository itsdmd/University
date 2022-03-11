#include <iostream>
using namespace std;

int main()
{
    double a, b, x;

    cout << "Phuong trinh ax + b = 0" << endl;
    cout << "Nhap 2 so a, b: ";
    cin >> a >> b;

    cout << "x = " << fixed << (-b)/a;
    
    return 0;
}