/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 20 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef float ARRAY[MAX_SIZE];



void ArrayAppender(ARRAY &, int &), ArrayPrinter(ARRAY, int),
     ArrayIncrSorter(ARRAY, int, ARRAY &), ArrayMerger(ARRAY, int, ARRAY, int, ARRAY &, int &);



int main()
{
    ARRAY arr_1, arr_2, res;
    int size_1, size_2, size_res;
    
    cout << endl << "===== Nhap mang thu 1 =====" << endl;
    ArrayAppender(arr_1, size_1);
    
    cout << endl << "===== Nhap mang thu 2 =====" << endl;
    ArrayAppender(arr_2, size_2);

    ArrayMerger(arr_1, size_1, arr_2, size_2, res, size_res);

    ArrayIncrSorter(res, size_res, res);

    ArrayPrinter(res, size_res);
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

/// ------------------------------------------------------------------------ ///
///                               ArrayMerger()                              ///
/// ------------------------------------------------------------------------ ///
void ArrayMerger(ARRAY inp_1, int size_1, ARRAY inp_2, int size_2, ARRAY &outp, int &size_outp)
{
    size_outp = size_1 + size_2;

    for (int i = 0; i < size_1; i++)
        outp[i] = inp_1[i];
    
    for (int i = size_1; i < size_outp; i++)
        outp[i] = inp_2[i - size_1];
}