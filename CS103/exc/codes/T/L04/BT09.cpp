#include <iostream>
using namespace std;

int main()
{
    double  a, b, c;
    int type;                   // 0: thường        1: vuông            2: cân          3: vuông cân        4: đều

    cout << endl << "Nhap do dai 3 canh cua tam giac: ";
    cin >> a >> b >> c;


    if ((a + b > c) && (a + c > b) && (b + c > a))
    {
        if (a == b == c)
        {
            type = 4;
        }

        else if ((a == b) || (a == c) || (b == c))
        {
            type = 2;
        }

        else if((a*a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a))
        {
            switch ((a == b) || (a == c) || (b == c))
            {
                case false: type = 1; break;
                case true: type = 3; break;
            }
        }

        else
        {
            type = 0;
        }


        cout << endl << "Tam giac nay la ";
        switch (type)
        {
            case 0: cout << "tam giac thuong.";     break;
            case 1: cout << "tam giac vuong.";      break;
            case 2: cout << "tam giac can.";        break;
            case 3: cout << "tam giac vuong can.";  break;
            case 4: cout << "tam giac deu.";        break;
        }
        cout << endl;
    }

    else
    {
        cout << "Cac doan nhap vao khong the tao duoc mot tam giac." << endl;
        main();
    }
    
    return 0;
}