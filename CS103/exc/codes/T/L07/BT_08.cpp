#include <iostream>
using namespace std;



#define MAX_SIZE 200
typedef char ARRAY[MAX_SIZE];


int ArrayComparer(ARRAY, int, ARRAY, int, char);

void ArrayAppender(ARRAY &, int &);



int main()
{
    int mode, size_1, size_2, res;
    ARRAY arr_1, arr_2;


    cout << endl << "========== Mang 1 ==========" << endl;
    ArrayAppender(arr_1, size_1);
    
    cout << endl << endl << "========== Mang 2 ==========" << endl;
    ArrayAppender(arr_2, size_2);


    cout << endl << endl << "=> ";

    res = ArrayComparer(arr_1, size_1, arr_2, size_2, 'M');

    if (res == 0)
        cout << "Hai mang bang nhau";
        
    else if (res == 1)
        cout << "Mang 1 lon hon";
    
    else
        cout << "Mang 2 lon hon";
    
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
///                               ArrayComparer()                              ///
/// -------------------------------------------------------------------------- ///
int ArrayComparer(ARRAY inp_1, int size_1, ARRAY inp_2, int size_2, char mode)
{
    switch (mode)
    {
        case 'm':                                                               // Min
        {
            //

            break;
        }

        case 'M':                                                               // Max
        {
            if (size_1 > size_2)
                return 1;
            
            else if (size_2 > size_1)
                return 2;
            
            else
            {
                for (int i = 0; i < size_1; i++)
                {
                    if (int(inp_1[i]) > int(inp_2[i]))
                        return 1;
                    
                    else if (int(inp_2[i]) > int(inp_1[i]))
                        return 2;
                }
                
            }

            break;
        }
    }

    return 0;                                                                    //? 0: = nhau
}