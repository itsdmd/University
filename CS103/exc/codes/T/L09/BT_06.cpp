#include <iostream>
#include <cmath>
using namespace std;



struct NGAY{int d, m, y;};


bool DateIsValid(NGAY), IsLeap(int);

int Before(NGAY, NGAY);

long long DateInterval(NGAY, NGAY);

NGAY FromDate(NGAY, int);

void InputDate(NGAY &), PrintDate(NGAY);

void menu()
{
    cout << endl;
    cout << "================================= Menu =================================" << endl;
    cout << "1. Nhap/Xuat ngay                        5. Tim ngay truoc/sau do k ngay" << endl;
    cout << "2. Kiem tra nam nhuan                    6. Tinh khoang cach giua 2 ngay" << endl;
    cout << "3. Tinh so thu tu ngay trong nam         7. So sanh 2 ngay" << endl;
    cout << "4. Tinh so thu tu ngay ke tu ngay 1/1/1" << endl;
}


int main()
{
    NGAY inp_1, inp_2;
    int option;
    
    menu();
    
    do
    {
        if (option == -1)
            return 0;
    
        else
        {
            cout << endl << "Nhap ma so (-1 de thoat): ";
            cin >> option;
        }
    } while (option < 1 || 7 < option);


    switch (option)
    {
        case 1:
        {
            InputDate(inp_1);

            cout << endl << "Ngay vua nhap la: ";
            PrintDate(inp_1);

            break;
        }

        case 2:
        {
            InputDate(inp_1);

            cout << endl << "Nam " << inp_1.y;
            IsLeap(inp_1.y) ? cout << " la nam nhuan" : cout << " khong phai la nam nhuan";
            cout << endl;

            break;
        }

        case 3:
        {
            InputDate(inp_1);
            inp_2 = {1,1,inp_1.y};

            cout << endl;
            PrintDate(inp_1); cout << " la ngay thu " << DateInterval(inp_1, inp_2) << " cua nam " << inp_1.y << endl;

            break;
        }

        case 4:
        {
            InputDate(inp_1);
            inp_2 = {1,1,1};

            cout << endl;
            if (DateInterval(inp_1, inp_2) == 0)
                cout << "Ngay nhap vao la ngay 01/01/1" << endl;
            else
                PrintDate(inp_1); cout << " cach "; PrintDate(inp_2); cout << " " << DateInterval(inp_1, inp_2) << " ngay" << endl;


            break;
        }

        case 5:
        {
            int interval;

            InputDate(inp_1);
            cout << "Nhap k (k>0: sau, k<0: truoc): "; cin >> interval;

            cout << endl << "Ngay can tim la: ";
            PrintDate(FromDate(inp_1, interval));

            break;
        }

        case 6:
        {
            InputDate(inp_1);
            InputDate(inp_2);

            cout << endl;
            if (DateInterval(inp_1, inp_2) == 0)
                cout << "Hai ngay nhap vao giong nhau" << endl;
            else
                PrintDate(inp_1); cout << " cach "; PrintDate(inp_2); cout << " " << DateInterval(inp_1, inp_2) << " ngay" << endl;

            break;
        }

        case 7:
        {
            InputDate(inp_1);
            InputDate(inp_2);

            cout << endl << endl;

            switch (Before(inp_1, inp_2))
            {
                case 0: cout << "Hai ngay vua nhap giong nhau"; break;
                case 1: cout << "Ngay "; PrintDate(inp_1); cout << " dien ra truoc ngay "; PrintDate(inp_2); break;
                case 2: cout << "Ngay "; PrintDate(inp_1); cout << " dien ra sau ngay "; PrintDate(inp_2); break;
            }

            cout << endl;
        }
    }
    
    return 0;
}



/// ------------------------------------------------------------------------ ///
///                                InputDate()                               ///
/// ------------------------------------------------------------------------ ///
void InputDate(NGAY &target)
{
    do
    {
        cout << endl << "Nhap ngay, thang, nam: ";
        cin >> target.d >> target.m >> target.y;

        if (DateIsValid(target) == false)
            cout << "Ngay nhap vao khong hop le" << endl;

    } while (DateIsValid(target) == false);
}


/// ------------------------------------------------------------------------ ///
///                                PrintDate()                               ///
/// ------------------------------------------------------------------------ ///
void PrintDate(NGAY inp)
{
    if (inp.d < 10)
        cout << "0" << inp.d;
    else
        cout << inp.d;
    
    cout << "/";
    
    if (inp.m < 10)
        cout << "0" << inp.m;
    else
        cout << inp.m;
    
    cout << "/" << inp.y;
}


/// ------------------------------------------------------------------------ ///
///                               DateIsValid()                              ///
/// ------------------------------------------------------------------------ ///
bool DateIsValid(NGAY inp)
{
    if (inp.d < 1 || inp.d > 31 || inp.m < 0 || inp.m > 12)
        return false;

    if (inp.m == 1 || inp.m == 3 || inp.m == 5 || inp.m == 7 || inp.m == 8 || inp.m == 10 || inp.m == 12)
    {
        if (inp.d <= 31)
            return true;
        
        else
            return false;
    }

    else if (inp.m != 2)
    {
        if (inp.d <= 30)
            return true;
        
        else
            return false;
    }

    else
    {
        if (IsLeap(inp.y))
        {
            if (inp.d <= 29)
                return true;
            
            else
                return false;
        }

        else
        {
            if (inp.d <= 28)
                return true;
            
            else
                return false;
        }
        
    }
}


/// ------------------------------------------------------------------------ ///
///                                 IsLeap()                                 ///
/// ------------------------------------------------------------------------ ///
bool IsLeap(int y)
{
    switch (y % 100 == 0)   // Check xem có phải năm thế kỷ không (vd: 100, 700, 2000, etc.)
    {
        case false:
        {
            if (y % 4 == 0)
                return true;
            
            else
                return false;

            break;
        }
        
        case true:
        {
            if ((y % 4 == 0) && (y % 400 == 0))
                return true;
            
            else
                return false;

            break;
        }
    }
}


/// ------------------------------------------------------------------------ ///
///                              DateInterval()                              ///
/// ------------------------------------------------------------------------ ///
long long DateInterval(NGAY inp_1, NGAY inp_2)
{
    long long res = 0;
    bool reset;

    if (Before(inp_1, inp_2) == 0)
        return res;
    
    res = 1;

    int cur_y = inp_1.y, cur_m = inp_1.m, cur_d = inp_1.d,
        tar_y = inp_2.y, tar_m = inp_2.m, tar_d = inp_2.d;

    if (Before(inp_1, inp_2) == 1)
    {
        cur_y = inp_2.y, cur_m = inp_2.m, cur_d = inp_2.d,
        tar_y = inp_1.y, tar_m = inp_1.m, tar_d = inp_1.d;
    }



    if (cur_y == tar_y)                                                                                                         //? Nếu cùng năm
    {
        if (cur_m == tar_m)                                                                                                     //? --- Nếu cùng tháng
        {
            for (cur_d; cur_d > tar_d; cur_d--)
                res++;
            
            return res;
        }

        else                                                                                                                    //? --- Nếu khác tháng
        {
            for (cur_d; cur_d > 0; cur_d--)                                                                                     //? ------ Số ngày kể từ ngày cur_d/cur_m tới ngày 01/cur_m
                res++;

            cur_m -= 1;

            for (cur_m; cur_m > tar_m; cur_m--)                                                                                 //? ------ Cộng các ngày của các tháng giữa cur_m và tar_m
            {
                cur_d = 31;

                for (cur_d; cur_d > 0; cur_d--)
                {
                    NGAY temp{cur_d, cur_m, cur_y};

                    if (DateIsValid(temp))
                        res++;
                }
            }

            for (int i = 31; i > tar_d; i--)                                                                                    //? ------ Cộng các ngày từ ngày tar_d/tar_m tới ngày cuối tháng tar_m
            {
                NGAY temp{i, cur_m, cur_y};

                if (DateIsValid(temp))
                    res++;
            }

            return res;
        }
    }

    else                                                                                                                        //? Nếu khác năm
    {
        int y_gap = cur_y - tar_y - 1;                                                                                          //? --- Số năm nằm giữa cur_y và tar_y (Vd: y_gap của 2012 và 2017 là 4 vì có 4 năm 2013, 2014, 2015, 2016 nằm giữa 2 năm này)
        
        NGAY d1{31,12,tar_y}, d2{tar_d, tar_m, tar_y};                                                                          //? --- Số ngày từ tar tới cuối năm tar_y
        res += DateInterval(d1, d2); 

        d1 = {1,1,cur_y}, d2 = {cur_d, cur_m, cur_y};                                                                           //? --- Số ngày từ đầu năm cur_y tới cur
        res += DateInterval(d1, d2);


        d1.y = cur_y;
        
        for (int i = 0; i < y_gap; i++)                                                                                         //? --- Số ngày của các năm nằm giữa cur_y và tar_y
        {
            d1.y--;

            DateIsValid(d1);

            if (IsLeap(d1.y))
                res += 366;
            
            else
                res += 365;
        }

        return res;
    }
}


/// ------------------------------------------------------------------------ ///
///                                FromDate()                                ///
/// ------------------------------------------------------------------------ ///
NGAY FromDate(NGAY inp, int interval)
{
    if (interval == 0)
        return inp;


    NGAY itr = inp;
    int cur_int = 0;

    
    if (interval < 0)                                               // Trước
    {
        interval = -interval;
        interval += 1;
    
        while (DateInterval(inp, itr) != interval)
        {
            cur_int = DateInterval(inp, itr);
            itr.d--;

            if (itr.d == 0)
            {
                itr.d = 31;
                itr.m--;

                if (itr.m == 0)
                {
                    itr.y--;
                    itr.m = 12;
                }

                while (DateIsValid(itr) == false)
                {
                    itr.d--;
                }

                continue;
            }
        }
    }

    else
    {
        interval += 1;
    
        while (DateInterval(inp, itr) != interval)
        {
            cur_int = DateInterval(inp, itr);
            itr.d++;

            if (DateIsValid(itr) == false)
            {
                itr.d = 1;
                itr.m++;

                if (itr.m == 13)
                {
                    itr.y++;
                    itr.m = 1;
                }

                continue;
            }
        }
    }

    return itr;
}


/// ------------------------------------------------------------------------ ///
///                                 Before()                                 ///
/// ------------------------------------------------------------------------ ///
int Before(NGAY inp_1, NGAY inp_2)
{
    if (inp_1.y < inp_2.y)
        return 1;
    
    else if (inp_1.y == inp_2.y)
    {
        if (inp_1.m < inp_2.m)
            return 1;
        
        else if (inp_1.m == inp_2.m)
        {
            if (inp_1.d < inp_2.d)
                return 1;
            
            else if (inp_1.d == inp_2.d)
                return 0;
            
            else
                return 2;
        }

        else
            return 2;
    }

    else
        return 2;
}