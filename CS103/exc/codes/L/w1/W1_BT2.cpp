/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
-------------------------------- Bài tập 2 -------------------------------
------------------------------------------------------------------------*/


#include<stdio.h>
#include<string>
using namespace std;

string str = "C Language Basic Syntax Rules:\n\"\n1.	Lowercase letters are significant\n2.	main is where program execution begins\n3.	Opening and closing braces enclose program statements in a routine\n4.	All program statements must be terminated by a semicolon\"";

int main()
{
    printf("%s", str.c_str());
    return 0;
}