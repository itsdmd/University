#include <iostream>
using namespace std;

int main()
{
    int ch, dv, temp;
    
    for (int i = 10; i <= 99; i++)
    {
        temp = i;

        dv = temp % 10;
        temp /= 10;
        ch = temp % 10;

        if ((ch*dv) == (2 * (ch+dv)))
        {
            cout << i << endl;
        }

        else
        {
            continue;
        }
    }
    
    return 0;
}