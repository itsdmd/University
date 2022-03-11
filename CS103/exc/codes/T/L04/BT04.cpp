#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c, x1, x2;
    int _case;

    cout << endl << "Phuong trinh a*(x^2) + bx + c = 0" << endl;
    cout << "Nhap 3 so a, b, c: ";
    cin >> a >> b >> c;

    if (a == 0 && b == 0)
    {
        cout << "Phuong trinh co vo so nghiem.";
        main();
    }

    else if ( (pow(b, 2) - (4*a*c)) == 0 )
    {
        x1 = ( (-b) + sqrt(pow(b, 2) - (4*a*c)) ) / (2*a);
        cout << "Nghiem cua phuong trinh la: x = " << fixed << x1;
    }

    else if ( (pow(b, 2) - 4*a*c) > 0 )
    {
        x1 = ( (-b) + sqrt(pow(b, 2) - (4*a*c)) ) / (2*a);
        x2 = ( (-b) - sqrt(pow(b, 2) - (4*a*c)) ) / (2*a);

        cout << "Nghiem cua phuong trinh la: x1 = " << fixed  << x1 << "; x2 = " << x2;
    }

    else if ( (pow(b, 2) - (4*a*c)) < 0 )
    {
        cout << "Phuong trinh khong co nghiem thuc." << endl;
        main();
    }
    
    return 0;
}