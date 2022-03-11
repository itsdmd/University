/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 09 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int ARRAY[MAX_SIZE];



float ArrayFirstPosiVal(ARRAY, int);

void ArrayAppender(ARRAY &, int &);



int main()
{
    ARRAY arr;
    int size;
    
    ArrayAppender(arr, size);

    cout << endl << endl;

    if (ArrayFirstPosiVal(arr, size) == -1)
        cout << "Mang khong co so nguyen duong";
    
    else
        cout << "Gia tri nguyen duong dau tien cua mang la: " << ArrayFirstPosiVal(arr, size);

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
///                            ArrayFirstPosiVal()                           ///
/// ------------------------------------------------------------------------ ///
float ArrayFirstPosiVal(ARRAY inp, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (inp[i] > 0)
            return inp[i];
    }

    return -1;
}
