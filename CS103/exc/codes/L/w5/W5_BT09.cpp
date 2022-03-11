/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 09 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>            //? find()
#include <string>
#include <vector>
using namespace std;



vector<string> container_temp;

vector<int> e_1, e_2,
            d_1, d_2,
            res_e, res_d;

vector<char> s_1, s_2, s_res;


void StringSplitter(string, string, vector<string> &),
     GetElements(string, vector<int> &), GetDegrees(string, vector<int> &), GetSigns(string, string, vector<char> &),
     FlipSign(), MergeSign(vector<int> &, vector<char> &), Calculator(), Sorter(vector<int>, vector<int>, vector<int> &, vector<int> &), Printer(vector<int>, vector<int>),
     Logger();



int main()
{
    string mode;
    string raw_inp_1, raw_inp_2;

    cout << endl << "[[Vi du: 8x^-7 + 20x^2 - 9 + 5x]]" << endl;

    cout << endl << "Nhap phuong trinh 1: "; getline(cin, raw_inp_1);
    cout << endl << "Nhap phep toan: "; cin >> mode; cin.clear(); cin.sync();
    cout << endl << "Nhap phuong trinh 2: "; getline(cin, raw_inp_2);

    GetElements(raw_inp_1, e_1);
    GetElements(raw_inp_2, e_2);

    GetDegrees(raw_inp_1, d_1);
    GetDegrees(raw_inp_2, d_2);

    GetSigns(raw_inp_1, "+", s_1);
    GetSigns(raw_inp_2, mode, s_2);

    if (mode == "-")
        FlipSign();
    
    MergeSign(e_1, s_1);
    MergeSign(e_2, s_2);
    
    Calculator();

    // cout << endl; Logger(); cout << endl;

    Sorter(res_e, res_d, res_e, res_d);

    cout << endl << "= ";
    Printer(res_e, res_d);
    cout << endl;

    return 0;
}



/// -------------------------------------------------------------------------- ///
///                               GetElements()                                ///
/// -------------------------------------------------------------------------- ///
void GetElements(string inp, vector<int> &elems)
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
                    elems.push_back(cur);                                                                                       //? ------ Append

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
                }

                else if (inp[i+j] == ' ' || inp[i+j] == '\t')                                                                   //? --- Nếu gặp phải 2 kí tự này thì break và trả về cur
                {
                    i += j;

                    elems.push_back(cur);
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
                        elems.push_back(cur);                                                                                   //? --------- Làm tương tự bên trên

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

                        elems.push_back(cur);
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
void GetDegrees(string inp, vector<int> &degs)       //* Req: "20x^7 + 8x^-2 + 5x - 9"
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

                    degs.push_back(cur);                                                                                        //? ------ Append
                    break;
                }

                else if (inp[i+j] == ' ' || inp[i+j] == '\t')                                                                   //? --- Nếu gặp phải 2 kí tự này thì break và ném về cur hiện tại (cho trường hợp chỉ có cơ số hoặc ^x ở cuối inp)
                {
                    degs.push_back(cur);
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
void GetSigns(string inp, string mode, vector<char> &signs)
{
    for (int i = 0; i < inp.size(); i++)
    {
        if (inp[i] == '+' || inp[i] == '-')
        {
            signs.push_back(inp[i]);
        }

        else if (i == 0)                                //? Cho trường hợp số đầu tiên là số dương
        {
            signs.push_back('+');
        }
    }

    if (mode == "-")
    {
        for (int i = 0; i < signs.size(); i++)
        {
            (signs[i] == '+') ? signs[i] = '-' : signs[i] = '+';
        }
    }
}

/// -------------------------------------------------------------------------- ///
///                                 FlipSign()                                 ///
/// -------------------------------------------------------------------------- ///
void FlipSign()
{
    for (int i = 0; i < res_e.size(); i++)
    {
        res_e[i] = 0 - res_e[i];
    }
}

/// -------------------------------------------------------------------------- ///
///                                 MergeSign()                                ///
/// -------------------------------------------------------------------------- ///
void MergeSign(vector<int> &e_inp, vector<char> &s_inp)
{
    for (int i = 0; i < e_inp.size(); i++)
    {
        if (s_inp[i] == '-')
            e_inp[i] *= -1;
    }
}

/// -------------------------------------------------------------------------- ///
///                                Calculator()                                ///
/// -------------------------------------------------------------------------- ///
void Calculator()
{
//* Algo: Loop d_1, với mỗi giá trị của d_1 thì xác định xem bậc đó đã xét chưa.
//*       Chưa thì thêm vào res_d và loop d_2 để xác định vị trí các cơ số chung bậc trong e_2 để cộng/trừ vào element tương ứng trong res_e, 
//*       rồi thì loop trong d_1 để tìm vị trí của cơ số của bậc đang xét trong e_1 để cộng/trừ vào res_e; nếu không tìm thấy số nào thì ném chính nó vào res_e luôn. 
//*       Sau đó làm tương tự cho d_2 nhưng với d2 thì nếu có trong checked rồi thì skip do loop đầu đã cộng đủ.

    for (int i = 0; i < d_1.size(); i++)                                                                                        
    {
        if (find(res_d.begin(), res_d.end(), d_1[i]) == res_d.end())                                                            //? Nếu bậc này chưa được xét     //* Ref: https://stackoverflow.com/a/571405/16784616
        {
            res_d.push_back(d_1[i]);

            bool found = false;

            for (int j = 0; j < d_2.size(); j++)                                                                                //? --- Tìm trong d_2
            {
                if (d_2[j] == d_1[i])
                {
                    found = true;

                    int temp_1 = 0, temp_2 = 0, temp_res = 0;

                    temp_1 += e_1[i];
                    temp_2 += e_2[j];
                    
                    temp_res = temp_1 + temp_2;

                    res_e.push_back(temp_res);
                }
            }

            if (found == false)                                                                                                 //? --- Nếu không tìm thấy số cùng bậc trong d_2
                res_e.push_back(e_1[i]);
        }

        else                                                                                                                    //? Nếu được xét rồi
        {
            int pos;

            for (int j = 0; j < d_1.size(); j++)
            {
                if (d_1[i] == res_d[j])                                                                                         //? --- Xác định vị trí trong res_d (vì sẽ tương ứng vị trí của tổng các cơ số lưu trong res_e)
                {
                    pos = j;
                    break;
                }
            }

            res_e[pos] += e_1[i];
        }
    }
    
    for (int i = 0; i < d_2.size(); i++)                                                                                        
    {
        if (find(res_d.begin(), res_d.end(), d_2[i]) == res_d.end())
        {
            res_d.push_back(d_2[i]);

            bool found = false;

            for (int j = 0; j < d_1.size(); j++)
            {
                if (d_1[j] == d_2[i])
                {
                    found = true;

                    int temp_1 = 0, temp_2 = 0, temp_res = 0;

                    temp_1 += e_2[i];
                    temp_2 += e_1[j];
                    
                    temp_res = temp_1 + temp_2;

                    res_e.push_back(temp_res);
                }
            }

            if (found == false)
                res_e.push_back(e_2[i]);
        }

        else
        {
            continue;
        }
    }
}

/// -------------------------------------------------------------------------- ///
///                                  Sorter()                                  ///
/// -------------------------------------------------------------------------- ///
void Sorter(vector<int> e_inp, vector<int> d_inp, vector<int> &e_sorted, vector<int> &d_sorted)
{
//* Algo: Sort d_inp vào vector temp_d và loop vector đó để xác định vị trí tương ứng của giá trị đó trong d_inp để tìm giá trị e_inp tương ứng.
//*       Sau đó in ra temp_e.
    
    vector<int> temp_d, temp_e;
    temp_d = d_inp;

    sort(temp_d.begin(), temp_d.end(), greater<int>());
    
    for (int i = 0; i < temp_d.size(); i++)
    {
        for (int j = 0; j < d_inp.size(); j++)
        {
            if (temp_d[i] == d_inp[j])
            {
                temp_e.push_back(e_inp[j]);
                break;
            }
        }
    }


    if (find(temp_d.begin(), temp_d.end(), 0) != temp_d.end())                                                                     //? Chuyển số không có x về cuối
    {
        for (int i = 0; i < res_d.size(); i++)
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

    e_sorted = temp_e;
    d_sorted = temp_d;
}

/// -------------------------------------------------------------------------- ///
///                                  Printer()                                 ///
/// -------------------------------------------------------------------------- ///
void Printer(vector<int> e_toprint, vector<int> d_toprint)
{
    bool first = true;

    for (int i = 0; i < e_toprint.size(); i++)
    {
        if (e_toprint[i] == 0)
            continue;

        else if (d_toprint[i] == 1)
        {
            if (e_toprint[i] == 1)
                first ? cout << "x " : cout << "+ x ";

            else if (e_toprint[i] == -1)
                cout << "- x ";

            else if (e_toprint[i] > 0 )
                first ? cout << e_toprint[i] << "x " : cout << "+ " << e_toprint[i] << "x ";
                
            else if (e_toprint[i] < 0 )
                cout << "- " << e_toprint[i] * (-1) << "x ";
        }

        else if (d_toprint[i] < 0)
        {
            if (e_toprint[i] == 1)
                first ? cout << "x^(" << d_toprint[i] << ") " : cout << "+ x^(" << d_toprint[i] << ") ";

            else if (e_toprint[i] == -1)
                first ? cout << "- x^(" << d_toprint[i] << ") " : cout << "- x^(" << d_toprint[i] << ") ";

            else if (e_toprint[i] > 0 )
                first ? cout << e_toprint[i] << "x^(" << d_toprint[i] << ") " : cout << "+ " << e_toprint[i] << "x^(" << d_toprint[i] << ") ";
                
            else if (e_toprint[i] < 0 )
                cout << "- " << e_toprint[i] * (-1) << "x^(" << d_toprint[i] << ") ";
        }

        else if (d_toprint[i] > 0)
        {
            if  (e_toprint[i] == 1)
                first ? cout << "x " : cout << "+ x^" << d_toprint[i] << " ";

            else if (e_toprint[i] == -1)
                cout << "- x^" << d_toprint[i] << " ";

            else if (e_toprint[i] > 0 )
                first ? cout << e_toprint[i] << "x^" << d_toprint[i] << " " : cout << "+ " << e_toprint[i] << "x^" << d_toprint[i] << " ";
                
            else if (e_toprint[i] < 0 )
                cout << "- " << e_toprint[i] * (-1) << "x^" << d_toprint[i] << " ";
        }

        else    //? d_toprint[i] == 0
        {
            if (e_toprint[i] > 0 )
                first ? cout << e_toprint[i] << " " : cout << "+ " << e_toprint[i] << " ";
                
            else if (e_toprint[i] < 0 )
                cout << "- " << e_toprint[i] * (-1) << " ";
        }
    }
}

/// -------------------------------------------------------------------------- ///
///                                  Logger()                                  ///
/// -------------------------------------------------------------------------- ///
void Logger()
{
    cout << endl << "e_1: ";
    for (int i = 0; i < e_1.size(); i++)
    {
        cout << e_1[i] << " ";
    }

    cout << endl << "d_1: ";
    for (int i = 0; i < d_1.size(); i++)
    {
        cout << d_1[i] << " ";
    }

    cout << endl << "s_1: ";
    for (int i = 0; i < s_1.size(); i++)
    {
        cout << s_1[i] << " ";
    }
    
    cout << endl << "e_2: ";
    for (int i = 0; i < e_2.size(); i++)
    {
        cout << e_2[i] << " ";
    }

    cout << endl << "d_2: ";
    for (int i = 0; i < d_2.size(); i++)
    {
        cout << d_2[i] << " ";
    }

    cout << endl << "s_2: ";
    for (int i = 0; i < s_2.size(); i++)
    {
        cout << s_2[i] << " ";
    }
    
    cout << endl << "res_e: ";
    for (int i = 0; i < res_e.size(); i++)
    {
        cout << res_e[i] << " ";
    }
    
    cout << endl << "res_d: ";
    for (int i = 0; i < res_e.size(); i++)
    {
        cout << res_d[i] << " ";
    }
}