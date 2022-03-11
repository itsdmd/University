/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 04 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef float ARRAY[MAX_SIZE];



int ArrayMinPos(ARRAY, int);

void ArrayAppender(ARRAY &, int &);



int main()
{
    ARRAY arr;
    int size;
    
    ArrayAppender(arr, size);

    cout << endl << "Gia tri nho nhat trong mang nam o vi tri: " << ArrayMinPos(arr, size);
    
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
///                              ArrayMinPos()                               ///
/// ------------------------------------------------------------------------ ///
int ArrayMinPos(ARRAY inp, int size)
{
    float cur = inp[0];
    int pos = 0;

    for (int i = 1; i < size; i++)
    {
        if (inp[i] < cur)
            pos = i;
    }

    return pos;
}