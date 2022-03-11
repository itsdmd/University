#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef char CHARS[MAX_SIZE];


void Lower(CHARS, CHARS &, int &);



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

    Lower(inp, outp, length);

    cout << endl << "Chuoi sau khi chuyen doi la: " << outp << endl;
    
    return 0;
}



void Lower(CHARS inp, CHARS &res, int &res_size)
{
    res_size = 0;

    for (int i = 0; inp[i] != 0; i++)
    {
        if (65 <= inp[i] && inp[i] <= 90)
            res[i] = char(inp[i] + 32);
        
        else
            res[i] = inp[i];
        
        res_size++;
    }
}