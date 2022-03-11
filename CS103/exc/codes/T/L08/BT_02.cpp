#include <iostream>
#include <stdio.h> 
using namespace std;



#define MAX_SIZE 200

typedef int MATRIX[MAX_SIZE][MAX_SIZE];


bool IsIncreMatrixRow(MATRIX, int, int);

int MatrixMaxSumRow(MATRIX, int, int);

void MatrixAppender(MATRIX &, int, int), MatrixSpiralPrinter(MATRIX, int, int);



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



    cout << endl << endl << "Dong co tong gia tri cac phan tu lon nhat la: " << MatrixMaxSumRow(mat, size_x, size_y) + 1;

    bool hasIncre = false;
    for (int i = 0; i < size_y; i++)
    {
        if (IsIncreMatrixRow(mat, size_x, i))
        {
            hasIncre = true;
            break;
        }
    }

    if (hasIncre)
    {
        cout << endl << "Dong ";
        for (int i = 0; i < size_y; i++)
        {
            if (IsIncreMatrixRow(mat, size_x, i))
            {
                if (i != 0)
                    cout << ", ";
                
                cout << i+1;
            }
        }
        cout << " co gia tri tang dan.";
    }

    else
        cout << endl << "Ma tran khong co dong nao co gia tri tang dan";

    cout << endl << "Xuat mang theo chieu xoan oc: ";
    MatrixSpiralPrinter(mat, size_x, size_y);
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
///                             MatrixMaxSumRow()                            ///
/// ------------------------------------------------------------------------ ///
int MatrixMaxSumRow(MATRIX inp, int size_x, int size_y)
{
    int res_row = 0, res_row_sum = 0;

    for (int i = 0; i < size_x; i++)
        res_row_sum += inp[i][0];

    if (size_y > 1)
    {
        for (int row = 0; row < size_y; row++)
        {
            int cur_row_sum = 0;

            for (int col = 0; col < size_x; col++)
            {
                cur_row_sum += inp[col][row];
            }

            if (cur_row_sum > res_row_sum)
                res_row = row;
        }
    }

    return res_row;
}

/// ------------------------------------------------------------------------ ///
///                             IsIncreMatrixRow                             ///
/// ------------------------------------------------------------------------ ///
bool IsIncreMatrixRow(MATRIX inp, int size_x, int row)
{
    for (int col = 1; col < size_x; col++)
        if (inp[col-1][row] > inp[col][row])
            return false;
    
    return true;
}

/// ------------------------------------------------------------------------ ///
///                           MatrixSpiralPrinter()                          ///
/// ------------------------------------------------------------------------ ///
void MatrixSpiralPrinter(MATRIX inp, int size_x, int size_y)
{ 
    int cur_col = 0, cur_row = 0;

    while(cur_col < size_y && cur_row < size_x)
    {
        for(int i = cur_row; i < size_x; i++)
            cout << inp[i][cur_col] << " ";

        cur_col++;


        for(int i = cur_col; i < size_y; i++)
            cout << inp[size_x-1][i] << " ";
        
        size_x--;


        if(cur_col < size_y)
        {
            for(int i = size_x - 1; i >= 0; i--)
            cout << inp[i][size_y-1] << " ";
            
            size_y--;
        }

        if(cur_row < size_x)
        {
            for(int i = size_y - 1; i >= cur_col; i--)
                cout << inp[cur_row][i] << " ";
            
            cur_row++;
        }
    }
} 