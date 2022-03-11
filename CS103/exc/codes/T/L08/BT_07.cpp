#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef char CHARS[MAX_SIZE];


void SpaceDel(CHARS, CHARS &);



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

    SpaceDel(inp, outp);

    cout << endl << "Chuoi sau khi chuyen doi la: " << outp << endl;
    
    return 0;
}


/// ------------------------------------------------------------------------ ///
///                             ArrayDeductor( )                             ///
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
///                                SpaceDel()                                ///
/// ------------------------------------------------------------------------ ///
void SpaceDel(CHARS inp, CHARS &res)
{
    CHARS holder;

    for (int i = 0; i < 200; i++)
        holder[i] = inp[i];
    
    for (int i = 0; i < 200;)
    {
        if (holder[i] == ' ')
            ArrayDeductor(holder, i);
        
        else
            i++;
    }
    
    for (int i = 0; i < 200; i++)
        res[i] = holder[i];
}