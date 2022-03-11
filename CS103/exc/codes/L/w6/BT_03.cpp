/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 03 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef float ARRAY[MAX_SIZE];



float ArrayMax(ARRAY, int);

void ArrayAppender(ARRAY &, int &);



int main()
{
    ARRAY arr;
    int size;
    float max;
    
    ArrayAppender(arr, size);

    cout << endl << "Gia tri lon nhat trong mang la: " << ArrayMax(arr, size);
    
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
///                                ArrayMax()                                ///
/// ------------------------------------------------------------------------ ///
float ArrayMax(ARRAY inp, int size)
{
    float res = inp[0];

    for (int i = 1; i < size; i++)
    {
        if (inp[i] > res)
            res = inp[i];
    }

    return res;
}