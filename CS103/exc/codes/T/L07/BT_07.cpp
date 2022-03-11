#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int ARRAY[MAX_SIZE];


bool ArraysAreEqual(ARRAY, int, ARRAY, int);

void ArrayAppender(ARRAY &, int &);



int main()
{
    int mode, size_1, size_2;
    ARRAY arr_1, arr_2;


    cout << endl << "========== Mang 1 ==========" << endl;
    ArrayAppender(arr_1, size_1);
    
    cout << endl << endl << "========== Mang 2 ==========" << endl;
    ArrayAppender(arr_2, size_2);

    cout << endl << endl << "=> ";
    ArraysAreEqual(arr_1, size_1, arr_2, size_2) ? cout << "Hai mang bang nhau" : cout << "Hai mang khong bang nhau";
    cout << endl;
    
    return 0;
}


/// -------------------------------------------------------------------------- ///
///                               ArrayAppender()                              ///
/// -------------------------------------------------------------------------- ///
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

/// -------------------------------------------------------------------------- ///
///                              ArraysAreEqual()                              ///
/// -------------------------------------------------------------------------- ///
bool ArraysAreEqual(ARRAY inp_1, int size_1, ARRAY inp_2, int size_2)
{
    if (size_1 != size_2)
        return false;
    
    else
    {
        for (int i = 0; i < size_1; i++)
        {
            if (inp_1[i] != inp_2[i])
                return false;
        }
    }

    return true;
}