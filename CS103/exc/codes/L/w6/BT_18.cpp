/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 18 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef float ARRAY[MAX_SIZE];



float ArrayFirstGT2021Val(ARRAY, int);

void ArrayAppender(ARRAY &, int &);



int main()
{
    ARRAY arr;
    int size;
    
    ArrayAppender(arr, size);

    cout << endl << endl;

    if (ArrayFirstGT2021Val(arr, size) == -1)
        cout << "Mang khong co so nao lon hon 2021";
    
    else
        cout << "So dau tien lon hon 2021 cua mang la " << ArrayFirstGT2021Val(arr, size);

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
///                           ArrayFirstGT2021Val()                          ///
/// ------------------------------------------------------------------------ ///
float ArrayFirstGT2021Val(ARRAY inp, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (inp[i] > 2021)
            return inp[i];
    }

    return -1;
}