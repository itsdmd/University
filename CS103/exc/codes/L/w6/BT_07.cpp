/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 07 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef float ARRAY[MAX_SIZE];



bool IsPrime(int);

float ArraySumOfNegs(ARRAY, int);

void ArrayAppender(ARRAY &, int &);



int main()
{
    ARRAY arr;
    int size;
    
    ArrayAppender(arr, size);

    cout << endl << "Tong cua cac so am trong mang la: " << ArraySumOfNegs(arr, size) << endl;
    
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
///                             ArraySumOfNegs()                             ///
/// ------------------------------------------------------------------------ ///
float ArraySumOfNegs(ARRAY inp, int size)
{
    float res = 0;

    for (int i = 0; i < size; i++)
    {
        if (inp[i] < 0)
            res += inp[i];
    }

    return res;
}