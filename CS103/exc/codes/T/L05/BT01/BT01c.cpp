#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long inp;
    bool prime = true;

    cout << "Nhap so nguyen duong: ";
    cin >> inp;

    if (inp < 0)
    {
        cout << endl << "So nhap vao khong hop le." << endl;
        main(); 
    }

    else if (inp == 0 || inp == 1)
    {
        cout << inp << " khong phai la so nguyen to." << endl;
    }

    else
    {
        for(int i = 2; i <= sqrt(inp); i++)
        {
            if(inp % i == 0)
            {
                prime = false;
                break;
            }
        }

        prime ? cout << inp << " la so nguyen to." << endl : cout << inp << " khong phai la so nguyen to." << endl;
    }

  return 0;
}