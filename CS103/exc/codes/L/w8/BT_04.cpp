/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSBOOK: 2159003 -----------------------------
------------------------------- Bài tập 04 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;



struct BOOK
{
    string name;
    int yr;
    string id, shelf;
};

typedef BOOK BOOK_ARR[200];


const string dir = "bk_dtb.txt";

ofstream writer;
ifstream reader;


void InputBook(BOOK &), PrintBook(BOOK),
     ArrayDeductor(BOOK_ARR &, int &, int), BookArraySorter(BOOK_ARR, int, char, char, BOOK_ARR &, int &),
     Reader(BOOK_ARR &, int &), Writer(BOOK_ARR, int);



void menu()
{
    cout << endl;
    cout << "========================= Menu =========================" << endl;
    cout << "1. Them sach               4. In ra tat ca cac sach" << endl;
    cout << "2. Xoa sach                5. Sap xep sach theo ID" << endl;
    cout << "3. Cap nhat ban ghi sach   6. Sap xep sach theo gia sach" << endl;
}


int main()
{
    BOOK inp;
    BOOK_ARR container;
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
            InputBook(inp);

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

            cout << "Nhap ID sach can xoa ban ghi: ";
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

                cout << endl << "Ban ghi cua sach co ID \"" << to_del << "\" da duoc xoa thanh cong" << endl;
            }
            
            else
                cout << endl << "Khong tim thay sach co ID \"" << to_del << "\" trong danh sach ban ghi" << endl;

            
            break;
        }

        case 3: case 5:
        {
            BookArraySorter(container, cont_size, 'i', 'i', container, cont_size);

            Writer(container, cont_size);

            cout << endl << "Cap nhat danh sach ban ghi thanh cong" << endl << "Danh sach duoc sap xep theo ID cua sach theo thu tu tang dan" << endl;


            break;
        }
        
        case 4:
        {
            for (int i = 0; i < cont_size; i++)
            {
                cout << endl << "===== Sach " << i+1 << " =====";
                PrintBook(container[i]);
            }

            break;
        }

        case 6:
        {
            BookArraySorter(container, cont_size, 'i', 's', container, cont_size);

            Writer(container, cont_size);

            cout << endl << "Cap nhat danh sach ban ghi thanh cong" << endl << "Danh sach duoc sap xep theo gia sach cua sach theo thu tu tang dan" << endl;


            break;
        }
    }
    
    return 0;
}



/// ------------------------------------------------------------------------ ///
///                               InputBook()                                ///
/// ------------------------------------------------------------------------ ///
void InputBook(BOOK &target)
{
    cin.clear(); cin.sync();

    cout << endl << "Nhap ten sach: ";
    getline(cin, target.name);

    cout << "Nhap nam xuat ban: ";
    cin >> target.yr;

    cout << "Nhap ID: ";
    cin >> target.id;

    cout << "Nhap gia sach: ";
    cin >> target.shelf;

    cout << endl;
}


/// ------------------------------------------------------------------------ ///
///                                PrintBook()                               ///
/// ------------------------------------------------------------------------ ///
void PrintBook(BOOK target)
{
    cout << endl << "Ten: " << target.name << endl << "Nam xuat ban: " << target.yr << endl << "ID: " << target.id << endl << "Gia sach: " << target.shelf << endl;
}


/// ------------------------------------------------------------------------ ///
///                              ArrayDeductor()                             ///
/// ------------------------------------------------------------------------ ///
void ArrayDeductor(BOOK_ARR &inp, int &size, int pos)
{
    for (int i = pos; i < size; i++)
        inp[i] = inp[i+1];

    size--;
}


/// ------------------------------------------------------------------------ ///
///                               BookArraySorter()                          ///
/// ------------------------------------------------------------------------ ///
void BookArraySorter(BOOK_ARR inp, int size_in, char mode, char criteria, BOOK_ARR &outp, int &size_out)
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
                            BOOK temp = outp[j];

                            outp[j] = outp[j + 1];
                            outp[j + 1] = temp;
                        }
                    }

                    else if (criteria == 's')
                    {
                        if(outp[j].shelf > outp[j + 1].shelf)
                        {
                            BOOK temp = outp[j];

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
                            BOOK temp = outp[j];

                            outp[j] = outp[j + 1];
                            outp[j + 1] = temp;
                        }
                    }

                    else if (criteria == 's')
                    {
                        if(outp[j].shelf < outp[j + 1].shelf)
                        {
                            BOOK temp = outp[j];

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
void Reader(BOOK_ARR &target, int &size)
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
                target[elem_counter].yr = stoi(content);
                counter++;
            }

            else if (counter == 3)
            {
                target[elem_counter].id = content;
                counter++;
            }

            else if (counter == 4)
            {
                target[elem_counter].shelf = content;
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
void Writer(BOOK_ARR inp, int size)
{
    writer.open(dir);

    writer << size;

    for (int i = 0; i < size; i++)
        writer << "\n" << inp[i].name << "\n" << inp[i].id << "\n" << inp[i].yr << "\n" << inp[i].shelf;
    
    writer.close();
}