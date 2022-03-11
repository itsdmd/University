#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef char CHARS[MAX_SIZE];


int UpperCounter(CHARS), WordCounter(CHARS), SenCounter(CHARS);

void ArrayDeductor(CHARS &, int &, int);



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

    cout << endl << "So chu cai hoa trong chuoi la: " << UpperCounter(inp);
    cout << endl << "So tu trong chuoi la: " << WordCounter(inp);
    cout << endl << "So cau trong chuoi la: " << SenCounter(inp);
    
    return 0;
}

/// ------------------------------------------------------------------------ ///
///                              ArrayDeductor()                             ///
/// ------------------------------------------------------------------------ ///
void ArrayDeductor(CHARS &inp, int pos)
{
    for (int i = pos; i < (MAX_SIZE - 1); i++)
        inp[i] = inp[i+1];
}

/// ------------------------------------------------------------------------ ///
///                              UpperCounter()                              ///
/// ------------------------------------------------------------------------ ///
int UpperCounter(CHARS inp)
{
    int num = 0, size = 0;

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
            i++;
            size++;
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (65 <= holder[i] && holder[i] <= 90)
            num++;
    }

    return num;
}

/// ------------------------------------------------------------------------ ///
///                               WordCounter()                              ///
/// ------------------------------------------------------------------------ ///
int WordCounter(CHARS inp)
{
    int num = 0, size = 0;

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
            i++;
            size++;
        }
    }

    if (holder[size-2] != 0 && holder[size-2] != ' ')
        holder[size-1] = ' ';

    for (int i = 0; i < size; i++)
    {
        if (holder[i] == ' ')
            num++;
    }

    return num;
}

/// ------------------------------------------------------------------------ ///
///                               SenCounter()                               ///
/// ------------------------------------------------------------------------ ///
int SenCounter(CHARS inp)
{
    int num = 0, size = 0;

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
            i++;
            size++;
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (holder[i] == '.' || holder[i] == '!' || holder[i] == '?')
            num++;
    }

    return num;
}