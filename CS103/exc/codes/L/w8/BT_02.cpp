/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 02 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;



struct SV
{
    string name;
    int yob;
    float dtb;
};

typedef SV SV_ARR[200];



void InputSV(SV &), InputSVArr(SV_ARR &, int &), PrintSV(SV);



int main()
{
    SV_ARR inp, mins, maxes;
    int inp_size = 0, mins_size = 0, maxes_size = 0;

    InputSVArr(inp, inp_size);

    SV min = inp[0], max = inp[0];

    for (int i = 0; i < inp_size; i++)
    {
        if (inp[i].dtb < min.dtb)
            min = inp[i];
        
        if (inp[i].dtb > max.dtb)
            max = inp[i];
    }

    for (int i = 0; i < inp_size; i++)
    {
        if (inp[i].dtb == min.dtb)
        {
            mins[mins_size] = inp[i];
            mins_size++;
        }
        
        else if (inp[i].dtb == max.dtb)
        {
            maxes[maxes_size] = inp[i];
            maxes_size++;
        }
    }

    cout << endl << endl << maxes_size << " sinh vien co diem trung binh cao nhat la: ";
    for (int i = 0; i < maxes_size; i++)
    {
        cout << endl << "===== [" << i+1 << "] =====";
        PrintSV(maxes[i]);
    }
    
    cout << endl << endl << mins_size << " sinh vien co diem trung binh thap nhat la: ";
    for (int i = 0; i < mins_size; i++)
    {
        cout << endl << "===== [" << i+1 << "] =====";
        PrintSV(mins[i]);
    }
    
    return 0;
}



/// ------------------------------------------------------------------------ ///
///                                 InputSV()                                ///
/// ------------------------------------------------------------------------ ///
void InputSV(SV &target)
{
    cin.clear(); cin.sync();

    cout << endl << "Nhap ten sinh vien: ";
    getline(cin, target.name);

    cout << "Nhap nam sinh: ";
    cin >> target.yob;

    cout << "Nhap diem trung binh: ";
    cin >> target.dtb;

    cout << endl;
}


/// ------------------------------------------------------------------------ ///
///                               InputSVArr()                               ///
/// ------------------------------------------------------------------------ ///
void InputSVArr(SV_ARR &target, int &size)
{
    cout << "Nhap so sinh vien: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << endl << "===== Sinh vien " << i+1 << " =====";
        InputSV(target[i]);
    }
}


/// ------------------------------------------------------------------------ ///
///                                 PrintSV()                                ///
/// ------------------------------------------------------------------------ ///
void PrintSV(SV target)
{
    cout << endl << "Ten: " << target.name << endl << "Sinh nam: " << target.yob << endl << "Diem TB: " << target.dtb << endl;
}