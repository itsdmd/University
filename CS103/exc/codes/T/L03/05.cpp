#include <iostream>
#include <iomanip>
using namespace std;

double a, b;

int main()
{
    cout << "Nhap 2 so a, b: ";
    cin >> a >> b;
    cout << "a + b = " << fixed << a + b << endl;
    
    return 0;
}