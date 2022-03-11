/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 03 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;



struct SV
{
    string name, id;
    int age;
    float dtb;
};

typedef SV SV_ARR[200];


const string dir = "sv_dtb.txt";

ofstream writer;
ifstream reader;


void InputSV(SV &), PrintSV(SV),
     Scorers(SV_ARR, int, char, SV_ARR &, int &),
     ArrayDeductor(SV_ARR &, int &, int), SVArraySorter(SV_ARR, int, char, char, SV_ARR &, int &),
     Reader(SV_ARR &, int &), Writer(SV_ARR, int);



void menu()
{
    cout << endl;
    cout << "========================================= Menu =========================================" << endl;
    cout << "1. Them ban ghi sinh vien                    6. Hien thi cac sinh vien co DTB cao nhat" << endl;
    cout << "2. Xoa ban ghi sinh vien                     7. Hien thi cac sinh vien co DTB thap nhat" << endl;
    cout << "3. Cap nhat ban ghi sinh vien                8. Tim sinh vien theo ID" << endl;
    cout << "4. In ra tat ca ban ghi sinh vien            9. Sap xep ban ghi theo DTB" << endl;
    cout << "5. In ra diem trung binh cua mot sinh vien" << endl;
}


int main()
{
    SV inp;
    SV_ARR container;
    int option,
        inp_size = 0, cont_size = 0;
    
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
    } while (option < 1 || 9 < option);


    Reader(container, cont_size);

    if (cont_size == -1)
    {
        ofstream new_file(dir);
        new_file.close();

        cont_size = 0;
    }


    cout << endl;

    switch (option)
    {
        case 1:
        {
            InputSV(inp);

            container[cont_size] = inp;
            cont_size++;

            Writer(container, cont_size);

            cout << endl << "Them ban ghi thanh cong" << endl;


            break;
        }

        case 2:
        {
            bool found = false;
            string to_del;

            cout << "Nhap ID sinh vien can xoa ban ghi: ";
            cin >> to_del;

            for (int i = 0; i < cont_size; i++)
            {
                if (container[i].id == to_del)
                {
                    found = true;
                    
                    ArrayDeductor(container, cont_size, i);

                    break;
                }
            }

            if (found)
            {
                Writer(container, cont_size);

                cout << endl << "Ban ghi cua sinh vien co ID \"" << to_del << "\" da duoc xoa thanh cong" << endl;
            }
            
            else
                cout << endl << "Khong tim thay sinh vien co ID \"" << to_del << "\" trong danh sach ban ghi" << endl;

            
            break;
        }

        case 3:
        {
            SVArraySorter(container, cont_size, 'i', 'i', container, cont_size);

            Writer(container, cont_size);

            cout << endl << "Cap nhat danh sach ban ghi thanh cong" << endl << "Danh sach duoc sap xep theo ID cua sinh vien theo thu tu tang dan" << endl;


            break;
        }

        case 4:
        {
            for (int i = 0; i < cont_size; i++)
            {
                cout << endl << "===== SV " << i+1 << " =====";
                PrintSV(container[i]);
            }

            break;
        }

        case 5:
        {
            bool found = false;
            SV to_find;
            string to_find_id;

            cout << "Nhap ID sinh vien can tra diem trung binh: ";
            cin >> to_find_id;

            for (int i = 0; i < cont_size; i++)
            {
                if (container[i].id == to_find_id)
                {
                    found = true;
                    to_find = container[i];

                    break;
                }
            }

            if (found)
                cout << endl << "Diem trung binh cua sinh vien co ID \"" << to_find_id << "\" la " << to_find.dtb << endl;
            
            else
                cout << endl << "Khong tim thay sinh vien co ID \"" << to_find_id << "\" trong danh sach ban ghi" << endl;


            break;
        }

        case 6:
        {
            SV_ARR top;
            int top_size;

            Scorers(container, cont_size, 'M', top, top_size);

            cout << endl << top_size << " sinh vien co DTB cao nhat la: ";
            for (int i = 0; i < top_size; i++)
            {
                cout << endl << "===== [" << i+1 << "] =====";
                PrintSV(top[i]);
            }


            break;
        }

        case 7:
        {
            SV_ARR bot;
            int bot_size;

            Scorers(container, cont_size, 'm', bot, bot_size);

            cout << endl << bot_size << " sinh vien co DTB thap nhat la: ";
            for (int i = 0; i < bot_size; i++)
            {
                cout << endl << "===== [" << i+1 << "] =====";
                PrintSV(bot[i]);
            }


            break;
        }

        case 8:
        {
            bool found = false;
            SV to_find;
            string to_find_id;

            cout << "Nhap ID sinh vien can tra: ";
            cin >> to_find_id;

            for (int i = 0; i < cont_size; i++)
            {
                if (container[i].id == to_find_id)
                {
                    found = true;
                    to_find = container[i];

                    break;
                }
            }

            if (found)
            {
                cout << endl << "Thong tin sinh vien:";
                PrintSV(to_find);
            }
            
            else
                cout << endl << "Khong tim thay sinh vien co ID " << to_find_id << " trong danh sach ban ghi" << endl;


            break;
        }

        case 9:
        {
            SVArraySorter(container, cont_size, 'i', 'd', container, cont_size);

            Writer(container, cont_size);

            cout << endl << "Cap nhat danh sach ban ghi thanh cong" << endl << "Danh sach duoc sap xep theo diem trung binh cua sinh vien theo thu tu tang dan" << endl;


            break;
        }
    }
    
    return 0;
}



/// ------------------------------------------------------------------------ ///
///                                 InputSV()                                ///
/// ------------------------------------------------------------------------ ///
void InputSV(SV &target)
{
    cin.clear(); cin.sync();

    cout << endl << "Nhap ten sinh vien: ";
    getline(cin, target.name);

    cout << "Nhap ID: ";
    cin >> target.id;

    cout << "Nhap tuoi: ";
    cin >> target.age;

    cout << "Nhap diem trung binh: ";
    cin >> target.dtb;

    cout << endl;
}


/// ------------------------------------------------------------------------ ///
///                                 PrintSV()                                ///
/// ------------------------------------------------------------------------ ///
void PrintSV(SV target)
{
    cout << endl << "Ten: " << target.name << endl << "ID: " << target.id << endl << "Tuoi: " << target.age << endl << "Diem TB: " << target.dtb << endl;
}


/// ------------------------------------------------------------------------ ///
///                                 Scorers()                                ///
/// ------------------------------------------------------------------------ ///
void Scorers(SV_ARR inp, int size, char mode, SV_ARR &res, int &res_size)
{
    SV_ARR mins, maxes;
    int mins_size = 0, maxes_size = 0;

    SV min = inp[0], max = inp[0];

    for (int i = 0; i < size; i++)
    {
        if (inp[i].dtb < min.dtb)
            min = inp[i];
        
        if (inp[i].dtb > max.dtb)
            max = inp[i];
    }

    for (int i = 0; i < size; i++)
    {
        if (inp[i].dtb == min.dtb)
        {
            mins[mins_size] = inp[i];
            mins_size++;
        }
        
        else if (inp[i].dtb == max.dtb)
        {
            maxes[maxes_size] = inp[i];
            maxes_size++;
        }
    }

    switch (mode)
    {
        case 'm':
        {
            res_size = mins_size;

            for (int i = 0; i < mins_size; i++)
                res[i] = mins[i];
            

            break;
        }
        
        case 'M':
        {
            res_size = maxes_size;

            for (int i = 0; i < maxes_size; i++)
                res[i] = maxes[i];
            

            break;
        }
    }
}


/// ------------------------------------------------------------------------ ///
///                              ArrayDeductor()                             ///
/// ------------------------------------------------------------------------ ///
void ArrayDeductor(SV_ARR &inp, int &size, int pos)
{
    for (int i = pos; i < size; i++)
        inp[i] = inp[i+1];

    size--;
}


/// ------------------------------------------------------------------------ ///
///                               SVArraySorter()                            ///
/// ------------------------------------------------------------------------ ///
void SVArraySorter(SV_ARR inp, int size_in, char mode, char criteria, SV_ARR &outp, int &size_out)
{
    int cur_pos = 0;

    size_out = size_in;

    for (int i = 0; i < size_in; i++)
        outp[i] = inp[i];

    switch (mode)
    {
        case 'i':                                                       // Increment
        {
            for(int i = 0; i < (size_in - 1); i++)
            {
                for(int j = 0; j < (size_in - i - 1); j++)
                {
                    if (criteria == 'i')
                    {
                        if(outp[j].id > outp[j + 1].id)
                        {
                            SV temp = outp[j];

                            outp[j] = outp[j + 1];
                            outp[j + 1] = temp;
                        }
                    }

                    else if (criteria == 'd')
                    {
                        if(outp[j].dtb > outp[j + 1].dtb)
                        {
                            SV temp = outp[j];

                            outp[j] = outp[j + 1];
                            outp[j + 1] = temp;
                        }
                    }
                }
            }

            break;
        }

        case 'd':                                                       // Decrement
        {
            for (int i = 0; i < size_out; i++)
            {
                for (int j = i + 1; j < size_out; j++)
                {
                    if (criteria == 'i')
                    {
                        if(outp[j].id < outp[j + 1].id)
                        {
                            SV temp = outp[j];

                            outp[j] = outp[j + 1];
                            outp[j + 1] = temp;
                        }
                    }

                    else if (criteria == 'd')
                    {
                        if(outp[j].dtb < outp[j + 1].dtb)
                        {
                            SV temp = outp[j];

                            outp[j] = outp[j + 1];
                            outp[j + 1] = temp;
                        }
                    }
                }
            }

            break;
        }
    }
}


/// ------------------------------------------------------------------------ ///
///                                 Reader()                                 ///
/// ------------------------------------------------------------------------ ///
void Reader(SV_ARR &target, int &size)
{
    reader.open(dir);

    int counter = 0, elem_counter = 0;
    string content;

    if (reader.is_open())
    {
        while (getline(reader, content))
        {
            if (counter == 0)
            {
                size = stoi(content);
                counter++;
            }

            else if (counter == 1)
            {
                target[elem_counter].name = content;
                counter++;
            }

            else if (counter == 2)
            {
                target[elem_counter].id = content;
                counter++;
            }

            else if (counter == 3)
            {
                target[elem_counter].age = stoi(content);
                counter++;
            }

            else if (counter == 4)
            {
                target[elem_counter].dtb = stof(content);
                counter = 1;
                elem_counter++;
            }
        }
    }

    else
        size = -1;
}


/// ------------------------------------------------------------------------ ///
///                                 Writer()                                 ///
/// ------------------------------------------------------------------------ ///
void Writer(SV_ARR inp, int size)
{
    writer.open(dir);

    writer << size;

    for (int i = 0; i < size; i++)
        writer << "\n" << inp[i].name << "\n" << inp[i].id << "\n" << inp[i].age << "\n" << inp[i].dtb;
    
    writer.close();
}