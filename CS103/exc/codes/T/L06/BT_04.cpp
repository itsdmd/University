#include <iostream>
using namespace std;



int USCLN(long long, long long);



int main()
{
    long long a, b;

    cout << endl << "Nhap 2 so nguyen a, b: ";
    cin >> a >> b;

    cout << endl << "Uoc so chung lon nhat cua " << a << " va " << b << " la: " << USCLN(a, b) << endl;
    
    return 0;
}



int USCLN(long long a, long long b)
{
    int res;

    if (b > a)
        swap(a, b);

    for (int i = 2; i <= b; i++)
    {
        if (a % i == 0 && b % i ==0)
            res = i;
    }

    return res;
}