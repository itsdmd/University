/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 04 -------------------------------
------------------------------------------------------------------------*/

#include<iostream>
using namespace std;
 
int main()
{
    int inp;

    do
    {
        cout << endl << "Nhap so hang: ";
        cin >> inp;
    } while (inp < 1);

    cout << endl;

    int triangle[inp][inp];

    triangle[0][0] = 1;
    triangle[0][1] = 1;
    triangle[1][1] = 1;

    if ((inp-1) >= 2)
    {
        int cur_y = 2;

        for (int y = 2; y <= (inp-1); y++)
        {
            for (int x = 0; x <= cur_y; x++)
            {
                if (0 < x && x < cur_y)
                    triangle[x][y] = triangle[x-1][y-1] + triangle[x][y-1];

                else
                    triangle[x][y] = 1;
            }

            cur_y++;
        }
    }

    for (int i = 0; i <= (inp-1); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << triangle[j][i] << " ";
        }

        cout << endl;
    }
    
    return 0;
}