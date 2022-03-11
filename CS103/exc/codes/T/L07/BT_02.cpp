#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int ARRAY[MAX_SIZE];


void ArrayAppender(ARRAY &, int &);

bool ArrayChecker(ARRAY, int, char);



int main()
{
    char mode;
    int size;
    ARRAY arr;

    ArrayAppender(arr, size);

    cout << endl;
    ArrayChecker(arr, size, 'e') ? cout << "Mang la mang toan chan" : cout << "Mang khong phai la mang toan chan";

    cout << endl;
    ArrayChecker(arr, size, 'p') ? cout << "Mang bao gom toan so nguyen to" : cout << "Mang khong phai la mang toan so nguyen to";

    cout << endl;
    ArrayChecker(arr, size, 'i') ? cout << "Mang la mang tang dan" : cout << "Mang khong phai la mang tang dan";
    
    return 0;
}

/// ------------------------------------------------------------------------ ///
///                              ArrayAppender()                             ///
/// ------------------------------------------------------------------------ ///
void ArrayAppender(ARRAY &inp, int &size)
{
    do
    {
        cout << endl << "Nhap so phan tu cua mang: ";
        cin >> size;

    } while (size < 1);

    for (int i = 0; i < size; i++)
    {
        cout << endl << "Nhap gia tri thu " << i+1 << ": ";
        cin >> inp[i];
    }
}

/// ------------------------------------------------------------------------ ///
///                              ArrayChecker()                              ///
/// ------------------------------------------------------------------------ ///
bool ArrayChecker(ARRAY inp, int size, char mode)
{
    switch (mode)
    {
        case 'e':       //? Even
        {
            for (int i = 0; i < size; i++)
            {
                if ((inp[i] % 2) != 0)
                    return false;
            }

            break;
        }

        case 'p':       //? Prime
        {
            for(int i = 2; i <= (inp[i]/2); i++)
            {
                if (inp[i] < 2)
                    return false;
                
                if(inp[i] % i == 0)
                {  
                    return false;
                }
            }

            break;
        }

        case 'i':       //? Increment
        {
            for (int i = 0; i < (size - 1); i++)
            {
                if (inp[i] > inp[i+1])
                    return false;
            }

            break;
        }
    }

    return true;
}