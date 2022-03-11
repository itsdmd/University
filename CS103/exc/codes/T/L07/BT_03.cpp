#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int ARRAY[MAX_SIZE];


void ArrayAppender(ARRAY &, int &);

int ArrayElemCondCounter(ARRAY, int, char);


int main()
{
    int size;
    ARRAY arr;

    ArrayAppender(arr, size);

    cout << endl << "Mang co " << ArrayElemCondCounter(arr, size, 'a') << " phan tu chia het cho 4 nhung khong chia het cho 5";
    cout << endl << "Mang co " << ArrayElemCondCounter(arr, size, 'b') << " so nguyen to";
    
    return 0;
}


/// ------------------------------------------------------------------------ ///
///                                 IsPrime()                                ///
/// ------------------------------------------------------------------------ ///
bool IsPrime(int inp)
{
    if (inp < 2)
        return false;
    
    int checkPnt = 0;
    checkPnt = inp/2;

    for(int i = 2; i <= checkPnt; i++)
    {  
        if(inp % i == 0)
        {  
            return false;
        }
    }

    return true;
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
///                          ArrayElemCondCounter()                          ///
/// ------------------------------------------------------------------------ ///
int ArrayElemCondCounter(ARRAY inp, int size, char mode)
{
    int res = 0;

    switch (mode)
    {
        case 'a':
        {
            for (int i = 0; i < size; i++)
            {
                if ((inp[i] % 4 == 0) && (inp[i] % 5 != 0))
                {
                    res++;
                }
            }

            break;
        }

        case 'b':
        {
            for (int i = 0; i < size; i++)
            {
                if (IsPrime(inp[i]))
                {
                    res++;
                }
            }

            break;
        }
    }

    return res;
}