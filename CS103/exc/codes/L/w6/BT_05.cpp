/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 05 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int ARRAY[MAX_SIZE];



bool ArrayIsEven(ARRAY, int);

void ArrayAppender(ARRAY &, int &);



int main()
{
    ARRAY arr;
    int size;
    
    ArrayAppender(arr, size);

    cout << endl;
    ArrayIsEven(arr, size) ? cout << "Mang bao gom toan so chan" : cout << "Mang khong bao gom toan so chan";
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
///                               ArrayIsEven()                              ///
/// ------------------------------------------------------------------------ ///
bool ArrayIsEven(ARRAY inp, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (inp[0] % 2 != 0)
            return false;
    }

    return true;
}