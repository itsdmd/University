/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 02 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <direct.h>
#include <string>
#include <fstream>
using namespace std;


string working_path()
{
    char temp[261];
    return (_getcwd(temp, sizeof(temp)) ? string(temp) : string(""));
}

const string target_dir = working_path() + "\\NguyenTo.txt";

bool IsPrime(int);



int main()
{
    string to_write = "", sep = " ";
    int latest = 0;

    for (int i = 0; i < 50; i++)
    {
        int cur = latest + 1;

        while (IsPrime(cur) == false)
            cur++;
        
        latest = cur;
        to_write = to_write + to_string(latest);

        if (i != 49)
            to_write += " ";
    }

    ofstream writer;

    writer.open(target_dir);

    writer << to_write;

    writer.close();
    
    return 0;
}



bool IsPrime(int inp)
{
    if (inp < 2)
        return false;
    
    int checkPnt = 0;
    checkPnt = inp/2;

    for(int i = 2; i <= checkPnt; i++)
    {  
        if(inp % i == 0)
        {  
            return false;
        }
    }

    return true;
}