/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 01 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <direct.h>
#include <string>
#include <fstream>
using namespace std;


ifstream reader;


string working_path()
{
    char temp[261];
    return (_getcwd(temp, sizeof(temp)) ? string(temp) : string(""));
}

const string input_dir = working_path() + "\\input.txt";

int *GetNumbers(int, string);

void ReadData(int &, string &);



int main()
{
    int size;
    string inp;

    ReadData(size, inp);

    int *nums = new int[size];
    nums = GetNumbers(size, inp);

    cout << endl << "Cac gia tri chan trong file inPut.txt la: ";

    for (int i = 0; i < size; i++)
        if (nums[i] % 2 == 0)
            cout << nums[i] << " ";
    
    cout << endl;
    
    return 0;
}


void ReadData(int &size, string &res)
{
    reader.open(input_dir);
    string temp;

    getline(reader, temp);
    size = stoi(temp);
    
    getline(reader, res);

    reader.close();
}

int *GetNumbers(int size, string inp)
{
    int *nums = new int[size];
    int counter = 0;
    string temp;

    for (int i = 0; i < inp.length(); i++)
    {
        if (inp[i] == ' ')
        {
            nums[counter] = stoi(temp);

            counter++;
            temp = "";
        }

        else
            temp += inp[i];
    }

    return nums;
}