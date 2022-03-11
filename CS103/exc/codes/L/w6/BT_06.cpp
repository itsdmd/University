/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 06 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int ARRAY[MAX_SIZE];



bool IsPrime(int);

int ArrayPrimeCounter(ARRAY, int);

void ArrayAppender(ARRAY &, int &);



int main()
{
    ARRAY arr;
    int size;
    
    ArrayAppender(arr, size);

    cout << endl << "Mang da nhap bao gom " << ArrayPrimeCounter(arr, size) << " so nguyen to nho hon 100";
    
    return 0;
}


/// ------------------------------------------------------------------------ ///
///                                 IsPrime()                                ///
/// ------------------------------------------------------------------------ ///
bool IsPrime(long long inp)
{
    if (inp < 2)
        return false;
    
    long long checkPnt = 0;
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
///                            ArrayPrimeCounter()                           ///
/// ------------------------------------------------------------------------ ///
int ArrayPrimeCounter(ARRAY inp, int size)
{
    int res = 0;

    for (int i = 0; i < size; i++)
    {
        if (i <= 100 && IsPrime(inp[i]))
            res++;
    }

    return res;
}