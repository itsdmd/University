#include <iostream>
#include <direct.h>
#include <fstream>
using namespace std;



ifstream reader;

string working_path()
{
    char temp[261];
    return (_getcwd(temp, sizeof(temp)) ? string(temp) : string(""));
}

const string dir = working_path() + "\\data.in";


struct DATA
{
    string name = "";
    int age = 0;
};

struct DATA_ARRAY
{
    int size = 0;
    DATA person[50];
};


DATA_ARRAY ReadData(), Sorter(DATA_ARRAY, char);



int main()
{
    cout << dir;
    DATA_ARRAY extracted = ReadData(),
               sorted;

    sorted = Sorter(extracted, 'a');
    cout << endl << "Nguoi co tuoi lon nhat ten la " << sorted.person[0].name << ", " << sorted.person[0].age << " tuoi";

    cout << endl << endl << "---------- Danh sach sau khi xep theo ten ----------";

    sorted = Sorter(extracted, 'n');
    for (int i = 0; i < extracted.size; i++)
        cout << endl << sorted.person[i].name << "\t\t" << sorted.person[i].age << " tuoi";


    return 0;
}



DATA_ARRAY ReadData()
{
    DATA_ARRAY outp;


    reader.open(dir);

    int counter = 0, elem_counter = 0;
    string content;

    if (reader.is_open())
    {
        while (getline(reader, content))
        {
            if (counter == 0)
            {
	            outp.size = stoi(content) / 2;          //!

                if (outp.size == 0)
                    break;

                else counter++;
            }

            else if (counter == 1)
            {
	            outp.person[elem_counter].name = content;
                counter++;
            }

            else if (counter == 2)
            {
	            outp.person[elem_counter].age = stoi(content);
                counter = 1;
                elem_counter++;
            }
        }

        reader.close();
    }

    else
	    outp.size = -1;


    return outp;
}

DATA_ARRAY Sorter(DATA_ARRAY inp, char mode)
{
    DATA_ARRAY outp;

    outp.size = inp.size;

    for (int i = 0; i < outp.size; i++)
        outp.person[i] = inp.person[i];

    switch (mode)
    {
        case 'a':                                                       // Increment
        {
            for(int i = 0; i < (outp.size - 1); i++)
            {
                for(int j = 0; j < (outp.size - i - 1); j++)
                {
                    if(outp.person[j].age < outp.person[j + 1].age)
                    {
                        DATA temp = outp.person[j];

                        outp.person[j] = outp.person[j + 1];
                        outp.person[j + 1] = temp;
                    }
                }
            }

            break;
        }

        case 'n':                                                       // Increment
        {
            for(int i = 0; i < (outp.size - 1); i++)
            {
                for(int j = 0; j < (outp.size - i - 1); j++)
                {
                    if(outp.person[j].name > outp.person[j + 1].name)
                    {
                        DATA temp = outp.person[j];

                        outp.person[j] = outp.person[j + 1];
                        outp.person[j + 1] = temp;
                    }
                }
            }

            break;
        }
    }

    return outp;
}