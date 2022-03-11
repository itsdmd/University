/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 08 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef float ARRAY[MAX_SIZE];



void ArrayAppender(ARRAY &, int &), ArrayPrinter(ARRAY, int), ArrayIncrSorter(ARRAY, int, ARRAY &);



int main()
{
    ARRAY arr, res;
    int size;
    
    ArrayAppender(arr, size);

    ArrayIncrSorter(arr, size, res);

    ArrayPrinter(res, size);
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
    cout << endl << "Cac phan tu cua mang sau khi sap xep tang dan la: " << endl;
    for (int i = 0; i < size; i++)
        cout << "a[" << i << "] = " << inp[i] << endl;
}

/// ------------------------------------------------------------------------ ///
///                             ArrayIncrSorter()                            ///
/// ------------------------------------------------------------------------ ///
void ArrayIncrSorter(ARRAY inp, int size, ARRAY &outp)
{
    for (int i = 0; i < size; i++)
        outp[i] = inp[i];

    for(int i = 0; i < (size - 1); i++)
    {
        for(int j = 0; j < (size - i - 1); j++)
        {
            if(outp[j] > outp[j + 1])
            {
                int temp = outp[j];

                outp[j] = outp[j + 1];
                outp[j + 1] = temp;
            }
        }
    }
}