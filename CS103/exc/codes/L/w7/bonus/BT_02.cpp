/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 02 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef float ARRAY[MAX_SIZE];



void ArrayAppender(ARRAY &, int &), ArrayPrinter(ARRAY, int), ArrayNegValDel(ARRAY &, int &);



int main()
{
    ARRAY arr;
    int size;
    
    ArrayAppender(arr, size);

    ArrayNegValDel(arr, size);

    ArrayPrinter(arr, size);
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
///                              ArrayPrinter()                              ///
/// ------------------------------------------------------------------------ ///
void ArrayPrinter(ARRAY inp, int size)
{
    cout << endl << "Cac phan tu cua mang la: " << endl;
    for (int i = 0; i < size; i++)
        cout << "a[" << i << "] = " << inp[i] << endl;
}

/// ------------------------------------------------------------------------ ///
///                             ArrayNegValDel()                             ///
/// ------------------------------------------------------------------------ ///
void ArrayNegValDel(ARRAY &inp, int &size)
{
    for (int pos = 0; pos < size; pos++)
    {
        if (inp[pos] < 0)
        {
            for (int i = pos; i < size; i++)
                inp[i] = inp[i+1];

            size--;
        }
    }
}