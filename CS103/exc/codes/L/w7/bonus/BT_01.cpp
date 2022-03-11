/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 01 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef float ARRAY[MAX_SIZE];



void ArrayAppender(ARRAY &, int &), ArrayPrinter(ARRAY, int), ArrayIncrSorter(ARRAY, int, ARRAY &), IncreArrayElemInsert(ARRAY &, int &), ArrayInserter(ARRAY &, int &, int, int);



int main()
{
    ARRAY arr, res;
    int size;
    
    ArrayAppender(arr, size);

    ArrayIncrSorter(arr, size, res);

    IncreArrayElemInsert(res, size);

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
    cout << endl << "Cac phan tu cua mang la: " << endl;
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
///                           IncreArrayElemInsert()                         ///
/// ------------------------------------------------------------------------ ///
void IncreArrayElemInsert(ARRAY &inp, int &size)
{
    int ins;

    cout << endl << "Gia tri can them vao mang: ";
    cin >> ins;

    if (ins < inp[0])
        ArrayInserter(inp, size, ins, 0);

    else if (inp[size-1] < ins)
        ArrayInserter(inp, size, ins, size);

    else
    {
        for (int i = 1; i < size; i++)
        {
            if (inp[i] <= ins)
            {
                ArrayInserter(inp, size, ins, i+1);
                break;
            }
        }
        
    }
}

/// ------------------------------------------------------------------------ ///
///                              ArrayInserter()                             ///
/// ------------------------------------------------------------------------ ///
void ArrayInserter(ARRAY &inp, int &size, int val, int pos)
{
    for (int i = size; i > pos; i--)
        inp[i] = inp[i-1];
    
    inp[pos] = val;
    size++;
}