#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int ARRAY[MAX_SIZE];


void ArrayAppender(ARRAY &, int &), ArrayProc(ARRAY, int, char, ARRAY &, int &);



int main()
{
    int mode, size_inp, size_outp;
    ARRAY inp_arr, outp_arr;

    ArrayAppender(inp_arr, size_inp);

    cout << endl;
    cout << "===================== Menu =====================" << endl;
    cout << "1. Sua cac so nguyen to trong mang thanh so 0"<< endl;
    cout << "2. Chen so 0 dang sau cac so nguyen to trong mang"<< endl;
    cout << "3. Xoa tat ca cac so nguyen to co trong mang"<< endl;

    do
    {
        cout << endl << "Nhap ma so: ";
        cin >> mode;
    } while (mode < 1 && 3 < mode);

    cout << endl << "==========[" << mode << "]==========" << endl;

    switch (mode)
    {
        case 1: ArrayProc(inp_arr, size_inp, 'r', outp_arr, size_outp); break;
        
        case 2: ArrayProc(inp_arr, size_inp, 'i', outp_arr, size_outp); break;
        
        case 3: ArrayProc(inp_arr, size_inp, 'd', outp_arr, size_outp); break;
    }

    cout << endl << "Mang duoc nhap vao gom: ";
    for (int i = 0; i < size_inp; i++)
        cout << inp_arr[i] << " ";
    
    cout << endl << "Mang sau khi sua gom: ";
    for (int i = 0; i < size_outp; i++)
        cout << outp_arr[i] << " ";



    return 0;
}



/// -------------------------------------------------------------------------- ///
///                                  IsPrime()                                 ///
/// -------------------------------------------------------------------------- ///
bool IsPrime(long long inp)
{
    if (inp < 2)
        return false;
    
    long long checkPnt = 0;
    checkPnt = inp/2;

    for(int i = 2; i <= checkPnt; i++)
    {  
        if(inp % i == 0)
        {  
            return false;
        }
    }

    return true;
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
///                               ArrayDeductor()                              ///
/// -------------------------------------------------------------------------- ///
void ArrayDeductor(ARRAY &inp, int &size, int pos)
{
    for (int i = pos; i < size; i++)
        inp[i] = inp[i+1];
    
    size--;
}

/// -------------------------------------------------------------------------- ///
///                               ArrayInserter()                              ///
/// -------------------------------------------------------------------------- ///
void ArrayInserter(ARRAY &inp, int &size, int val, int pos)
{
    for (int i = size; i > pos; i--)
        inp[i] = inp[i-1];
    
    inp[pos] = val;
    size++;
}

/// -------------------------------------------------------------------------- ///
///                                 ArrayProc()                                ///
/// -------------------------------------------------------------------------- ///
void ArrayProc(ARRAY inp, int size_in, char mode, ARRAY &outp, int &size_out)
{
    for (int i = 0; i < size_in; i++)
        outp[i] = inp[i];
        
    size_out = size_in;

    switch (mode)
    {
        case 'r':                                   // Replace
        {
            for (int i = 0; i < size_out; i++)
            {
                if (IsPrime(outp[i]))
                    outp[i] = 0;
            }

            break;
        }

        case 'i':                                   // Insert
        {
            for (int i = 0; i < size_out; i++)
            {
                if (IsPrime(outp[i]))
                    ArrayInserter(outp, size_out, 0, i+1);
            }
            
            break;
        }
        
        case 'd':                                   // Delete
        {
            for (int i = 0; i < size_out;)
            {
                if (IsPrime(outp[i]))
                    ArrayDeductor(outp, size_out, i);
                
                else
                     i++;
            }
            
            break;
        }
    }
    
}