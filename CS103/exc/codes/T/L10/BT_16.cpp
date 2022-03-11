#include <iostream>
#include <cmath>
using namespace std;


long long* GetDigits(long long, int);

void Sorter(long long *, int);


int main()
{
    long long inp;
    int k;

    cout << endl;
    do
    {
        cout << "Nhap so chu so (0 < k < 11): ";
        cin >> k;
    } while (k < 1 || 10 < k);

    cout << endl;
    do
    {
        cout << "Nhap so nguyen duong: ";
        cin >> inp;
    } while (inp < pow(10, k-1) || pow(10, k) <= inp);


    long long *digits = GetDigits(inp, k);
    Sorter(digits, k);

    cout << endl << endl << "So " << inp << " sau khi sap xep cac chu so tang dan la: ";
    for (int i = 0; i < k; i++)
        cout << digits[i];
    
    cout << endl;

    
    return 0;
}


/// ------------------------------------------------------------------------ ///
///                                 GetDigits                                ///
/// ------------------------------------------------------------------------ ///
long long *GetDigits(long long inp, int size)
{
    long long *container = new long long[size];

    for (int i = 0; i < size; i++)
    {
        container[i] = inp % 10;
        inp /= 10;
    }

    return container;
}

/// ------------------------------------------------------------------------ ///
///                                 Sorter()                                 ///
/// ------------------------------------------------------------------------ ///
void Sorter(long long *inp, int size)
{
    for(int i = 0; i < (size - 1); i++)
    {
        for(int j = 0; j < (size - i - 1); j++)
        {
            if(inp[j] > inp[j + 1])
            {
                long long temp = inp[j];

                inp[j] = inp[j + 1];
                inp[j + 1] = temp;
            }
        }
    }
}