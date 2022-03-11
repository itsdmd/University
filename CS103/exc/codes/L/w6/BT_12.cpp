/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 12 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int ARRAY[MAX_SIZE];



bool IsPerfNum(int);

int ArrayLastPerfPos(ARRAY, int);

void ArrayAppender(ARRAY &, int &);



int main()
{
    ARRAY arr;
    int size;
    
    ArrayAppender(arr, size);

    cout << endl << endl;

    if (ArrayLastPerfPos(arr, size) == -1)
        cout << "Mang khong co so chan";
    
    else
        cout << "So hoan thien dau tien cua mang nam o vi tri thu " << ArrayLastPerfPos(arr, size) + 1;

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
///                                IsPerfNum()                               ///
/// ------------------------------------------------------------------------ ///
bool IsPerfNum(int inp)
{
    int sum = 0;

    for (int i = 1; i < inp; i++)
    {
        if (inp % i == 0)
            sum += i;
    }

    if (inp == sum)
        return true;
    
    else
        return false;
}

/// ------------------------------------------------------------------------ ///
///                            ArrayLastPerfPos()                            ///
/// ------------------------------------------------------------------------ ///
int ArrayLastPerfPos(ARRAY inp, int size)
{
    int res = -1;

    for (int i = 0; i < size; i++)
    {
        if (IsPerfNum(inp[i]))
            res = i;
    }

    return res;
}