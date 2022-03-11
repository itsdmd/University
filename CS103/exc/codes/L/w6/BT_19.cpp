/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 19 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int ARRAY[MAX_SIZE];



void ArrayAppender(ARRAY &, int &), ArrayPrinter(ARRAY, int), ArrayOddIncrSorter(ARRAY, int, ARRAY &);



int main()
{
    ARRAY arr, res;
    int size;
    
    ArrayAppender(arr, size);

    ArrayOddIncrSorter(arr, size, res);

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
    cout << endl << "Cac phan tu cua mang sau khi sap xep cac so le tang dan la: " << endl;
    for (int i = 0; i < size; i++)
        cout << "a[" << i << "] = " << inp[i] << endl;
}

/// ------------------------------------------------------------------------ ///
///                            ArrayOddIncrSorter()                          ///
/// ------------------------------------------------------------------------ ///
void ArrayOddIncrSorter(ARRAY inp, int size, ARRAY &outp)
{
    int cur_pos = 0;

    for (int i = 0; i < size; i++)
        outp[i] = inp[i];

    for(int i = 0; i < (size - 1); i++)
    {
        for(int j = 0; j < (size - i - 1); j++)
        {
            if (outp[j] % 2 == 0)
                continue;
            
            int next_odd_pos = -1;

            for (int k = (j + 1); k < (size - j); k++)
            {
                if (outp[k] % 2 != 0)
                {
                    next_odd_pos = k;
                    break;
                }
            }

            if (next_odd_pos == -1)
                break;

            else if (outp[j] > outp[next_odd_pos])
            {
                int temp = outp[j];

                outp[j] = outp[next_odd_pos];
                outp[next_odd_pos] = temp;
            }
        }
    }
}