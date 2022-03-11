#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int ARRAY[MAX_SIZE];

void ArrayAppender(ARRAY &, int &);

int ArrayElemLastPos(ARRAY, int, int), ArrayFirstPrimePos(ARRAY, int),
    ArrayMin(ARRAY, int, char);



int main()
{
    int size, mode;
    ARRAY arr;

    ArrayAppender(arr, size);

    cout << endl;
    cout << "===================== Menu =====================" << endl;
    cout << "1. Tim vi tri cuoi cung cua x trong mang"<< endl;
    cout << "2. Vi tri so nguyen to dau tien trong mang neu co"<< endl;
    cout << "3. Tim so nho nhat trong mang"<< endl;
    cout << "4. Tim so nguyen duong nho nhat trong mang"<< endl;

    do
    {
    cout << endl << "Nhap ma so: ";
    cin >> mode;
    } while (mode < 1 && 4 < mode);

    cout << endl << "==========[" << mode << "]=========="; 

    switch(mode)
    {
        case 1:
        {
            int to_find;

            cout << endl << "Nhap so can tim: ";
            cin >> to_find;

            if (ArrayElemLastPos(arr, size, to_find) != -1)
                cout << "So " << to_find << " cuoi cung nam o vi tri thu " << ArrayElemLastPos(arr, size, to_find) + 1 << " trong mang";
            
            else
                cout <<  "So " << to_find << " khong xuat hien trong mang";

            cout << endl;

            break;
        }

        case 2:
        {
            if (ArrayFirstPrimePos(arr, size) != -1)
                cout << "So nguyen to dau tien trong mang la " << ArrayFirstPrimePos(arr, size);
            
            else
                cout <<  "Khong co so nguyen to nao xuat hien trong mang";

            cout << endl;

            break;
        }

        case 3:
        {
            cout << endl << "So nho nhat trong mang la " << ArrayMin(arr, size, 'a') << endl;

            break;
        }
        
        case 4:
        {
            if (ArrayMin(arr, size, 'p') == 0)
                cout << endl << "Mang khong co so nguyen duong" << endl;
            
            else
                cout << endl << "So nguyen duong nho nhat trong mang la " << ArrayMin(arr, size, 'p') << endl;

            break;
        }
    }
    
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
///                            ArrayElemLastPos()                            ///
/// ------------------------------------------------------------------------ ///
int ArrayElemLastPos(ARRAY inp, int size, int to_find)
{
    int pos = -1;

    for (int i = 0; i < size; i++)
    {
        if (inp[i] == to_find)
            pos = i;
    }
    
    return pos;
}

/// ------------------------------------------------------------------------ ///
///                           ArrayFirstPrimePos()                           ///
/// ------------------------------------------------------------------------ ///
int ArrayFirstPrimePos(ARRAY inp, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (IsPrime(inp[i]))
            return i;
    }
    
    return -1;
}

/// ------------------------------------------------------------------------ ///
///                                ArrayMin()                                ///
/// ------------------------------------------------------------------------ ///
int ArrayMin(ARRAY inp, int size, char mode)
{
    int res;

    switch (mode)
    {
        case 'a':                                       // All
        {
            res = inp[0];

            for (int i = 0; i < size; i++)
            {
                if (inp[i] < res)
                    res = inp[i];
            }
            
            break;
        }

        case 'p':                                       // Positive
        {
            res = 0;

            for (int i = 0; i < size; i++)
            {
                if (inp[i] < res && inp[i] > 0)
                    res = inp[i];
            }

            break;
        }
    }

    return res;
}

