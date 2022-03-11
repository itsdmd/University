#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef int ARRAY[MAX_SIZE];


void ArrayAppender(ARRAY &, int &),
     ArrayElementExtractor(ARRAY, int, char, ARRAY &, int &, ARRAY &, int &), ArrayElementExtractor(ARRAY, int, char, ARRAY &, int &), ArrayElementSorter(ARRAY, int, char, ARRAY &, int &);


int main()
{
    int mode, size_inp, size_prime, size_pos, size_temp, size_decr, size_special;
    ARRAY inp_arr, prime_arr, pos_arr, temp_arr, decr_arr, special_arr;

    ArrayAppender(inp_arr, size_inp);

    cout << endl;
    cout << "===================== Menu =====================" << endl;
    cout << "1. Tim cac so nguyen to trong mang"<< endl;
    cout << "2. Tim cac so nguyen duong trong mang"<< endl;
    cout << "3. Sap xep mang theo thu tu giam dan"<< endl;
    cout << "4. Sap xep mang cho cac so duong dung dau mang "<< endl
         << "   giam dan, ke den la cac so am tang dan" << endl
         << "   va cuoi cung la cac so 0" << endl;

    do
    {
    cout << endl << "Nhap ma so: ";
    cin >> mode;
    } while (mode < 1 && 4 < mode);

    cout << endl << "==========[" << mode << "]==========";

    switch (mode)
    {
        case 1:
        {
            ArrayElementExtractor(inp_arr, size_inp, 'p', inp_arr, size_inp, prime_arr, size_prime);

            if (size_prime == 0)
                cout << endl << "Mang nhap vao khong co so nguyen to";
            
            else
            {
                cout << endl << "Cac so nguyen to trong mang la: ";
                for (int i = 0; i < size_prime; i++)
                    cout << prime_arr[i]  << " ";
                
                cout << endl << "Cac so con lai trong mang nhap vao la: ";
                for (int i = 0; i < size_inp; i++)
                    cout << inp_arr[i]  << " ";
            }

            cout << endl;

            break;
        }

        case 2:
        {
            ArrayElementExtractor(inp_arr, size_inp, '+', temp_arr, size_temp, pos_arr, size_pos);

            cout << endl << "Cac so trong mang nhap vao la: ";
            for (int i = 0; i < size_inp; i++)
                cout << inp_arr[i]  << " ";
            
            if (size_pos == 0)
                cout << endl << "Mang nhap vao khong co so nguyen duong";
            
            else
            {
                cout << endl << "Cac so nguyen duong trong mang la: ";
                for (int i = 0; i < size_pos; i++)
                    cout << pos_arr[i]  << " ";
                
                cout << endl << "Cac so con lai trong mang la: ";
                for (int i = 0; i < size_temp; i++)
                    cout << temp_arr[i]  << " ";
            }

            cout << endl;

            break;
        }

        case 3:
        {
            ArrayElementSorter(inp_arr, size_inp, 'd', decr_arr, size_decr);

            cout << endl << "Mang sau khi duoc sap xep theo thu tu giam dan la: ";

            for (int i = 0; i < size_decr; i++)
            {
                cout << decr_arr[i] << " ";
            }
            
            break;
        }

        case 4:
        {
            ArrayElementSorter(inp_arr, size_inp, '*', special_arr, size_special);

            cout << endl << "Mang sau khi duoc sap xep theo yeu cau la: ";

            for (int i = 0; i < size_special; i++)
            {
                cout << special_arr[i] << " ";
            }
            
            break;
        }

        cout << endl << endl;
    }
    
    return 0;
}



/// -------------------------------------------------------------------------- ///
///                                  IsPrime()                                 ///
/// -------------------------------------------------------------------------- ///
bool IsPrime(int inp)
{
    if (inp < 2)
        return false;
    
    int checkPnt = 0;
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
    {
        inp[i] = inp[i+1];
    }
    
    size--;
}

/// -------------------------------------------------------------------------- ///
///                           ArrayElementExtractor()                          ///
/// -------------------------------------------------------------------------- ///
void ArrayElementExtractor(ARRAY inp, int size_in, char mode, ARRAY &outp, int &size_out)
{
    ARRAY temp;
    for (int i = 0; i < size_in; i++)
        temp[i] = inp[i];
    

    int cur_pos = 0;
    size_out = 0;

    switch (mode)
    {
        case 'p':                                                       // Prime
        {
            for (int i = 0; i < size_in;)
            {
                if (IsPrime(temp[i]))
                {
                    outp[cur_pos] = temp[i];
                    size_out++;

                    ArrayDeductor(temp, size_in, i);

                    cur_pos++;
                }

                else
                     i++;
            }
            
            break;
        }

        case '+':                                                       // Positive
        {
            for (int i = 0; i < size_in;)
            {
                if (temp[i] > 0)
                {
                    outp[cur_pos] = temp[i];
                    size_out++;

                    ArrayDeductor(temp, size_in, i);

                    cur_pos++;
                }

                else
                     i++;
            }

            break;
        }
        
        case '-':                                                       // Negative
        {
            for (int i = 0; i < size_in;)
            {
                if (temp[i] < 0)
                {
                    outp[cur_pos] = temp[i];
                    size_out++;

                    ArrayDeductor(temp, size_in, i);

                    cur_pos++;
                }

                else
                     i++;
            }

            break;
        }
        
        case '0':                                                       // Zeros
        {
            for (int i = 0; i < size_in;)
            {
                if (temp[i] == 0)
                {
                    outp[cur_pos] = temp[i];
                    size_out++;

                    ArrayDeductor(temp, size_in, i);

                    cur_pos++;
                }

                else
                     i++;
            }

            break;
        }
    }
}

/// -------------------------------------------------------------------------- ///
///                      ArrayElementExtractor() overload                      ///
/// -------------------------------------------------------------------------- ///
void ArrayElementExtractor(ARRAY inp, int size_in, char mode, ARRAY &outp_1, int &size_out_1, ARRAY &outp_2, int &size_out_2)
{
    ARRAY temp;
    for (int i = 0; i < size_in; i++)
        temp[i] = inp[i];
    

    int cur_pos = 0;

    size_out_1 = size_in;
    size_out_2 = 0;

    for (int i = 0; i < size_in; i++)
        outp_1[i] = temp[i];

    switch (mode)
    {
        case 'p':                                                       // Prime
        {
            for (int i = 0; i < size_out_1;)
            {
                if (IsPrime(outp_1[i]))
                {
                    outp_2[cur_pos] = outp_1[i];
                    size_out_2++;

                    ArrayDeductor(outp_1, size_out_1, i);

                    cur_pos++;
                }

                else
                     i++;
            }
            
            break;
        }

        case '+':                                                       // Positive
        {
            for (int i = 0; i < size_out_1;)
            {
                if (outp_1[i] > 0)
                {
                    outp_2[cur_pos] = outp_1[i];
                    size_out_2++;

                    ArrayDeductor(outp_1, size_out_1, i);

                    cur_pos++;
                }

                else
                     i++;
            }

            break;
        }
        
        case '-':                                                       // Negative
        {
            for (int i = 0; i < size_out_1;)
            {
                if (outp_1[i] < 0)
                {
                    outp_2[cur_pos] = outp_1[i];
                    size_out_2++;

                    ArrayDeductor(outp_1, size_out_1, i);

                    cur_pos++;
                }

                else
                     i++;
            }

            break;
        }
        
        case '0':                                                       // Zeros
        {
            for (int i = 0; i < size_out_1;)
            {
                if (outp_1[i] == 0)
                {
                    outp_2[cur_pos] = outp_1[i];
                    size_out_2++;

                    ArrayDeductor(outp_1, size_out_1, i);

                    cur_pos++;
                }

                else
                     i++;
            }

            break;
        }
    }
}

/// -------------------------------------------------------------------------- ///
///                            ArrayElementSorter()                            ///
/// -------------------------------------------------------------------------- ///
void ArrayElementSorter(ARRAY inp, int size_in, char mode, ARRAY &outp, int &size_out)
{
    int cur_pos = 0;

    size_out = size_in;

    for (int i = 0; i < size_in; i++)
        outp[i] = inp[i];

    switch (mode)
    {
        case 'i':                                                       // Increment
        {
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

            break;
        }

        case 'd':                                                       // Decrement
        {
            for (int i = 0; i < size_out; i++)
            {
                for (int j = i + 1; j < size_out; j++)
                {
                    if (outp[i] < outp[j])
                    {
                        int temp = outp[i];

                        outp[i] = outp[j];
                        outp[j] = temp;
                    }
                }
            }

            break;
        }

        case '*':                                                       // Special
        {
            ARRAY pos, neg, zero, temp;
            int size_pos, size_neg, size_zero;


            for (int i = 0; i < size_in; i++)
                temp[i] = inp[i];
            ArrayElementExtractor(temp, size_in, '+', pos, size_pos);
            
            for (int i = 0; i < size_in; i++)
                temp[i] = inp[i];
            ArrayElementExtractor(temp, size_in, '-', neg, size_neg);
            
            for (int i = 0; i < size_in; i++)
                temp[i] = inp[i];
            ArrayElementExtractor(temp, size_in, '0', zero, size_zero);



            for (int i = 0; i < size_pos; i++)
                temp[i] = pos[i];
            ArrayElementSorter(temp, size_pos, 'd', pos, size_pos);

            for (int i = 0; i < size_neg; i++)
                temp[i] = neg[i];
            ArrayElementSorter(temp, size_neg, 'i', neg, size_neg);



            for (int i = 0; i < size_pos; i++)
                outp[i] = pos[i];

            for (int i = size_pos; i < (size_pos + size_neg); i++)
                outp[i] = neg[i - size_pos];

            for (int i = (size_pos + size_neg); i < (size_pos + size_neg + size_neg); i++)
                outp[i] = zero[i - size_pos - size_neg];
            

            break;
        }
    }
}
