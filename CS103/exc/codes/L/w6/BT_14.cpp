/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 14 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int ARRAY[MAX_SIZE];



int ArrayMinPosiPos(ARRAY, int);

void ArrayAppender(ARRAY &, int &);



int main()
{
    ARRAY arr;
    int size;
    
    ArrayAppender(arr, size);

    cout << endl << endl;

    if (ArrayMinPosiPos(arr, size) == -1)
        cout << "Mang khong co so nguyen duong";
    
    else
        cout << "So nguyen duong nho nhat cua mang nam o vi tri thu " << ArrayMinPosiPos(arr, size) + 1;

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
///                             ArrayMinPosiPos()                            ///
/// ------------------------------------------------------------------------ ///
int ArrayMinPosiPos(ARRAY inp, int size)
{
    int pos =-1;

    for (int i = 0; i < size; i++)
    {
        if (inp[i] > 0)
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
    {
        for (int i = 0; i < size; i++)
        {
            if (inp[i] > 0 && inp[i] < pos)
                pos = i;
        }
    }

    return pos;
}