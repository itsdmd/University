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

typedef int MATRIX[MAX_SIZE][MAX_SIZE];


int SumOfMatrixEvenElemOnSides(MATRIX, int, int);

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

    cout << "Tong cua cac phan tu chan nam tren bien la: " << SumOfMatrixEvenElemOnSides(mat, size_x, size_y);
    
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
///                       SumOfMatrixEvenElemOnSides()                       ///
/// ------------------------------------------------------------------------ ///
int SumOfMatrixEvenElemOnSides(MATRIX inp, int size_x, int size_y)
{
    int res = 0;

    // Cạnh trên
    for (int i = 0; i < size_x; i++)
    {
        if (inp[i][0] % 2 == 0)
            res += inp[i][0];
    }
    
    // Cạnh phải
    for (int i = 1; i < size_y; i++)
    {
        if (inp[size_x - 1][i] % 2 == 0)
            res += inp[size_x - 1][i];
    }
    
    // Cạnh dưới
    for (int i = (size_x - 2); i >= 0; i--)
    {
        if (inp[i][size_y - 1] % 2 == 0)
            res += inp[i][size_y - 1];
    }
    
    // Cạnh trái
    for (int i = (size_y - 2); i > 0; i--)
    {
        if (inp[0][(size_y - 2)] % 2 == 0)
            res += inp[0][(size_y - 2)];
    }
    

    return res;
}