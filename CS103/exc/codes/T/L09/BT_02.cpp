#include <iostream>
#include <algorithm>            //? find()
#include <cmath>
#include <string>
#include <vector>
using namespace std;
using namespace std;



struct DONTHUC
{
    vector<float> degree,       // Bậc của đơn thức
                  elem;         // Cơ số của đơn thức
    vector<char>  sign;         // Dấu của đơn thức
};

DONTHUC dt_1, dt_2, dt_res;

void Extractor(string, DONTHUC &), GetElements(string, DONTHUC &), GetDegrees(string, DONTHUC &), GetSigns(string, DONTHUC &),
     FlipSign(DONTHUC &), MergeSign(DONTHUC &),
     Calculator(char), Dervative(DONTHUC, int, DONTHUC &),
     Sorter(DONTHUC &), Printer(DONTHUC);


void menu()
{
    cout << endl;
    cout << "============================== Menu ==============================" << endl;
    cout << "1. Nhap/Xuat don thuc           3. Tinh dao ham cap 1 cua don thuc" << endl;
    cout << "2. Tinh toan 2 don thuc (* /)   4. Tinh gia tri don thuc tai x=x0"  << endl;
}


int main()
{
    int option;
    string raw_inp_1, raw_inp_2;
    
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
    } while (option < 1 || 4 < option);

    cin.clear(); cin.sync();
    cout << endl << "----------------";
    cout << endl << "| Vi du: 8x^-7 |";
    cout << endl << "----------------" << endl;

    switch (option)
    {
        case 1:
        {
            cout << endl << "Nhap don thuc: "; getline(cin, raw_inp_1);
            
            Extractor(raw_inp_1, dt_1);
            Extractor("0", dt_2);

            Calculator('+');

            cout << endl << "Don thuc vua duoc nhap la: ";
            Printer(dt_res);
            cout << endl;

            break;
        }

        case 2:
        {
            char mode;

            cout << endl << "Nhap don thuc 1: "; getline(cin, raw_inp_1);
            cout << endl << "Nhap don thuc 2: "; getline(cin, raw_inp_2);
            do
            {
                cout << endl << "Nhap phep toan: ";
                cin >> mode;
            } while (mode != '*' && mode != '/');

            Extractor(raw_inp_1, dt_1);
            Extractor(raw_inp_2, dt_2);

            MergeSign(dt_1);
            MergeSign(dt_2);
            
            Calculator(mode);

            Sorter(dt_res);

            cout << endl << "= ";
            Printer(dt_res);
            cout << endl;

            break;
        }

        case 3:
        {
            cout << endl << "Nhap da thuc: "; getline(cin, raw_inp_1);
            
            Extractor(raw_inp_1, dt_res);
            Dervative(dt_res, 1, dt_res);

            cout << endl << "Dao ham cap 1 cua don thuc vua duoc nhap la: ";
            Printer(dt_res);
            cout << endl;

            break;
        }

        case 4:
        {
            int x;
            double res = 0;

            cout << endl << "Nhap don thuc: "; getline(cin, raw_inp_1);
            cout << "Nhap x0: "; cin >> x;
            
            Extractor(raw_inp_1, dt_1);
            MergeSign(dt_1);

            for (int i = 0; i < dt_1.elem.size(); i++)
            {
                if (dt_1.degree[i] != 0)
                    res += dt_1.elem[i] * pow(x, dt_1.degree[i]);
                
                else
                    res += dt_1.elem[i];
            }
            
            cout << endl << "= " << res;

            break;
        }
    }


    return 0;
}



/// ------------------------------------------------------------------------ ///
///                                Extractor()                               ///
/// ------------------------------------------------------------------------ ///
void Extractor(string inp, DONTHUC &target)
{
    GetElements(inp, target);
    GetDegrees(inp, target);
    GetSigns(inp, target);
}


/// -------------------------------------------------------------------------- ///
///                               GetElements()                                ///
/// -------------------------------------------------------------------------- ///
void GetElements(string inp, DONTHUC &target)
{
    inp += "\t";                                                                                                                //? Đánh dấu kết thúc chuỗi
    int cur;

    for (int i = 0; i < (inp.length() + 1); i++)                                                                                //? Loop chuỗi
    {
        if ((int(inp[i]) - 48) == 0 || (int(inp[i]) - 48) == 1 || (int(inp[i]) - 48) == 2 || (int(inp[i]) - 48) == 3 || (int(inp[i]) - 48) == 4 || (int(inp[i]) - 48) == 5 || (int(inp[i]) - 48) == 6 || (int(inp[i]) - 48) == 7 || (int(inp[i]) - 48) == 8 || (int(inp[i]) - 48) == 9)
        {
            int j = 1;
            
            cur = int(inp[i]) - 48;
            
            do                                                                                                                  //? Loop xác định cơ số
            {                                                                                                                   //! Xài do-while cho trường hợp ko có cơ số
                if (inp[i+j] == 'x')                                                                                            //? --- Nếu gặp x
                {
                    target.elem.push_back(cur);                                                                                //? ------ Append

                    j++;

                    if (inp[i+j] != '\t')
                    {
                        while (inp[i+j] != ' ' && inp[i+j] != '\t')                                                             //? ------ Đếm xem còn bao nhiêu vị trí nữa tới dấu cách tiếp theo (để skip qua x và bậc của nó)
                        {
                            j++;
                        }

                        i += j;
                        break;
                    }

                    else
                    {
                        break;
                    }
                }

                else if (inp[i+j] == ' ' || inp[i+j] == '\t')                                                                   //? --- Nếu gặp phải 2 kí tự này thì break và trả về cur
                {
                    i += j;

                    target.elem.push_back(cur);
                    break;
                }

                else                                                                                                            //? --- Các trg hợp còn lại chỉ có thể là số
                {
                    while ((int(inp[i+j]) - 48) == 0 || (int(inp[i+j]) - 48) == 1 || (int(inp[i+j]) - 48) == 2 || (int(inp[i+j]) - 48) == 3 || (int(inp[i+j]) - 48) == 4 || (int(inp[i+j]) - 48) == 5 || (int(inp[i+j]) - 48) == 6 || (int(inp[i+j]) - 48) == 7 || (int(inp[i+j]) - 48) == 8 || (int(inp[i+j]) - 48) == 9)
                    {
                        cur = cur*10 + int(inp[i+j]) - 48;
                        j++;
                    }

                    if (inp[i+j] == 'x')                                                                                        //? ------ Nếu gặp x
                    {
                        target.elem.push_back(cur);                                                                            //? --------- Làm tương tự bên trên

                        while (inp[i+j] != ' ')
                        {
                            j++;
                        }

                        i += j;                                                                                                 //! --------- Skip tới vị trí có dấu cách tiếp theo
                        break;
                    }

                    else                                                                                                        //? ------ Nếu không thì trả về luôn (trường hợp cho các số < 10)
                    {
                        i += j;

                        target.elem.push_back(cur);
                        break;
                    }
                }
                

            } while (inp[i+j] != ' ');
        }
    }
}


/// -------------------------------------------------------------------------- ///
///                                GetDegrees()                                ///
/// -------------------------------------------------------------------------- ///
void GetDegrees(string inp, DONTHUC &target)       //* Req: "20x^7 + 8x^-2 + 5x - 9"
{
    inp += "\t";                                                                                                                //? Đánh dấu kết thúc chuỗi
    int cur;

    for (int i = 0; i < (inp.length() + 1); i++)                                                                                //? Loop chuỗi
    {
        if ((int(inp[i]) - 48) == 0 || (int(inp[i]) - 48) == 1 || (int(inp[i]) - 48) == 2 || (int(inp[i]) - 48) == 3 || (int(inp[i]) - 48) == 4 || (int(inp[i]) - 48) == 5 || (int(inp[i]) - 48) == 6 || (int(inp[i]) - 48) == 7 || (int(inp[i]) - 48) == 8 || (int(inp[i]) - 48) == 9)
        {
            int j = 1;
            
            cur = 0;
            
            do                                                                                                                  //? Loop xác định bậc của cơ số
            {                                                                                                                   //! Xài do-while để cho trường hợp số ko có x
                if (inp[i+j] == 'x')                                                                                            //? --- Nếu gặp x
                {
                    if (inp[i+j+1] == '^')                                                                                      //? ------ Nếu có mũ
                    {
                        if (inp[i+j+2] == '-')                                                                                  //? --------- Nếu là số âm
                        {
                            cur = (int(inp[i+j+3]) - 48) * -1;
                            j += 3;
                        }

                        else                                                                                                    //? --------- Nếu là số dương
                        {
                            cur = int(inp[i+j+2]) - 48;
                            j += 2;
                        }

                        int k = 1;

                        if (inp[i+j+k] == '-')
                        {
                            cur *= -1;
                            k++;
                        }
                                                                                                                                //? ↙`-------- Loop xác định bậc x
                        while ((int(inp[i+j+k]) - 48) == 0 || (int(inp[i+j+k]) - 48) == 1 || (int(inp[i+j+k]) - 48) == 2 || (int(inp[i+j+k]) - 48) == 3 || (int(inp[i+j+k]) - 48) == 4 || (int(inp[i+j+k]) - 48) == 5 || (int(inp[i+j+k]) - 48) == 6 || (int(inp[i+j+k]) - 48) == 7 || (int(inp[i+j+k]) - 48) == 8 || (int(inp[i+j+k]) - 48) == 9)
                        {
                            cur = cur*10 + (int(inp[i+j+k]) - 48);
                            k++;
                        }

                        i += j + k;                                                                                             //! --------- Skip đến vị trí sau số mũ của x
                    }

                    else                                                                                                        //? ------ Nếu không có mũ
                    {
                        cur = 1;
                        i += j + 1;                                                                                             //! --------- Skip đến vị trí sau x
                    }

                    target.degree.push_back(cur);                                                                                        //? ------ Append
                    break;
                }

                else if (inp[i+j] == ' ' || inp[i+j] == '\t')                                                                   //? --- Nếu gặp phải 2 kí tự này thì break và ném về cur hiện tại (cho trường hợp chỉ có cơ số hoặc ^x ở cuối inp)
                {
                    target.degree.push_back(cur);
                    i += j;
                    break;
                }
                
                j++;

            } while (inp[i+j] != ' ');
        }
    }
}


/// -------------------------------------------------------------------------- ///
///                                 GetSigns()                                 ///
/// -------------------------------------------------------------------------- ///
void GetSigns(string inp, DONTHUC &target)
{
    for (int i = 0; i < inp.size(); i++)
    {
        if (i == 0 && inp[i] != '-')                                //? Cho trường hợp số đầu tiên là số dương
        {
            target.sign.push_back('+');

            for (int j = 0; j < inp.size(); j++)
            {
                if (inp[j+i+1] == ' ')
                {
                    i += j;
                    break;
                }
            }
            
        }

        else if (inp[i] == '+' || inp[i] == '-')
        {
            target.sign.push_back(inp[i]);
            
            for (int j = 0; j < inp.size(); j++)
            {
                if (inp[j+i+1] == ' ')
                {
                    i += j;
                    continue;
                }
            }
        }
    }
}


/// -------------------------------------------------------------------------- ///
///                                 FlipSign()                                 ///
/// -------------------------------------------------------------------------- ///
void FlipSign(DONTHUC &target)
{
    for (int i = 0; i < target.elem.size(); i++)
    {
        target.elem[i] = 0 - target.elem[i];
    }
    
    for (int i = 0; i < target.sign.size(); i++)
    {
        if (target.sign[i] == '+')
            target.sign[i] = '-';
        
        else
            target.sign[i] = '+';
    }
}


/// -------------------------------------------------------------------------- ///
///                                 MergeSign()                                ///
/// -------------------------------------------------------------------------- ///
void MergeSign(DONTHUC &target)
{
    for (int i = 0; i < target.elem.size(); i++)
    {
        if (target.sign[i] == '-')
        {
            target.elem[i] *= -1;
            target.sign[i] = '+';
        }
    }
}


/// -------------------------------------------------------------------------- ///
///                                Calculator()                                ///
/// -------------------------------------------------------------------------- ///
void Calculator(char mode)
{
    switch (mode)
    {
        case '*':
        {
            for (int i = 0; i < dt_1.elem.size(); i++)
            {
                for (int j = 0; j < dt_2.elem.size(); j++)
                {
                    dt_res.elem.push_back(dt_1.elem[i] * dt_2.elem[j]);
                    dt_res.degree.push_back(dt_1.degree[i] + dt_2.degree[j]);

                    dt_res.sign.push_back('+');
                }
            }

            for (int i = 0; i < dt_res.degree.size(); i++)
            {
                for (int j = i + 1; j < dt_res.degree.size();)
                {
                    if (dt_res.degree[j] == dt_res.degree[i])
                    {
                        dt_res.elem[i] += dt_res.elem[j];

                        dt_res.elem.erase(dt_res.elem.begin() + j);
                        dt_res.degree.erase(dt_res.degree.begin() + j);
                        dt_res.sign.erase(dt_res.sign.begin() + j);
                    }

                    else
                        j++;
                }
            }

            break;
        }
        
        case '/':
        {
            for (int i = 0; i < dt_1.elem.size(); i++)
            {
                for (int j = 0; j < dt_2.elem.size(); j++)
                {
                    dt_res.elem.push_back(dt_1.elem[i] / dt_2.elem[j]);
                    dt_res.degree.push_back(dt_1.degree[i] - dt_2.degree[j]);

                    dt_res.sign.push_back('+');
                }
            }

            for (int i = 0; i < dt_res.degree.size(); i++)
            {
                for (int j = i + 1; j < dt_res.degree.size();)
                {
                    if (dt_res.degree[j] == dt_res.degree[i])
                    {
                        dt_res.elem[i] += dt_res.elem[j];

                        dt_res.elem.erase(dt_res.elem.begin() + j);
                        dt_res.degree.erase(dt_res.degree.begin() + j);
                        dt_res.sign.erase(dt_res.sign.begin() + j);
                    }

                    else
                        j++;
                }
            }

            break;
        }
    }
}


/// ------------------------------------------------------------------------ ///
///                                Dervative()                               ///
/// ------------------------------------------------------------------------ ///
void Dervative(DONTHUC inp, int degree, DONTHUC &target)
{
    target = inp;

    for (int i = 0; i < degree; i++)
    {
        for (int j = 0; j < inp.elem.size(); j++)
        {
            if (target.degree[j] == 0)
            {
                target.elem.erase(inp.elem.begin() + j);
                target.degree.erase(inp.degree.begin() + j);
                target.sign.erase(inp.sign.begin() + j);

                j--;
            }

            else
            {
                target.elem[j] *= target.degree[j];
                target.degree[j]--;
            }
        }
    }
}


/// -------------------------------------------------------------------------- ///
///                                  Sorter()                                  ///
/// -------------------------------------------------------------------------- ///
void Sorter(DONTHUC &target)
{
//* Algo: Sort d_inp vào vector temp_d và loop vector đó để xác định vị trí tương ứng của giá trị đó trong d_inp để tìm giá trị e_inp tương ứng.
//*       Sau đó in ra temp_e.
    
    vector<float> temp_d, temp_e;
    temp_d = target.degree;

    sort(temp_d.begin(), temp_d.end(), greater<int>());
    
    for (int i = 0; i < temp_d.size(); i++)
    {
        for (int j = 0; j < target.degree.size(); j++)
        {
            if (temp_d[i] == target.degree[j])
            {
                temp_e.push_back(target.elem[j]);
                break;
            }
        }
    }


    if (find(temp_d.begin(), temp_d.end(), 0) != temp_d.end())                                                                     //? Chuyển số không có x về cuối
    {
        for (int i = 0; i < target.degree.size(); i++)
        {
            if (temp_d[i] == 0)
            {
                temp_e.push_back(temp_e[i]);
                temp_e.erase(temp_e.begin() + i);

                temp_d.push_back(temp_d[i]);
                temp_d.erase(temp_d.begin() + i);

                break;
            }
        }
    }

    target.elem = temp_e;
    target.degree = temp_d;
}


/// -------------------------------------------------------------------------- ///
///                                  Printer()                                 ///
/// -------------------------------------------------------------------------- ///
void Printer(DONTHUC target)
{
    bool first = true;

    for (int i = 0; i < target.elem.size(); i++)
    {
        if (target.elem[i] == 0)
            continue;

        else if (target.degree[i] == 1)
        {
            if (target.elem[i] == 1)
                first ? cout << "x " : cout << "+ x ";

            else if (target.elem[i] == -1)
                cout << "- x ";

            else if (target.elem[i] > 0 )
                first ? cout << target.elem[i] << "x " : cout << "+ " << target.elem[i] << "x ";
                
            else if (target.elem[i] < 0 )
                cout << "- " << target.elem[i] * (-1) << "x ";
            
            first = false;
        }

        else if (target.degree[i] < 0)
        {
            if (target.elem[i] == 1)
                first ? cout << "x^(" << target.degree[i] << ") " : cout << "+ x^(" << target.degree[i] << ") ";

            else if (target.elem[i] == -1)
                first ? cout << "- x^(" << target.degree[i] << ") " : cout << "- x^(" << target.degree[i] << ") ";

            else if (target.elem[i] > 0 )
                first ? cout <<  target.elem[i] << "x^(" << target.degree[i] << ") " : cout << "+ " << target.elem[i] << "x^(" << target.degree[i] << ") ";
                
            else if (target.elem[i] < 0 )
                cout << "- " << target.elem[i] * (-1) << "x^(" << target.degree[i] << ") ";
                
            first = false;
        }

        else if (target.degree[i] > 0)
        {
            if  (target.elem[i] == 1)
                first ? cout << "x " : cout << "+ x^" << target.degree[i] << " ";

            else if (target.elem[i] == -1)
                cout << "- x^" << target.degree[i] << " ";

            else if (target.elem[i] > 0 )
                first ? cout << target.elem[i] << "x^" << target.degree[i] << " " : cout << "+ " << target.elem[i] << "x^" << target.degree[i] << " ";
                
            else if (target.elem[i] < 0 )
                cout << "- " << target.elem[i] * (-1) << "x^" << target.degree[i] << " ";
                
            first = false;
        }

        else    //? target.degree[i] == 0
        {
            if (target.elem[i] > 0 )
                first ? cout << target.elem[i] << " " : cout << "+ " << target.elem[i] << " ";
                
            else if (target.elem[i] < 0 )
                cout << "- " << target.elem[i] * (-1) << " ";
                
            first = false;
        }
    }
}