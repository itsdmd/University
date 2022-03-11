/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 17 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef float ARRAY[MAX_SIZE];



float ArrayClosestValToX(ARRAY, int, float);

void ArrayAppender(ARRAY &, int &);



int main()
{
    ARRAY arr;
    int size;
    float x;
    
    ArrayAppender(arr, size);

    cout << endl << "Nhap x: ";
    cin >> x;

    cout << endl << endl << "So gan " << x << " nhat trong mang la: " << ArrayClosestValToX(arr, size, x);

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
///                           ArrayClosestValToX()                           ///
/// ------------------------------------------------------------------------ ///
float ArrayClosestValToX(ARRAY inp, int size, float x)
{
    float res = inp[0], mindif = abs(inp[0] - x);

    for (int i = 1; i < size; i++)
    {
        if (abs(inp[i] - x) < mindif)
            res = inp[i];
    }

    return res;
}