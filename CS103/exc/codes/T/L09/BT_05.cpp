#include <iostream>
#include <cmath>
using namespace std;



struct DIEM{double x, y;};


double PntDist(DIEM, DIEM);


struct TAMGIAC
{
    DIEM a, b, c;

    double ab, bc, ac,
           ah, bh, ch,
           p, s;

    bool legal;
};


void InputTriangle(TAMGIAC &), PrintTriangle(TAMGIAC), TriangleGenerator(TAMGIAC &);


void menu()
{
    cout << endl;
    cout << "========== Menu ==========" << endl;
    cout << "1. Nhap/Xuat tam giac" << endl;
    cout << "2. Tinh chu vi tam giac" << endl;
    cout << "3. Tinh dien tich tam giac" << endl;
}


int main()
{
    int option;
    TAMGIAC inp;
    
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
    } while (option < 1 || 3 < option);


    switch (option)
    {
        case 1:
        {
            InputTriangle(inp);

            cout << endl << "Tam giac vua nhap co toa do cac dinh la: ";
            PrintTriangle(inp);
            cout << endl;

            break;
        }

        case 2:
        {
            InputTriangle(inp);

            cout << endl << "Chu vi cua tam giac vua nhap la: " << inp.p << endl;

            break;
        }

        case 3:
        {
            InputTriangle(inp);

            cout << endl << "Dien tich cua tam giac vua nhap la: " << inp.s << endl;

            break;
        }
    }
    
    return 0;
}


/// ------------------------------------------------------------------------ ///
///                              InputTriangle()                             ///
/// ------------------------------------------------------------------------ ///
void InputTriangle(TAMGIAC &target)
{
    cout << endl;
    cout << "Nhap toa do diem A: "; cin >> target.a.x >> target.a.y;
    cout << "Nhap toa do diem B: "; cin >> target.b.x >> target.b.y;
    cout << "Nhap toa do diem C: "; cin >> target.c.x >> target.c.y;

    TriangleGenerator(target);

    if (target.legal == false)
    {
        cout << "Tam giac vua nhap khong hop le.";
        cout << endl;
        InputTriangle(target);
    }
    
    cout << endl;
}


/// ------------------------------------------------------------------------ ///
///                              PrintTriangle()                             ///
/// ------------------------------------------------------------------------ ///
void PrintTriangle(TAMGIAC inp)
{
    cout << "A(" << inp.a.x << ", " << inp.a.y << ")\t B(" << inp.b.x << ", " << inp.b.y << ")\t C(" << inp.c.x << ", " << inp.c.y << ")";
}


/// ------------------------------------------------------------------------ ///
///                                 PntDist()                                ///
/// ------------------------------------------------------------------------ ///
double PntDist(DIEM inp_1, DIEM inp_2)
{
    return sqrt(pow((inp_2.x - inp_1.x), 2) + pow((inp_2.y - inp_1.y), 2));
}


/// ------------------------------------------------------------------------ ///
///                            TriangleGenerator()                           ///
/// ------------------------------------------------------------------------ ///
void TriangleGenerator(TAMGIAC &target)
{
    target.ab = PntDist(target.a, target.b),
    target.bc = PntDist(target.b, target.c),
    target.ac = PntDist(target.a, target.c),

    target.p = target.ab + target.bc + target.ac,
    target.s = sqrt((target.p/2) * (target.p/2 - target.ab) * (target.p/2 - target.bc) * (target.p/2 - target.ac)),
    
    target.ah = 2*target.s / target.bc,
    target.bh = 2*target.s / target.ac,
    target.ch = 2*target.s / target.ab;

    target.legal = ((target.ab + target.bc > target.ac) && (target.ab + target.ac > target.bc) && (target.bc + target.ac > target.ab));
}