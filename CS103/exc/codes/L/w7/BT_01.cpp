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

typedef int MATRIX[MAX_SIZE][MAX_SIZE];


bool MatrixCheckDiag(MATRIX, int, int);

void MatrixAppender(MATRIX &, int, int);



int main()
{
    int size_x, size_y;
    MATRIX mat;
    
    cout << endl << "===== Ma tran =====";
    do
    {
        cout << endl << "Nhap kich thuoc ma tran (x, y): ";
        cin >> size_x >> size_y;
    } while (size_x <= 0 || size_y <= 0);
    cout << endl;
    MatrixAppender(mat, size_x, size_y);

    cout << endl;

    if ((size_y == 1) || (size_x == 1))
        cout << "Khong the xac dinh";
    
    else
        MatrixCheckDiag(mat, size_x, size_y) ? cout << "Duong cheo chinh ma tran co tinh tang dan" : cout << "Duong cheo chinh ma tran khong co tinh tang dan";
    
    cout << endl;
    
    return 0;
}


/// ------------------------------------------------------------------------ ///
///                             MatrixAppender()                             ///
/// ------------------------------------------------------------------------ ///
void MatrixAppender(MATRIX &inp, int size_x, int size_y)
{
    for (int y = 0; y < MAX_SIZE; y++)
    {
        for (int x = 0; x < MAX_SIZE; x++)
        {
            inp[x][y] = 0;
        }
        
    }
    
    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
        {
            cout << "[" << x << "][" << y << "] = ";
            cin >> inp[x][y];
        }
        
        cout << endl;
    }
}


/// ------------------------------------------------------------------------ ///
///                             MatrixCheckDiag()                            ///
/// ------------------------------------------------------------------------ ///
bool MatrixCheckDiag(MATRIX inp, int size_x, int size_y)
{
    int counter;

    (size_x < size_y) ? counter = size_x : counter = size_y;

    for (int i = 0; i < counter - 1; i++)
    {
        if (inp[i][i] > inp[i+1][i+1])
            return false;
    }

    return true;
}