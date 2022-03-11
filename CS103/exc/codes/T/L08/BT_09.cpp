#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef char CHARS[MAX_SIZE];


void LongestWords(CHARS);



int main()
{
    CHARS inp, outp;
    int len;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        inp[i] = char(0);
        outp[i] = char(0);
    }

    cout << endl << "Nhap chuoi: ";
    gets(inp);

    cout << endl;
    LongestWords(inp);
    

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
///                              LongestWords()                              ///
/// ------------------------------------------------------------------------ ///
void LongestWords(CHARS inp)
{
    int size = 0, max_len = 0;

    CHARS holder, longest;

    for (int i = 0; i < 200; i++)
    {
        holder[i] = inp[i];
        longest[i] = 0;
    }
    
    while (holder[0] == ' ')
        ArrayDeductor(holder, 0);


    for (int i = 0; holder[i] != 0;)
    {
        if (holder[i] == ' ' && holder[i+1] == ' ')
            ArrayDeductor(holder, i+1);
        
        else
        {
            i++;
            size++;
        }
    }

    // Xác định độ dài lớn nhất
    int pos = 0;
    for (;pos < size;)
    {
        while (holder[pos] == ' ')
            pos++;
        
        int cur_len = 0, start_pos = pos;

        while (holder[pos] != ' ' && holder[pos] != 0)
        {
            cur_len++;
            pos++;
        }

        if (cur_len >= max_len)
            max_len = cur_len;
    }


    // In các từ có độ dài bằng với độ dài lớn nhất
    cout << endl << "Cac tu co do dai lon nhat la: ";

    pos = 0;
    for (;pos < size;)
    {
        while (holder[pos] == ' ')
            pos++;
        
        int cur_len = 0, start_pos = pos;

        while (holder[pos] != ' ' && holder[pos] != 0)
        {
            cur_len++;
            pos++;
        }

        if (cur_len == max_len)
        {
            max_len = cur_len;

            int k = 0;

            for (int i = start_pos; i <= pos; i++)
            {
                longest[k] = holder[i];
                k++;
            }

            for (int i = 0; i < max_len; i++)
                cout << longest[i];
            cout << " ";
        }
    }

    cout << endl;
}