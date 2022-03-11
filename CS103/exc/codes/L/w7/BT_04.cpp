/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 04 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef float ARRAY[MAX_SIZE];
typedef int MATRIX[MAX_SIZE][MAX_SIZE];


void MatrixAppender(MATRIX &, int, int), MatrixPrinter(MATRIX, int, int), ArrayElementSorter(ARRAY, int, ARRAY &, int &);



int main()
{
    int size_x, size_y, diag_size;
    ARRAY diag;
    MATRIX mat;

    cout << endl << "===== Ma tran =====";
    do
    {
        cout << endl << "Nhap kich thuoc ma tran (x, y): ";
        cin >> size_x >> size_y;
    } while (size_x <= 0 || size_y <= 0);
    cout << endl;
    MatrixAppender(mat, size_x, size_y);

    (size_x <= size_y) ? diag_size = size_x : diag_size = size_y;

    for (int i = 0; i < diag_size; i++)
        diag[i] = mat[i][i];
    
    ArrayElementSorter(diag, diag_size, diag, diag_size);
    
    for (int i = 0; i < diag_size; i++)
        mat[i][i] = diag[i];

    cout << endl << "Ma tran sau khi sap xep duong cheo chinh tang dan: " << endl;
    MatrixPrinter(mat, size_x, size_y);
    
    
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
///                              MatrixPrinter()                             ///
/// ------------------------------------------------------------------------ ///
void MatrixPrinter(MATRIX inp, int size_x, int size_y)
{
    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
        {
            cout << inp[x][y] << "\t";
        }
        
        cout << endl;
    }
}

/// ------------------------------------------------------------------------ ///
///                           ArrayElementSorter()                           ///
/// ------------------------------------------------------------------------ ///
void ArrayElementSorter(ARRAY inp, int size_in, ARRAY &outp, int &size_out)
{
    int cur_pos = 0;

    size_out = size_in;

    for (int i = 0; i < size_in; i++)
        outp[i] = inp[i];

    for(int i = 0; i < (size_in - 1); i++)
    {
        for(int j = 0; j < (size_in - i - 1); j++)
        {
            if(outp[j] > outp[j + 1])
            {
                int temp = outp[j];

                outp[j] = outp[j + 1];
                outp[j + 1] = temp;
            }
        }
    }
}