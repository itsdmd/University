/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------   Bài tập   -------------------------------
------------------------------------------------------------------------*/


#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef float ARRAY[MAX_SIZE];
typedef int MATRIX[MAX_SIZE][MAX_SIZE];


bool MatrixCheckDiag(MATRIX, int, int), MatIsSymmMainDiag(MATRIX, int, int), MatIsSymmViceDiag(MATRIX, int, int);

int SumOfMatrixEvenElemOnSides(MATRIX, int, int), MatrixUpperTriagMaxVal(MATRIX, int, int), MatrixLowerTriagMinVal(MATRIX, int, int);

void MatrixAppender(MATRIX &, int, int), MatrixPrinter(MATRIX, int, int), ArrayElementSorter(ARRAY, int, ARRAY &, int &);



/// ------------------------------------------------------------------------ ///
///                                  menu()                                  ///
/// ------------------------------------------------------------------------ ///
void menu()
{
    cout << endl;
    cout << "==================================== Menu ====================================" << endl;
    cout << "1. Duong cheo ma tran co tinh tang dan?    5. Tong cua cac phan tu chan nam tren bien" << endl;
    cout << "2. Ma tran doi xung qua duong cheo chinh?  6. Gia tri lon nhat trong ma tran tam giac ben tren" << endl;
    cout << "3. Ma tran doi xung qua duong cheo phu?    7. Gia tri nho nhat trong ma tran tam giac ben duoi" << endl;
    cout << "4. Sap xep duong cheo chinh tang dan" << endl;
}


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

    cout << endl;

    int option;
    long long inp;
    
    menu();
    
    do
    {
        if (option == -1)
            return 0;
    
        else
        {
            cout << endl << "Nhap ma so (-1 de thoat): ";
            cin >> option;
        }
    } while (option < 1 || 6 < option);

    cout << endl;

    switch (option)
    {
        case 1:
        {
            if ((size_y == 1) || (size_x == 1))
                cout << "Khong the xac dinh";
            
            else
                MatrixCheckDiag(mat, size_x, size_y) ? cout << "Duong cheo chinh ma tran co tinh tang dan" : cout << "Duong cheo chinh ma tran khong co tinh tang dan";


            break;
        }

        case 2:
        {
            if ((size_y == 1) || (size_x == 1))
                cout << "Khong the xac dinh";
            
            else
                MatIsSymmMainDiag(mat, size_x, size_y) ? cout << "Ma tran doi xung qua duong cheo chinh" : cout << "Ma tran khong doi xung qua duong cheo chinh";


            break;
        }

        case 3:
        {
            if ((size_y == 1) || (size_x == 1))
                cout << "Khong the xac dinh";
            
            else
                MatIsSymmViceDiag(mat, size_x, size_y) ? cout << "Ma tran doi xung qua duong cheo phu" : cout << "Ma tran khong doi xung qua duong cheo phu";
            

            break;
        }

        case 4:
        {
            (size_x <= size_y) ? diag_size = size_x : diag_size = size_y;

            for (int i = 0; i < diag_size; i++)
                diag[i] = mat[i][i];
            
            ArrayElementSorter(diag, diag_size, diag, diag_size);
            
            for (int i = 0; i < diag_size; i++)
                mat[i][i] = diag[i];

            cout << endl << "Ma tran sau khi sap xep duong cheo chinh tang dan: " << endl;
            MatrixPrinter(mat, size_x, size_y);


            break;
        }

        case 5: cout << "Tong cua cac phan tu chan nam tren bien la: " << SumOfMatrixEvenElemOnSides(mat, size_x, size_y); break;

        case 6: cout << "Gia tri lon nhat trong ma tran tam giac ben tren la: " << MatrixUpperTriagMaxVal(mat, size_x, size_y); break;

        case 7: cout << "Gia tri nho nhat trong ma tran tam giac ben duoi la: " << MatrixLowerTriagMinVal(mat, size_x, size_y); break;
    }

    
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

/// ------------------------------------------------------------------------ ///
///                            MatIsSymmMainDiag()                           ///
/// ------------------------------------------------------------------------ ///
bool MatIsSymmMainDiag(MATRIX inp, int size_x, int size_y)
{
    int counter;

    (size_x < size_y) ? counter = size_x : counter = size_y;

    for (int i = 0; i < counter; i++)
    {
        for (int j = 0; j < counter; j++)
        {
            if (inp[i][j] != inp[j][i])
                return false;
        }
    }

    return true;
}

/// ------------------------------------------------------------------------ ///
///                            MatIsSymmViceDiag()                           ///
/// ------------------------------------------------------------------------ ///
bool MatIsSymmViceDiag(MATRIX inp, int size_x, int size_y)
{
    int counter;

    (size_x < size_y) ? counter = size_x : counter = size_y;

    for (int i = (counter - 2); i >= 0; i--)
    {
        for (int j = (counter - 2); j >= 0; j--)
        {
            if (inp[counter - j][counter - i] != inp[counter - i][counter - j])
                return false;
        }
    }

    return true;
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

/// ------------------------------------------------------------------------ ///
///                         MatrixLowerTriagMinVal()                         ///
/// ------------------------------------------------------------------------ ///
int MatrixLowerTriagMinVal(MATRIX inp, int size_x, int size_y)
{
    if (size_x == 2 || size_y == 2)
        return inp[0][1];
    
    else
    {
        int min = inp[0][1];
        
        for (int i = 2; i < size_y; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (inp[j][i] < min)
                    min = inp[j][i];
            }
        }
        
        return min;
    }
}