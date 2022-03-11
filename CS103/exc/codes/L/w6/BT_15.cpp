/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 15 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int ARRAY[MAX_SIZE];



bool IsPrime(int);

int ArrayFirstPrimeVal(ARRAY, int);

void ArrayAppender(ARRAY &, int &);



int main()
{
    ARRAY arr;
    int size;
    
    ArrayAppender(arr, size);

    cout << endl << endl;

    if (ArrayFirstPrimeVal(arr, size) == -1)
        cout << "Mang khong co so nguyen to";
    
    else
        cout << "So nguyen to dau tien cua mang la " << ArrayFirstPrimeVal(arr, size);

    cout << endl;
    
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
///                           ArrayFirstPrimeVal()                           ///
/// ------------------------------------------------------------------------ ///
int ArrayFirstPrimeVal(ARRAY inp, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (IsPrime(inp[i]))
            return inp[i];
    }

    return -1;
}