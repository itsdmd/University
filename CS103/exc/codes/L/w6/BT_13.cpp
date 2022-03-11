/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 13 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int ARRAY[MAX_SIZE];



int ArrayMinPosiVal(ARRAY, int);

void ArrayAppender(ARRAY &, int &);



int main()
{
    ARRAY arr;
    int size;
    
    ArrayAppender(arr, size);

    cout << endl << endl;

    if (ArrayMinPosiVal(arr, size) == -1)
        cout << "Mang khong co so nguyen duong";
    
    else
        cout << "So nguyen duong nho nhat trong mang la: " << ArrayMinPosiVal(arr, size);

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
///                             ArrayMinPosiVal()                            ///
/// ------------------------------------------------------------------------ ///
int ArrayMinPosiVal(ARRAY inp, int size)
{
    int min =-1;

    for (int i = 0; i < size; i++)
    {
        if (inp[i] > 0)
        {
            min = inp[i];
            break;
        }
    }

    if (min != -1)
    {
        for (int i = 0; i < size; i++)
        {
            if (inp[i] > 0 && inp[i] < min)
                min = inp[i];
        }
    }

    return min;
}