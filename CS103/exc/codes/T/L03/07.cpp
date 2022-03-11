#include <iostream>
#include <string>
using namespace std;

float t, l, h,
      hs_t, hs_l, hs_h;

int nhap(string cat, string subj)
{
    string grdStr       = "Nhap diem mon ";
    string mltStr       = "Nhap he so mon ";
    string sufStr_T     = "Toan: ";
    string sufStr_L     = "Ly: ";
    string sufStr_H     = "Hoa: ";
    
    float val;
    
    cout << endl;

    if (cat == "g")
    {
        if (subj == "t")
        {
            cout << grdStr << sufStr_T;
            cin >> t;
            val = t;
        }

        else if (subj == "l")
        {
            cout << grdStr << sufStr_L;
            cin >> l;
            val = l;
        }

        else if (subj == "h")
        {
            cout << grdStr << sufStr_H;
            cin >> h;
            val = h;
        }

        if (val < 0 || val > 10)
        {
            cout << "Diem nhap vao phai nam trong khoang [0; 10]" << endl;
            nhap(cat, subj);
        }
    }
    
    else if (cat == "m")
    {
        if (subj == "t")
        {
            cout << mltStr << sufStr_T;
            cin >> hs_t;
            val = hs_t;
        }

        else if (subj == "l")
        {
            cout << mltStr << sufStr_L;
            cin >> hs_l;
            val = hs_l;
        }

        else if (subj == "h")
        {
            cout << mltStr << sufStr_H;
            cin >> hs_h;
            val = hs_h;
        }

        if (val < 0)
        {
            cout << "He so phai lon hon 0." << endl;
            nhap(cat, subj);
        }
    }
    
    return 0;
}

int main()
{
    nhap("g", "t");
    nhap("g", "l");
    nhap("g", "h");
    nhap("m", "t");
    nhap("m", "l");
    nhap("m", "h");

    cout << endl << "Diem trung binh: " << ( (t*hs_t + l*hs_l + h*hs_h) / (hs_t + hs_l + hs_h) ) << endl;
    
    return 0;
}