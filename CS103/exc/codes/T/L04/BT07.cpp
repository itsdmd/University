#include <iostream>
using namespace std;

long FeeCalc(long);

int main()
{
    long long n;

    cout << endl << "Nhap quang duong (km): ";
    cin >> n;

    while (n <= 0)
    {
        cout << "Du lieu nhap vao phai lon hon 0." << endl;
        
        cout << endl << "Nhap quang duong (km): ";
        cin >> n;
    }

    cout << "Tong tien phai tra la: " << fixed << FeeCalc(n) << endl;
        
    return 0;
}



long FeeCalc(long S)
{
    const int   p1 = 15000, p2 = 13500, p3 = 11000,             // Mức giá
                s1 = 1, s2 = 5, s4 = 6, s4 = 120;               // Mốc quãng đường
    
    double p;

    if (S <= s1)
    {
        p = p1;
    }

    else if (S <= s2)
    {
        p = p1 + ((S-s1) * p2);
    }

    else if (S <= s4)
    {
        p = p1 + ((s2-s1) * p2) + ((S-s4) * p3);
    }

    else
    {
        p = (p1 + ((s2-s1) * p2) + ((S-s4) * p3)) - ((p1 + ((s2-s2) * p2) + ((S-s4) * p3)) * 0.1);
    }

    return p;
}
