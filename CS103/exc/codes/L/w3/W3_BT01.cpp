/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 01 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std; 

int main()
{
    int word_counter = 0;
    string str;

    cout << endl << "Nhap mot cau: ";
    getline(cin, str);

    for (int i = 0; i < str.length(); i++)
    {
        if (str.at(i) == ' ' || str.at(i) == '.')
        {
            word_counter += 1;
        }
    }

    cout << endl;
    cout << "So tu la: " << word_counter << endl;
    cout << "So ky tu la: " << str.size() << endl;
    
    return 0;
}