/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 16 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

long long n, price, paid, rem,
          n_10, n_05, n_02, n_01;

int remCheck();

int nhap(int mode)
{
    if (mode == 1)
    {
        cout << endl << "Nhap so chai nuoc: ";
        cin >> n;
    }

    else if (mode == 2)
    {
        cout << endl << "Nhap don gia: ";
        cin >> price;
    }

    else if (mode == 3)
    {
        cout << endl << "Nhap so tien nguoi dung tra: ";
        cin >> paid;
        remCheck();
    }

    return 0;
}

int remCheck()
{
    rem = paid - (price * n);

    if (rem < 0)
    {
        cout << "Nguoi dung khong tra du tien!" << endl;
        nhap(3);
    }

    else if (rem == 0)
    {
        cout << endl << "Nguoi dung tra du tien. Khong co tien thua." << endl;
    }

    else
    {
        //// From W2_BT15.cpp

        n_10 = rem;
        n_10 /= 10;

        n_05 = (rem % 10) / 5;

        n_02 = ((rem % 10) - (n_05 * 5)) / 2;

        n_01 = (rem % 10) - (n_05 * 5) - (n_02 * 2);

        cout << endl << "So tien thua cua nguoi dung se duoc quy doi thanh: \n";

        if (n_10 != 0)
        {
            cout << n_10 << " to 10 dong\n";
        }

        if (n_05 != 0)
        {
            cout << n_05 << " to 5 dong\n";
        }

        if (n_02 != 0)
        {
            cout << n_02 << " to 2 dong\n";
        }

        if (n_01 != 0)
        {
            cout << n_01 << " to 1 dong\n";
        }
    }
    
    return 0;
}

int main()
{
    nhap(1);
    nhap(2);
    nhap(3);
}