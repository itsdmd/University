/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 03 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;



void TriangleCornerCalc(float, float, float, float &, float &, float &), TriangleHeightCalc(float, float, float, float &, float &, float &);

int main()
{
    float AB, BC, AC,       // Sides
        AH, BH, CH,         // Heights
        A, B, C;            // Corners

    do
    {
        do
        {
            cout << endl << "Nhap do dai canh AB: ";
            cin >> AB;
        } while (AB < 1);

        do
        {
            cout << endl << "Nhap do dai canh BC: ";
            cin >> BC;
        } while (BC < 1);

        do
        {
            cout << endl << "Nhap do dai canh AC: ";
            cin >> AC;
        } while (AC < 1);

        if (((AB + BC) < AC) || ((BC + AC) < AB) || ((AB + AC) < BC))
        {
            cout << endl << "Tam giac khong hop le" << endl;
        }
    } while (((AB + BC) < AC) || ((BC + AC) < AB) || ((AB + AC) < BC));

    TriangleCornerCalc(AB, BC, AC, A, B, C);
    TriangleHeightCalc(AB, BC, AC, AH, BH, CH);

    cout << endl << "Goc A = " << A << "º  |  Goc B = " << B << "º  |  Goc C = " << C << "º";
    cout << endl << "AH = " << AH << "  |  BH = " << BH << "  |  CH = " << CH << endl;
    
    return 0;
}



/// -------------------------------------------------------------------------- ///
///                            TriangleCornerCalc()                            ///
/// -------------------------------------------------------------------------- ///
void TriangleCornerCalc(float AB, float BC, float AC, float &A, float &B, float &C)
{
    A = acos((AB*AB + AC*AC - BC*BC) / (2*AB*AC)) * (180.0/M_PI);
    B = acos((AB*AB + BC*BC - AC*AC) / (2*AB*BC)) * (180.0/M_PI);
    C = acos((BC*BC + AC*AC - AB*AB) / (2*BC*AC)) * (180.0/M_PI);
}

/// -------------------------------------------------------------------------- ///
///                            TriangleHeightCalc()                            ///
/// -------------------------------------------------------------------------- ///
void TriangleHeightCalc(float AB, float BC, float AC, float &AH, float &BH, float &CH)
{
    float p = (AB + BC + AC) / 2;
    AH = 2*(sqrt(p * (p-AB) * (p - BC) * (p - AC))) / BC;
    BH = 2*(sqrt(p * (p-AB) * (p - BC) * (p - AC))) / AC;
    CH = 2*(sqrt(p * (p-AB) * (p - BC) * (p - AC))) / AB;
}