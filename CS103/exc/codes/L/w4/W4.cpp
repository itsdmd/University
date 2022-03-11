/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập TL -------------------------------
------------------------------------------------------------------------*/


#include <iostream>
#include <Windows.h>    //// Hàm Sleep()
using namespace std;

int DemUocSo(long long inp, bool looping), Reverse(long long inp), Timer(long long sec);


/// -------------------------------------------------------------------------- ///
///                                   main()                                   ///
/// -------------------------------------------------------------------------- ///
int main()
{
    int mode;
    long long ll_inp;

    cout << endl << "Nhap 1 so nguyen tu 1 den 7: ";
    cin >> mode;
    switch (mode)
    {
        /// --------------------------------- Case 1 --------------------------------- ///
        //? Đếm số ước của n
        case 1:
        {
            int res_1;

            //? Lặp đến khi nhận được số hợp lệ
            do
            {
                cout << endl << "Nhap vao mot so nguyen duong: ";
                cin >> ll_inp;
                res_1 = DemUocSo(ll_inp, true);

                if (res_1 == -2 || res_1 == 0)
                {
                    cout << endl << ll_inp << " khong co uoc so." << endl;
                }

                else if (res_1 != -1)
                {
                    cout << endl << ll_inp << " co " << res_1 << " uoc so." << endl;
                }
            }
            while (res_1 == -1);

            break;
        }

        /// --------------------------------- Case 2 --------------------------------- ///
        //? Kiểm tra n có phải số nguyên tố
        case 2:
        {
            int res_2;

            cout << endl << "Nhap vao mot so nguyen duong: ";
            cin >> ll_inp;

            res_2 = DemUocSo(ll_inp, false);

            if (res_2 == -2 || res_2 == 0)
            {
                cout << ll_inp << " la so nguyen to." << endl;
            }

            else
            {
                cout << endl << ll_inp << " khong phai la so nguyen to" << endl;
            }

            break;
        }

        /// --------------------------------- Case 3 --------------------------------- ///
        //? In ra các số nguyên tố từ 1 đến n
        case 3:
        {
            cout << endl << "Nhap vao mot so nguyen duong: ";
            cin >> ll_inp;

            if (ll_inp < 2)
            {
                cout << "Khong co so nguyen to nao trong khoang tu 1 den " << ll_inp << endl;
            }

            else
            {
                cout << endl << "Cac so nguyen to tu 1 den " << ll_inp << " la:" << endl;

                for (int i = 2; i <= ll_inp; i++)
                {
                    if (DemUocSo(i, false) > 0)
                    {
                        continue;
                    }

                    else
                    {
                        cout << i << " ";
                    }
                }

                cout << endl;
            }
            
            break;
        }

        /// --------------------------------- Case 4 --------------------------------- ///
        //? Tính tổng các số nguyên tố
        case 4:
        {
            long long res_4 = 0;

            cout << endl << "Nhap vao mot so nguyen duong: ";
            cin >> ll_inp;

            if (ll_inp < 2)
            {
                cout << "Khong co so nguyen to trong khoang tu 1 den " << ll_inp << endl;
            }

            else
            {
                for (int i = 2; i <= ll_inp; i++)
                {
                    if (DemUocSo(i, false) > 0)
                    {
                        continue;
                    }

                    else
                    {
                        res_4 += i;
                    }
                }

                cout << "Tong cac so nguyen to tu 1 den " << ll_inp << " la " << res_4 << endl;
            }
            
            break;
        }

        /// --------------------------------- Case 5 --------------------------------- ///
        //? Trả về số đào ngược
        case 5:
        {
            cout << endl << "Nhap vao mot so nguyen duong: ";
            cin >> ll_inp;

            while (ll_inp <= 0)
            {
                cout << "So nhap vao khong hop le." << endl;

                cout << endl << "Nhap 1 so nguyen duong: ";
                cin >> ll_inp;
            }

            cout << "So dao nguoc cua " << ll_inp << " la " << Reverse(ll_inp) << endl;

            break;
        }

        /// --------------------------------- Case 6 --------------------------------- ///
        //? Kiểm tra n có phải số đối xứng
        case 6:
        {
            cout << endl << "Nhap vao mot so nguyen duong: ";
            cin >> ll_inp;

            while (ll_inp <= 0)
            {
                cout << "So nhap vao khong hop le." << endl;

                cout << endl << "Nhap 1 so nguyen duong: ";
                cin >> ll_inp;
            }

            (ll_inp == Reverse(ll_inp)) ? cout << ll_inp << " la so doi xung." << endl : cout << ll_inp << " khong phai la so doi xung." << endl;

            break;
        }

        /// --------------------------------- Case 7 --------------------------------- ///
        //? Đồng hồ đếm ngược
        case 7:
        {
            long long min, sec;

            cout << endl << "Nhap so phut: ";
            cin >> min;

            while (min < 0)
            {
                cout << "So nhap vao khong hop le." << endl;

                cout << endl << "Nhap so phut: ";
                cin >> min;
            }

            cout << endl << "Nhap so giay: ";
            cin >> sec;

            while (sec < 0)
            {
                cout << "So nhap vao khong hop le." << endl;

                cout << endl << "Nhap so giay: ";
                cin >> sec;
            }

            sec += min*60;              //? Đổi qua sec cho dễ đếm

            cout << endl;
            Timer (sec);

            break;
        }

        default:
        {
            cout << "Gia tri nhap vao khong hop le." << endl;
            main();
        }
    }
    
    return 0;
}

/// -------------------------------------------------------------------------- ///
///                                 Đếm ước số                                 ///
/// -------------------------------------------------------------------------- ///
int DemUocSo(long long inp, bool looping)
{
    long long outp = 0;

    if (inp <= 0)
    {
        if (looping)
        {
            return -1;
        }

        else
        {
            return -2;
        }
    }

    else
    {
        for (long long i = 2; i < inp; i++)
        {
            if (inp % i == 0)
            {
                outp++;
            }

            else
            {
                continue;
            }
        }

        return outp;
    }
}

/// -------------------------------------------------------------------------- ///
///                                   Reverse                                  ///
/// -------------------------------------------------------------------------- ///
int Reverse(long long inp)
{
    long long og, mod = 0, temp;

    cout << endl << "Nhap so nguyen duong: ";
    cin >> inp;

    inp = abs(inp);

    og = inp;

    while(inp > 0)
    {
        temp = inp % 10;            // Lấy chữ số cuối của inp
        mod = (mod*10) + temp;      // ... và thêm vào cuối biến mod
        inp = inp / 10;             // Bỏ đi chữ số vừa lấy từ inp
    }

    return mod;
}

/// -------------------------------------------------------------------------- ///
///                                    Timer                                   ///
/// -------------------------------------------------------------------------- ///
int Timer(long long sec)
{
    while (sec > 0)
    {
        while (sec > 5)
        {
            if (sec/60 < 10)
                cout << "0" << sec/60;
            else
                cout << sec/60;

            cout << ":";

            if ((sec - (sec/60)*60) < 10)             //? Do 2 biến này kiểu int nên khi /60 sẽ nhận được số phút là số nguyên
                cout << "0" << sec - (sec/60)*60;
            else
                cout << sec - (sec/60)*60;
            
            cout << endl;
            
            Sleep(1000);
            sec--;
        }     

        if (sec/60 < 10)
            cout << "0" << sec/60;
        else
            cout << sec/60;

        cout << ":";

        if ((sec - (sec/60)*60) < 10)
            cout << "0" << sec - (sec/60)*60;
        else
            cout << sec - (sec/60)*60;
        
        cout << " Tich tac";
            
        cout << endl;
        
        Sleep(1000);
        sec--;
    }

    cout << "00:00 Reng reng reng" << endl;

    return 0;
}













