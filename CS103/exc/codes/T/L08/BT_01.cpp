#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int MATRIX[MAX_SIZE][MAX_SIZE];


void MatrixAppender(MATRIX &, int, int), MatrixPrinter(MATRIX, int , int),
     MatAddSub(MATRIX, int, int, MATRIX, int, int, MATRIX &, int &, int &, char, bool &), MatMul(MATRIX, int, int, MATRIX, int, int, MATRIX &, int &, int &, bool &);



int main()
{
    bool valid;
    char mode;
    int x_1, y_1, x_2, y_2, x_res, y_res;
    MATRIX mat_1, mat_2, mat_res;

    cout << endl << "===== Ma tran 1 =====";
    do
    {
        cout << endl << "Nhap kich thuoc ma tran (x, y): ";
        cin >> x_1 >> y_1;
    } while (x_1 <= 0 || y_1 <= 0);
    cout << endl;
    MatrixAppender(mat_1, x_1, y_1);
    
    cout << endl << endl << "===== Ma tran 2 =====";
    do
    {
        cout << endl << "Nhap kich thuoc ma tran (x, y): ";
        cin >> x_2 >> y_2;
    } while (x_2 <= 0 || y_2 <= 0);
    cout << endl;
    MatrixAppender(mat_2, x_2, y_2);
    
    cout << endl << endl << "Nhap phep toan (+ - *): ";
    cin >> mode;


    switch (mode)
    {
        case '*':
        {
            MatMul(mat_1, x_1, y_1, mat_2, x_2, y_2, mat_res, x_res, y_res, valid);

            if (valid)
            {
                cout << endl << endl << "Tich cua hai ma tran la: " << endl;
                MatrixPrinter(mat_res, x_res, y_res);
                cout << endl;
            }

            else
                cout << endl << "Khong the nhan 2 ma tran" << endl;

            break;
        }

        default:
        {
            MatAddSub(mat_1, x_1, y_1, mat_2, x_2, y_2, mat_res, x_res, y_res, mode, valid);
            
            if (valid)
            {
                cout << endl << endl;
                (mode == '+') ? cout << "Tong" :  cout << "Hieu";
                cout << " cua hai ma tran la: " << endl;

                MatrixPrinter(mat_res, x_res, y_res);
                cout << endl;
            }

            else
                cout << endl << "Khong the <<";
                (mode == '+') ? cout << "cong" :  cout << "tru";
                cout << " 2 ma tran" << endl;
        }
    }
    
    return 0;
}

/// ------------------------------------------------------------------------ ///
///                             MatrixAppender()                             ///
/// ------------------------------------------------------------------------ ///
void MatrixAppender(MATRIX &inp, int x_1, int y_1)
{
    for (int y = 0; y < MAX_SIZE; y++)
    {
        for (int x = 0; x < MAX_SIZE; x++)
        {
            inp[x][y] = 0;
        }
        
    }
    
    for (int y = 0; y < y_1; y++)
    {
        for (int x = 0; x < x_1; x++)
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
void MatrixPrinter(MATRIX inp, int x_1, int y_1)
{
    for (int y = 0; y < y_1; y++)
    {
        for (int x = 0; x < x_1; x++)
        {
            cout << inp[x][y] << "\t";
        }
        
        cout << endl;
    }
}

/// ------------------------------------------------------------------------ ///
///                                MatAddSub()                               ///
/// ------------------------------------------------------------------------ ///
void MatAddSub(MATRIX inp_1, int x_1, int y_1, MATRIX inp_2, int x_2, int y_2, MATRIX &res, int &x_res, int &y_res, char mode, bool &valid)
{
    (x_1 != x_2 || y_1 != y_2) ? valid = false : valid = true;
    
    if (valid)
    {
        for (int y = 0; y < y_1; y++)
        {
            for (int x = 0; x < x_1; x++)
            {
                switch (mode)
                {
                    case '+': res[x][y] = inp_1[x][y] + inp_2[x][y]; break;
                    case '-': res[x][y] = inp_1[x][y] - inp_2[x][y]; break;
                }
            }
        }
    }
}

/// ------------------------------------------------------------------------ ///
///                                 MatMul()                                 ///
/// ------------------------------------------------------------------------ ///
void MatMul(MATRIX inp_1, int x_1, int y_1, MATRIX inp_2, int x_2, int y_2, MATRIX &res, int &x_res, int &y_res, bool &valid)
{
    (x_1 != y_2) ? valid = false : valid = true;

    if (valid)
    {
        x_res = x_2; y_res = y_1;
        int cur_res_row = 0, cur_res_col = 0;
        
        for (int row_1 = 0; row_1 < y_1; row_1++)
        {
            for (int col_2 = 0; col_2 < x_2; col_2++)
            {
                for (int col_1 = 0; col_1 < x_1; col_1++)
                {
                    res[cur_res_col][cur_res_row] += inp_1[col_1][row_1] * inp_2[col_2][col_1];
                }
                
                cur_res_col++;
            }

            cur_res_col = 0;
            cur_res_row++;
        }
    }
}