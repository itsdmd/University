#include <iostream>
using namespace std;

int ucln(int m, int n)
{
    if (n == 0)                     // Chia hết
    {
        return m;
    }
    
    else
    {
        return ucln(n, m % n);      // Vd:    184 | 23    →    23 | (184 % 23 =) 0    →    0 | 23    →    return 23
    }
}

int main()
{
    int a, b;

    cout << "Nhap 2 so nguyen duong a, b: ";
    cin >> a >> b;
    
    cout << "UCLN cua " << a << " va " << b << " la " << ucln(a, b);
    return 0;
}