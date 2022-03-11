#include <iostream>
using namespace std;

int main()
{
    char c;
    int n;

    cout << endl << "Nhap 1 chu cai: ";
    cin >> c;

    n = int(c);

    if (n >= 65 && n <= 90)
    {
        n += 32;
        cout << char(n);
    }

    else if (n >= 97 && n <= 122)
    {
        n -= 32;
        cout << char(n);
    }

    else
    {
        cout << "Ki tu nhap vao khong hop le." << endl;
        main();
    }
    
    return 0;
}