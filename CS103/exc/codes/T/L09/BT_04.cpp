#include <iostream>
#include <cmath>
using namespace std;



struct DIEM {double x, y;};


int Quarter(DIEM);

double PntDist(DIEM, DIEM);

DIEM SymmAboutOrigin(DIEM);

void PntInput(DIEM &), PntPrint(DIEM);


void menu()
{
    cout << endl;
    cout << "================================ Menu ================================" << endl;
    cout << "1. Nhap/Xuat toa do diem           3. Tim diem doi xung qua goc toa do" << endl;
    cout << "2. Tinh khoang cach giua 2 diem    4. Kiem tra diem thuoc phan tu nao" << endl;
}


int main()
{
    DIEM pnt_1, pnt_2;
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
    } while (option < 1 || 4 < option);

    switch (option)
    {
        case 1:
        {
            cout << endl;
            PntInput(pnt_1);

            cout << endl << "Diem vua nhap co toa do la: ";
            PntPrint(pnt_1);
            cout << endl;

            break;
        }

        case 2:
        {
            cout << endl << "===== Diem 1 =====";
            PntInput(pnt_1);
            cout << endl << "===== Diem 2 =====";
            PntInput(pnt_2);

            cout << endl << "Khoang cach giua 2 diem la: " << fixed << PntDist(pnt_1, pnt_2) << endl;

            break;
        }

        case 3:
        {
            cout << endl;
            PntInput(pnt_1);

            cout << "Diem doi xung voi diem vua nhap co toa do la: ";
            PntPrint(SymmAboutOrigin(pnt_1));
            cout << endl;

            break;
        }

        case 4:
        {
            cout << endl;
            PntInput(pnt_1);

            if (Quarter(pnt_1) == 0)
                cout << endl << "Diem vua nhap nam tai goc toa do" << endl;
            
            else
                cout << endl << "Diem vua nhap nam trong phan tu thu " << Quarter(pnt_1) << endl;
        }
    }
    
    return 0;
}


/// ------------------------------------------------------------------------ ///
///                                PntInput()                                ///
/// ------------------------------------------------------------------------ ///
void PntInput(DIEM &target)
{
    cout << endl << "Nhap x: "; cin >> target.x;
    cout << "Nhap y: "; cin >> target.y;
}


/// ------------------------------------------------------------------------ ///
///                                PntPrint()                                ///
/// ------------------------------------------------------------------------ ///
void PntPrint(DIEM target)
{
    cout << "(" << target.x << ", " << target.y << ")";
}


/// ------------------------------------------------------------------------ ///
///                                 PntDist()                                ///
/// ------------------------------------------------------------------------ ///
double PntDist(DIEM inp_1, DIEM inp_2)
{
    return sqrt(pow((inp_2.x - inp_1.x), 2) + pow((inp_2.y - inp_1.y), 2));
}


/// ------------------------------------------------------------------------ ///
///                             SymmAboutOrigin()                            ///
/// ------------------------------------------------------------------------ ///
DIEM SymmAboutOrigin(DIEM inp)
{
    return {0 - inp.x, 0 - inp.y};
}


/// ------------------------------------------------------------------------ ///
///                                 Quarter()                                ///
/// ------------------------------------------------------------------------ ///
int Quarter(DIEM inp)
{
    if (inp.x > 0 && inp.y > 0)
        return 1;
    
    else if (inp.x < 0 && inp.y > 0)
        return 2;
    
    else if (inp.x < 0 && inp.y < 0)
        return 3;
    
    else if (inp.x > 0 && inp.y < 0)
        return 4;
    
    else
        return 0;
}