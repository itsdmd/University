#include <iostream>
using namespace std;

int main()
{
    long long inp, og;
    int temp, min = 9, max = 0;

    cout << "Nhap so nguyen duong: ";
    cin >> inp;

    if (inp < 0)
    {
        cout << endl << "So nhap vao khong hop le." << endl;
        main();
    }

    else
    {
        og = inp;

        while (inp > 0)
        {
            temp = inp % 10;    // Xét chữ số ở vị trí cuối
            
            if (temp < min)
            {
                min = temp;
            }

            if (temp > max)
            {
                max = temp;
            }

            inp /= 10;          // Bỏ đi chữ số vừa xét
        }

        cout << endl << "Chu so nho nhat la " << min << ". Chu so lon nhat la " << max << "." << endl;
    }


    return 0;
}