#include <iostream>
using namespace std;

int main()
{
    long long inp;
    int temp_cur, temp_prev;
    bool incrementing, satisfied = true;

    cout << "Nhap so nguyen duong: ";
    cin >> inp;
    
    if (inp < 0)
    {
        cout << endl << "So nhap vao khong hop le." << endl;
        main();
    }

    else
    {
        // Xét 2 chữ số cuối
        temp_prev = inp % 10;
        inp /= 10;
        temp_cur = inp % 10;
        inp /= 10;
        satisfied = (temp_cur != temp_prev);

        if (satisfied)
        {
            incrementing = (temp_cur < temp_prev);      //? Vì tăng giảm xét từ trái qua phải nên phải lật giá trị

            temp_prev = temp_cur;
            while (inp > 0)
            {
                temp_cur = inp % 10;                    // Xét chữ số ở vị trí cuối
                
                switch (incrementing)
                {
                    case true: (temp_cur < temp_prev) ? satisfied = true : satisfied = false; break;

                    case false: (temp_cur > temp_prev) ? satisfied = true : satisfied = false; break;
                }

                if (satisfied == false)
                {
                    break;
                }

                temp_prev = temp_cur;                   // Gán số vừa xét cho _prev
                inp /= 10;                              // Bỏ đi chữ số vừa xét
            }

            satisfied ? (incrementing ? (cout << "Cac chu so cua nhap vao tang theo thu tu.") : (cout << "Cac chu so cua nhap vao giam theo thu tu.")) : (cout << "Cac chu so cua nhap vao khong tang/giam theo thu tu.");
        }

        else
        {
            cout << "Cac chu so cua nhap vao khong tang/giam theo thu tu.";
        }
        
    }
    
    return 0;
}