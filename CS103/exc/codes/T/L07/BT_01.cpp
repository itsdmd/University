#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int ARRAY[MAX_SIZE];


void ArrayAppender(ARRAY &, int &), ArrayPrinter(ARRAY, int);



int main()
{
    int size;
    ARRAY arr;

    ArrayAppender(arr, size);

    cout << endl;
    ArrayPrinter(arr, size);
    
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
///                              ArrayPrinter()                              ///
/// ------------------------------------------------------------------------ ///
void ArrayPrinter(ARRAY inp, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Phan tu thu " << i+1 << " cua mang la: " << inp[i] << endl;
    }
}