#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef char CHARS[MAX_SIZE];


void WordProc(CHARS, CHARS &, int &, bool);



int main()
{
    CHARS inp, outp;
    int words;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        inp[i] = char(0);
        outp[i] = char(0);
    }

    cout << endl << "Nhap chuoi: ";
    gets(inp);

    WordProc(inp, outp, words, false);

    if (words == 0)
        cout << "Chuoi nhap vao khong co tu nao";
    
    else
    {
        cout << endl << "Chuoi nhap vao co " << words << " tu, gom:" << endl << endl;
        WordProc(inp, outp, words, true);
    }

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
///                                 WordProc()                               ///
/// ------------------------------------------------------------------------ ///
void WordProc(CHARS inp, CHARS &res, int &num, bool echo)
{
    num = 0;
    int size = 0;

    CHARS holder;

    for (int i = 0; i < 200; i++)
        holder[i] = inp[i];
    
    while (holder[0] == ' ')
        ArrayDeductor(holder, 0);


    for (int i = 0; int(holder[i]) != 0;)
    {
        if (holder[i] == ' ' && holder[i+1] == ' ')
            ArrayDeductor(holder, i+1);
        
        else
        {
            res[i] = holder[i];
            i++;
            
            size++;
        }
    }

    if (holder[size-2] != 0 && holder[size-2] != ' ')
        holder[size-1] = ' ';

    for (int i = 0; i < size; i++)
    {
        if (holder[i] == ' ')
        {
            num++;

            if (echo)
                cout << endl;
        }

        else if (echo)
            cout << holder[i];
    }
}