#include <iostream>
#include <algorithm>            //? find()
#include <cmath>
#include <string>
#include <vector>
using namespace std;
using namespace std;



struct DATHUC
{
    vector<float> degrees,       // Các bậc có trong đa thức
                  elems;         // Chứa cơ số của mỗi bậc của đa thức
    vector<char>  signs;         // Chứa dấu (+/-) của mỗi cơ số của đa thức
};

DATHUC dt_1, dt_2, dt_res;

void Extractor(string, DATHUC &), GetElements(string, DATHUC &), GetDegrees(string, DATHUC &), GetSigns(string, DATHUC &),
     FlipSign(DATHUC &), MergeSign(DATHUC &),
     Calculator(char), Dervative(DATHUC, int, DATHUC &),
     Sorter(DATHUC &), Printer(DATHUC);


void menu()
{
    cout << endl;
    cout << "================================= Menu =================================" << endl;
    cout << "1. Nhap/Xuat da thuc                  4. Tinh dao ham cap k cua don thuc" << endl;
    cout << "2. Tinh toan 2 don thuc               5. Tinh gia tri don thuc tai x=x0"  << endl;
    cout << "3. Tinh dao ham cap 1 cua don thuc" << endl;
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
    } while (option < 1 || 5 < option);

    cin.clear(); cin.sync();
    cout << endl << "-------------------------";
    cout << endl << "| Vi du: 8x^-7 + 5x - 2 |";
    cout << endl << "-------------------------" << endl;

    switch (option)
    {
        case 1:
        {
            cout << endl << "Nhap da thuc: "; getline(cin, raw_inp_1);
            
            Extractor(raw_inp_1, dt_1);
            Extractor("0", dt_2);

            Calculator('+');

            cout << endl << "Da thuc vua duoc nhap la: ";
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
            } while (mode != '+' && mode != '-' && mode != '*' && mode != '/');

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
            int degree;

            cout << endl << "Nhap da thuc: "; getline(cin, raw_inp_1);
            
            do
            {
                cout << "Nhap cap dao ham k: ";
                cin >> degree;
            } while (degree < 0);
            
            Extractor(raw_inp_1, dt_res);
            Dervative(dt_res, degree, dt_res);

            cout << endl << "Dao ham cap " << degree << " cua don thuc vua duoc nhap la: ";
            Printer(dt_res);
            cout << endl;

            break;
        }

        case 5:
        {
            int x;
            double res = 0;

            cout << endl << "Nhap da thuc: "; getline(cin, raw_inp_1);
            cout << "Nhap x0: "; cin >> x;
            
            Extractor(raw_inp_1, dt_1);
            MergeSign(dt_1);

            for (int i = 0; i < dt_1.elems.size(); i++)
            {
                if (dt_1.degrees[i] != 0)
                    res += dt_1.elems[i] * pow(x, dt_1.degrees[i]);
                
                else
                    res += dt_1.elems[i];
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
void Extractor(string inp, DATHUC &target)
{
    GetElements(inp, target);
    GetDegrees(inp, target);
    GetSigns(inp, target);
}


/// -------------------------------------------------------------------------- ///
///                               GetElements()                                ///
/// -------------------------------------------------------------------------- ///
void GetElements(string inp, DATHUC &target)
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
                    target.elems.push_back(cur);                                                                                //? ------ Append

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

                    target.elems.push_back(cur);
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
                        target.elems.push_back(cur);                                                                            //? --------- Làm tương tự bên trên

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

                        target.elems.push_back(cur);
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
void GetDegrees(string inp, DATHUC &target)       //* Req: "20x^7 + 8x^-2 + 5x - 9"
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

                    target.degrees.push_back(cur);                                                                                        //? ------ Append
                    break;
                }

                else if (inp[i+j] == ' ' || inp[i+j] == '\t')                                                                   //? --- Nếu gặp phải 2 kí tự này thì break và ném về cur hiện tại (cho trường hợp chỉ có cơ số hoặc ^x ở cuối inp)
                {
                    target.degrees.push_back(cur);
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
void GetSigns(string inp, DATHUC &target)
{
    for (int i = 0; i < inp.size(); i++)
    {
        if (i == 0 && inp[i] != '-')                                //? Cho trường hợp số đầu tiên là số dương
        {
            target.signs.push_back('+');

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
            target.signs.push_back(inp[i]);
            
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
void FlipSign(DATHUC &target)
{
    for (int i = 0; i < target.elems.size(); i++)
    {
        target.elems[i] = 0 - target.elems[i];
    }
    
    for (int i = 0; i < target.signs.size(); i++)
    {
        if (target.signs[i] == '+')
            target.signs[i] = '-';
        
        else
            target.signs[i] = '+';
    }
}


/// -------------------------------------------------------------------------- ///
///                                 MergeSign()                                ///
/// -------------------------------------------------------------------------- ///
void MergeSign(DATHUC &target)
{
    for (int i = 0; i < target.elems.size(); i++)
    {
        if (target.signs[i] == '-')
        {
            target.elems[i] *= -1;
            target.signs[i] = '+';
        }
    }
}


/// -------------------------------------------------------------------------- ///
///                                Calculator()                                ///
/// -------------------------------------------------------------------------- ///
void Calculator(char mode)
{
//* Algo: Loop d_1, với mỗi giá trị của d_1 thì xác định xem bậc đó đã xét chưa.
//*       Chưa thì thêm vào res_d và loop d_2 để xác định vị trí các cơ số chung bậc trong e_2 để cộng/trừ vào element tương ứng trong res_e, 
//*       rồi thì loop trong d_1 để tìm vị trí của cơ số của bậc đang xét trong e_1 để cộng/trừ vào res_e; nếu không tìm thấy số nào thì ném chính nó vào res_e luôn. 
//*       Sau đó làm tương tự cho d_2 nhưng với d2 thì nếu có trong checked rồi thì skip do loop đầu đã cộng đủ.

    switch (mode)
    {
        case '+':
        {
            for (int i = 0; i < dt_1.degrees.size(); i++)                                                                                        
            {
                if (find(dt_res.degrees.begin(), dt_res.degrees.end(), dt_1.degrees[i]) == dt_res.degrees.end())                        //? Nếu bậc này chưa được xét
                {
                    dt_res.degrees.push_back(dt_1.degrees[i]);

                    bool found = false;

                    for (int j = 0; j < dt_2.degrees.size(); j++)                                                                       //? --- Tìm trong dt_2
                    {
                        if (dt_2.degrees[j] == dt_1.degrees[i])
                        {
                            found = true;

                            int temp_1 = 0, temp_2 = 0, temp_res = 0;

                            temp_1 += dt_1.elems[i];
                            temp_2 += dt_2.elems[j];
                            
                            temp_res = temp_1 + temp_2;

                            dt_res.elems.push_back(temp_res);
                        }
                    }

                    if (found == false)                                                                                                 //? --- Nếu không tìm thấy số cùng bậc trong dt_2
                        dt_res.elems.push_back(dt_1.elems[i]);
                }

                else                                                                                                                    //? Nếu được xét rồi
                {
                    int pos;

                    for (int j = 0; j < dt_1.degrees.size(); j++)
                    {
                        if (dt_1.degrees[i] == dt_res.degrees[j])                                                                       //? --- Xác định vị trí trong dt_res.degrees (vì sẽ tương ứng vị trí của tổng các cơ số lưu trong dt_res.elements)
                        {
                            pos = j;
                            break;
                        }
                    }

                    dt_res.elems[pos] += dt_1.elems[i];
                }
            }
            
            for (int i = 0; i < dt_2.degrees.size(); i++)                                                                                        
            {
                if (find(dt_res.degrees.begin(), dt_res.degrees.end(), dt_2.degrees[i]) == dt_res.degrees.end())
                {
                    dt_res.degrees.push_back(dt_2.degrees[i]);

                    bool found = false;

                    for (int j = 0; j < dt_1.degrees.size(); j++)
                    {
                        if (dt_1.degrees[j] == dt_2.degrees[i])
                        {
                            found = true;

                            int temp_1 = 0, temp_2 = 0, temp_res = 0;

                            temp_1 += dt_2.elems[i];
                            temp_2 += dt_1.elems[j];
                            
                            temp_res = temp_1 + temp_2;

                            dt_res.elems.push_back(temp_res);
                        }
                    }

                    if (found == false)
                        dt_res.elems.push_back(dt_2.elems[i]);
                }

                else
                {
                    continue;
                }
            }

            break;
        }

        case '-':
        {
            FlipSign(dt_2);
            Calculator('+');

            break;
        }
        
        case '*':
        {
            for (int i = 0; i < dt_1.elems.size(); i++)
            {
                for (int j = 0; j < dt_2.elems.size(); j++)
                {
                    dt_res.elems.push_back(dt_1.elems[i] * dt_2.elems[j]);
                    dt_res.degrees.push_back(dt_1.degrees[i] + dt_2.degrees[j]);

                    dt_res.signs.push_back('+');
                }
            }

            for (int i = 0; i < dt_res.degrees.size(); i++)
            {
                for (int j = i + 1; j < dt_res.degrees.size();)
                {
                    if (dt_res.degrees[j] == dt_res.degrees[i])
                    {
                        dt_res.elems[i] += dt_res.elems[j];

                        dt_res.elems.erase(dt_res.elems.begin() + j);
                        dt_res.degrees.erase(dt_res.degrees.begin() + j);
                        dt_res.signs.erase(dt_res.signs.begin() + j);
                    }

                    else
                        j++;
                }
            }

            break;
        }
        
        case '/':
        {
            for (int i = 0; i < dt_1.elems.size(); i++)
            {
                for (int j = 0; j < dt_2.elems.size(); j++)
                {
                    dt_res.elems.push_back(dt_1.elems[i] / dt_2.elems[j]);
                    dt_res.degrees.push_back(dt_1.degrees[i] - dt_2.degrees[j]);

                    dt_res.signs.push_back('+');
                }
            }

            for (int i = 0; i < dt_res.degrees.size(); i++)
            {
                for (int j = i + 1; j < dt_res.degrees.size();)
                {
                    if (dt_res.degrees[j] == dt_res.degrees[i])
                    {
                        dt_res.elems[i] += dt_res.elems[j];

                        dt_res.elems.erase(dt_res.elems.begin() + j);
                        dt_res.degrees.erase(dt_res.degrees.begin() + j);
                        dt_res.signs.erase(dt_res.signs.begin() + j);
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
void Dervative(DATHUC inp, int degree, DATHUC &target)
{
    target = inp;

    for (int i = 0; i < degree; i++)
    {
        for (int j = 0; j < inp.elems.size(); j++)
        {
            if (target.degrees[j] == 0)
            {
                target.elems.erase(inp.elems.begin() + j);
                target.degrees.erase(inp.degrees.begin() + j);
                target.signs.erase(inp.signs.begin() + j);

                j--;
            }

            else
            {
                target.elems[j] *= target.degrees[j];
                target.degrees[j]--;
            }
        }
    }
}


/// -------------------------------------------------------------------------- ///
///                                  Sorter()                                  ///
/// -------------------------------------------------------------------------- ///
void Sorter(DATHUC &target)
{
//* Algo: Sort d_inp vào vector temp_d và loop vector đó để xác định vị trí tương ứng của giá trị đó trong d_inp để tìm giá trị e_inp tương ứng.
//*       Sau đó in ra temp_e.
    
    vector<float> temp_d, temp_e;
    temp_d = target.degrees;

    sort(temp_d.begin(), temp_d.end(), greater<int>());
    
    for (int i = 0; i < temp_d.size(); i++)
    {
        for (int j = 0; j < target.degrees.size(); j++)
        {
            if (temp_d[i] == target.degrees[j])
            {
                temp_e.push_back(target.elems[j]);
                break;
            }
        }
    }


    if (find(temp_d.begin(), temp_d.end(), 0) != temp_d.end())                                                                     //? Chuyển số không có x về cuối
    {
        for (int i = 0; i < target.degrees.size(); i++)
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

    target.elems = temp_e;
    target.degrees = temp_d;
}


/// -------------------------------------------------------------------------- ///
///                                  Printer()                                 ///
/// -------------------------------------------------------------------------- ///
void Printer(DATHUC target)
{
    bool first = true;

    for (int i = 0; i < target.elems.size(); i++)
    {
        if (target.elems[i] == 0)
            continue;

        else if (target.degrees[i] == 1)
        {
            if (target.elems[i] == 1)
                first ? cout << "x " : cout << "+ x ";

            else if (target.elems[i] == -1)
                cout << "- x ";

            else if (target.elems[i] > 0 )
                first ? cout << target.elems[i] << "x " : cout << "+ " << target.elems[i] << "x ";
                
            else if (target.elems[i] < 0 )
                cout << "- " << target.elems[i] * (-1) << "x ";
            
            first = false;
        }

        else if (target.degrees[i] < 0)
        {
            if (target.elems[i] == 1)
                first ? cout << "x^(" << target.degrees[i] << ") " : cout << "+ x^(" << target.degrees[i] << ") ";

            else if (target.elems[i] == -1)
                first ? cout << "- x^(" << target.degrees[i] << ") " : cout << "- x^(" << target.degrees[i] << ") ";

            else if (target.elems[i] > 0 )
                first ? cout <<  target.elems[i] << "x^(" << target.degrees[i] << ") " : cout << "+ " << target.elems[i] << "x^(" << target.degrees[i] << ") ";
                
            else if (target.elems[i] < 0 )
                cout << "- " << target.elems[i] * (-1) << "x^(" << target.degrees[i] << ") ";
                
            first = false;
        }

        else if (target.degrees[i] > 0)
        {
            if  (target.elems[i] == 1)
                first ? cout << "x " : cout << "+ x^" << target.degrees[i] << " ";

            else if (target.elems[i] == -1)
                cout << "- x^" << target.degrees[i] << " ";

            else if (target.elems[i] > 0 )
                first ? cout << target.elems[i] << "x^" << target.degrees[i] << " " : cout << "+ " << target.elems[i] << "x^" << target.degrees[i] << " ";
                
            else if (target.elems[i] < 0 )
                cout << "- " << target.elems[i] * (-1) << "x^" << target.degrees[i] << " ";
                
            first = false;
        }

        else    //? target.degrees[i] == 0
        {
            if (target.elems[i] > 0 )
                first ? cout << target.elems[i] << " " : cout << "+ " << target.elems[i] << " ";
                
            else if (target.elems[i] < 0 )
                cout << "- " << target.elems[i] * (-1) << " ";
                
            first = false;
        }
    }
}