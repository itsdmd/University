/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
-------------------------------- Bài tập 5 -------------------------------
------------------------------------------------------------------------*/


#include<iostream>
#include<string>
using namespace std;

//Reference: https://en.wikipedia.org/wiki/Code_page_437
const char a_grave = 133;       //? à

string hello_1  = "Xin ch";
string hello_2  = "o";
string tab      = "       ";    //? 7*<space>
string ribbon   = "************************";


int main()
{
    cout << tab << ribbon << "\n" << tab << "*" << tab << hello_1 << a_grave << hello_2 << tab << "*" << "\n" << tab << ribbon;
    return 0;
}