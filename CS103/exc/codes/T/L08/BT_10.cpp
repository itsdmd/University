#include <iostream>
using namespace std;



#define MAX_SIZE 200

typedef char CHARS[MAX_SIZE];


void Extractor(CHARS, int, int, CHARS &, bool &), Printer(CHARS, int);



int main()
{
    bool valid;
    CHARS inp, outp_1, outp_2, outp_3;
    int len, pos;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        inp[i] = 0;
        outp_1[i] = 0;
        outp_2[i] = 0;
        outp_3[i] = 0;
    }

    cout << endl << "Nhap chuoi: ";
    gets(inp);

    cout << endl << "Nhap so ki tu can lay: ";
    cin >> len;

    cout << endl << "Nhap vi tri pos (bat dau tu 0): ";
    cin >> pos;



    
    Extractor(inp, 0, len, outp_1, valid);

    if (!valid)
        cout << endl << "Gia tri nhap vao khong hop le" << endl;

    else
    {
        cout << endl << len << " ki tu dau tien la: ";
        Printer(outp_1, len);
    }
    

    Extractor(inp, -1, len, outp_2, valid);

    if (!valid)
        cout << endl << "Gia tri nhap vao khong hop le" << endl;

    else
    {
        cout << endl << len << " ki tu cuoi cung la: ";
        Printer(outp_2, len);
    }


    Extractor(inp, pos, len, outp_3, valid);

    if (!valid)
        cout << endl << "Gia tri nhap vao khong hop le" << endl;
    
    else
    {
        cout << endl << len << " ki tu bat dau tai vi tri " << pos << " la: ";
        Printer(outp_3, len);
    }


    
    return 0;
}

/// ------------------------------------------------------------------------ ///
///                                Extractor()                               ///
/// ------------------------------------------------------------------------ ///
void Extractor(CHARS inp, int start, int len, CHARS &outp, bool &valid)
{
    int inp_len = 0;

    for (int i = 0; (i < 200) && (inp[i] != 0); i++)
        inp_len++;

    valid = true;
    if (len > inp_len || abs(start) > inp_len || len <= 0)
        valid = false;

    if (valid)
    {
        int o = 0;

        if (start >= 0)
        {
            for (int i = start; i < (start + len); i++)
            {
                outp[o] = inp[i];
                o++;
            }
        }

        else if (start < 0)
        {
            for (int i = inp_len - len - 1; i < inp_len; i++)
            {
                outp[o] = inp[i];
                o++;
            }
        }
    }
}

/// ------------------------------------------------------------------------ ///
///                                 Printer()                                ///
/// ------------------------------------------------------------------------ ///
void Printer(CHARS inp, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (i > 0)
            cout << ", ";
        
        cout << inp[i];
    }
    
}