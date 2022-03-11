#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

double r;

int main()
{
    cout << endl << "Nhap ban kinh duong tron: ";
    cin >> r;

    if (r <= 0)
    {
        cout << "Ban kinh duong tron phai lon hon 0." << endl;
        main();
    }

    else
    {
        cout << endl << "Chu vi: " << fixed << setprecision(3) << 2 * M_PI * r << endl << "Dien tich: " << fixed << setprecision(3) << M_PI * pow(r, 2) << endl;
    }
    
    return 0;
}