#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef char CHARS[MAX_SIZE];


void Standard(CHARS, CHARS &, int &);



int main()
{
    CHARS inp, outp;
    int length;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        inp[i] = char(0);
        outp[i] = char(0);
    }

    cout << endl << "Nhap chuoi: ";
    gets(inp);

    Standard(inp, outp, length);

    cout << endl << "Chuoi sau khi chuyen doi la: " << outp << endl;
    
    return 0;
}


/// ------------------------------------------------------------------------ ///
///                              ArrayDeductor()                             ///
/// ------------------------------------------------------------------------ ///
void ArrayDeductor(CHARS &inp, int pos)
{
    for (int i = pos; i < (MAX_SIZE - 1); i++)
    {
        inp[i] = inp[i+1];

        if (i == MAX_SIZE - 2)
            inp[i] = char(0);
    }
}

/// ------------------------------------------------------------------------ ///
///                                Standard()                                ///
/// ------------------------------------------------------------------------ ///
void Standard(CHARS inp, CHARS &res, int &res_size)
{
    res_size = 0;

    CHARS holder;

    for (int i = 0; i < 200; i++)
        holder[i] = inp[i];
    
    while (holder[0] == ' ')
        ArrayDeductor(holder, 0);


    for (int i = 0; holder[i] != 0;)
    {
        if (holder[i] == ' ' && holder[i+1] == ' ')
            ArrayDeductor(holder, i+1);
        
        else if (holder[i] == ' ' && holder[i+1] == 0)
            ArrayDeductor(holder, i);
        
        else
        {
            res[i] = holder[i];
            i++;
            
            res_size++;
        }
    }
}