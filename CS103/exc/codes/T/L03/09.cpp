#include <iostream>
using namespace std;
 
int inp;

int main()
{
    cout << endl << "Nhap so xe: ";
    cin >> inp;
    inp = abs(inp);

    if (inp < 1000 || inp > 9999)
    {
        cout << "So xe nhap vao phai la so co 4 chu so" << endl;
        main();
    }

    else
    {
        int _1_, _2_, _3_, _4_;
        _1_ = (inp / 1000) % 10;
        _2_ = (inp / 100) % 10;
        _3_ = (inp / 10) % 10;
        _4_ = inp % 10;

        cout << "So xe cua ban duoc " << ( (_1_ + _2_ + _3_ + _4_) % 10 ) << " nut" << endl;
    }
    
    return 0;
}
