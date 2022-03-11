#include <iostream>
#include <cmath>
using namespace std;



struct DIEM {double x, y;};

const DIEM ORIGIN{0,0};

typedef DIEM PNT_ARR[200];


bool IsSimilar(DIEM, DIEM);

int Quarter(DIEM), NumOfUniquePoint(PNT_ARR, int);

double PntDist(DIEM, DIEM);

DIEM SymmAboutOrigin(DIEM);

void PntArrInput(PNT_ARR &, int &), PntArrPrinter(PNT_ARR, int),
     PntInput(DIEM &), PntPrinter(DIEM);


void menu()
{
    cout << endl;
    cout << "================================== Menu ==================================" << endl;
    cout << "1. Nhap/Xuat mang diem                    4. Tim diem co hoanh do lon nhat" << endl;
    cout << "2. Dem so luong diem co hoanh do duong    5. Tim diem co hoanh do nho nhat" << endl;
    cout << "3. Dem so luong diem doc nhat             6. Tim diem gan goc toa do nhat"  << endl;
}


int main()
{
    int option,
        size_1, size_2;
    PNT_ARR inp_1, inp_2;
    
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
    } while (option < 1 || 6 < option);


    PntArrInput(inp_1, size_1);

    switch (option)
    {
        case 1:
        {
            cout << endl << "Mang vua nhap la: ";
            PntArrPrinter(inp_1, size_1);
            cout << endl;

            break;
        }

        case 2:
        {
            int counter = 0;

            for (int i = 0; i < size_1; i++)
            {
                if (inp_1[i].x > 0)
                    counter++;
            }

            if (counter == 0)
                cout << endl << "Mang khong co diem nao co hoanh do duong" << endl;
            
            else
                cout << endl << "Mang co " << counter << " diem co hoanh do duong" << endl;
            
            break;
        }

        case 3:
        {
            if (NumOfUniquePoint(inp_1, size_1) == 0)
                cout << endl << "Mang khong co diem nao doc nhat";
            else
                cout << endl << "Mang co " << NumOfUniquePoint(inp_1, size_1) << " diem doc nhat" << endl;

            break;
        }

        case 4:
        {
            double max_x = inp_1[0].x;
            double max_y = inp_1[0].y;

            for (int i = 0; i < size_1; i++)
            {
                if (inp_1[i].x > max_x)
                {
                    max_x = inp_1[i].x;
                    max_y = inp_1[i].y;
                }
            }

            cout << endl << "Diem co hoanh do lon nhat trong mang la: ";
            PntPrinter({max_x, max_y});
            cout << endl;

            break;
        }

        case 5:
        {
            double min_x = inp_1[0].x;
            double min_y = inp_1[0].y;

            for (int i = 0; i < size_1; i++)
            {
                if (inp_1[i].x < min_x)
                {
                    min_x = inp_1[i].x;
                    min_y = inp_1[i].y;
                }
            }

            cout << endl << "Diem co hoanh do nho nhat trong mang la: ";
            PntPrinter({min_x, min_y});
            cout << endl;

            break;
        }

        case 6:
        {
            DIEM closest = inp_1[0];

            for (int i = 1; i < size_1; i++)
            {
                if (PntDist(inp_1[i], ORIGIN) < PntDist(closest, ORIGIN))
                    closest = inp_1[i];
            }

            cout << endl << "Diem gan goc toa do nhat la: ";
            PntPrinter(closest);
            cout << endl;

            break;
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
///                               PntPrinter()                               ///
/// ------------------------------------------------------------------------ ///
void PntPrinter(DIEM target)
{
    cout << "(" << target.x << ", " << target.y << ")";
}

/// ------------------------------------------------------------------------ ///
///                               PntArrInput()                              ///
/// ------------------------------------------------------------------------ ///
void PntArrInput(PNT_ARR &target, int &size)
{
    do
    {
        cout << endl << "Nhap so phan tu cua mang: ";
        cin >> size;

    } while(size <= 0);

    for (int i = 0; i < size; i++)
    {
        cout << "===== Diem " << i+1 << " =========";
        PntInput(target[i]);
    }
}


/// ------------------------------------------------------------------------ ///
///                              PntArrPrinter()                             ///
/// ------------------------------------------------------------------------ ///
void PntArrPrinter(PNT_ARR inp, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << endl << "[" << i+1 << "] = ";
        PntPrinter(inp[i]);
    }

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


/// ------------------------------------------------------------------------ ///
///                            NumOfUniquePoint()                            ///
/// ------------------------------------------------------------------------ ///
int NumOfUniquePoint(PNT_ARR inp, int size)
{
    int counter = 0, unique_size = 0, non_unique_size = 0;

    PNT_ARR unique, non_unique;

    for (int i = 0; i < size; i++)
    {
        bool found = false;
        
        if (i == size - 1)
        {
            for (int k = 0; k < non_unique_size; k++)
            {
                if (IsSimilar(inp[i], non_unique[k]))
                {
                    found = true;
                    break;
                }
            }

            if (found == false)
            {
                unique[unique_size] = inp[i];
                unique_size++;

                counter++;
            }
        }

        else
        {
            for (int j = (i + 1); j < size; j++)
            {
                if (IsSimilar(inp[i], inp[j]))
                {
                    found = true;

                    non_unique[non_unique_size] = inp[i];
                    non_unique_size++;

                    break;
                }
            }

            if (found == false)
            {
                for (int k = 0; k < non_unique_size; k++)
                {
                    if (IsSimilar(inp[i], non_unique[k]))
                    {
                        found = true;
                        break;
                    }
                }

                if (found == false)
                {
                    unique[unique_size] = inp[i];
                    unique_size++;

                    counter++;
                }
            }
        }
    }

    return counter;
}


/// ------------------------------------------------------------------------ ///
///                                IsSimilar()                               ///
/// ------------------------------------------------------------------------ ///
bool IsSimilar(DIEM inp_1, DIEM inp_2)
{
    if (inp_1.x == inp_2.x && inp_1.y == inp_2.y)
        return true;
    
    else
        return false;
}