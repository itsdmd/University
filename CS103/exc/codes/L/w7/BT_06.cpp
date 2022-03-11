/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 06 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int MATRIX[MAX_SIZE][MAX_SIZE];


int MatrixUpperTriagMaxVal(MATRIX, int, int);

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

    cout << "Gia tri lon nhat trong ma tran tam giac ben tren la: " << MatrixUpperTriagMaxVal(mat, size_x, size_y);
    
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
///                         MatrixUpperTriagMaxVal()                         ///
/// ------------------------------------------------------------------------ ///
int MatrixUpperTriagMaxVal(MATRIX inp, int size_x, int size_y)
{
    if (size_x == 2 || size_y == 2)
        return inp[1][0];
    
    else
    {
        int max = inp[1][0];
        
        for (int i = 0; i < size_y; i++)
        {
            for (int j = i+1; j < size_x; j++)
            {
                if (inp[j][i] > max)
                    max = inp[j][i];
            }
        }
        
        return max;
    }
}