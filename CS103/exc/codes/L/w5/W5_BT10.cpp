/*------------------------------------------------------------------------
                              Thông tin cá nhân                            
--------------------------------------------------------------------------
-------------------------- Họ tên: Đào Minh Đức --------------------------
------------------------------ MSSV: 2159003 -----------------------------
------------------------------- Bài tập 10 -------------------------------
------------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>        //? find()
#include <string>
#include <vector>
using namespace std;



vector<double> elems;
vector<char> ops;


void GetElements(string, vector<double> &), GetOperators(string, vector<char> &),
     Calculator(vector<double>, vector<char>, double &, bool &);



int main()
{
    bool err = false;
    double res;
    string raw_inp;

    cout << endl << "[[Vi du: - 7 * 8 / 5 + 3]" << endl;                                                                        //! Chương trình không xử lí được phép toán có nhiều toán tử liên tiếp (Vd: 3 - - + 4; 7 * - 8). Để làm được như này thì code sẽ phức tạp lắm ạ :(
    
    cout << endl << "Nhap phep toan: "; getline(cin, raw_inp);

    GetElements(raw_inp, elems);
    GetOperators(raw_inp, ops);
    
    Calculator(elems, ops, res, err);

    if (err == false)
        cout << endl << raw_inp << " = " << res;
    
    return 0;
}



/// -------------------------------------------------------------------------- ///
///                               GetElements()                                ///
/// -------------------------------------------------------------------------- ///
void GetElements(string inp, vector<double> &elems)
{
    inp += "\t";                                                                                                                //? Đánh dấu kết thúc chuỗi
    double cur;

    for (int i = 0; i < (inp.length() + 1); i++)                                                                                //? Loop chuỗi
    {
        if ((double(inp[i]) - 48) == 0 || (double(inp[i]) - 48) == 1 || (double(inp[i]) - 48) == 2 || (double(inp[i]) - 48) == 3 || (double(inp[i]) - 48) == 4 || (double(inp[i]) - 48) == 5 || (double(inp[i]) - 48) == 6 || (double(inp[i]) - 48) == 7 || (double(inp[i]) - 48) == 8 || (double(inp[i]) - 48) == 9)
        {
            int j = 1;
            
            cur = double(inp[i]) - 48;
            
            do                                                                                                                  //? Loop xác định elem
            {
                if (inp[i+j] == ' ' || inp[i+j] == '\t')                                                                        //? --- Nếu gặp phải 2 kí tự này thì break và trả về cur hiện tại
                {
                    i += j;

                    elems.push_back(cur);
                    break;
                }

                else                                                                                                            //? --- Các trg hợp còn lại chỉ có thể là số
                {
                    while ((double(inp[i+j]) - 48) == 0 || (double(inp[i+j]) - 48) == 1 || (double(inp[i+j]) - 48) == 2 || (double(inp[i+j]) - 48) == 3 || (double(inp[i+j]) - 48) == 4 || (double(inp[i+j]) - 48) == 5 || (double(inp[i+j]) - 48) == 6 || (double(inp[i+j]) - 48) == 7 || (double(inp[i+j]) - 48) == 8 || (double(inp[i+j]) - 48) == 9)
                    {
                        cur = cur*10 + double(inp[i+j]) - 48;
                        j++;
                    }

                    i += j;

                    elems.push_back(cur);
                    break;
                }
                
            } while (inp[i+j] != ' ');
        }
    }
}

/// -------------------------------------------------------------------------- ///
///                               GetOperators()                               ///
/// -------------------------------------------------------------------------- ///
void GetOperators(string inp, vector<char> &ops)
{
    inp += "\t";

    if (inp[0] != '-')                                                                                                          //? Gán dấu cho số đầu tiên
    {
        ops.push_back('+');
    }

    for (int i = 0; i < (inp.length() + 1); i++)
    {
        if (inp[i] == '+' || inp[i] == '-' || inp[i] == '*' || inp[i] == '/')
        {
            ops.push_back(inp[i]);
        }
    }
}

/// -------------------------------------------------------------------------- ///
///                                Calculator()                                ///
/// -------------------------------------------------------------------------- ///
void Calculator(vector<double> inp_e, vector<char> inp_o, double &res_e, bool &err)
{
//// Algo: Tìm từ trái qua, gặp dấu (*) hoặc (/) thì lấy vị trí hiện tại của dấu đó và tính tích/thương của elem có cùng vị trí và vị trí đó -1.
////       Sau đó xóa elem và op ở vị trí đó đi (giữ giá trị ở vị trí -1).
////       Chỉ tăng i của vòng lặp khi không tìm thấy dấu cần tìm.
////       Xét xong thì làm tương tự với (+) và (-) nhưng xóa số nằm sau. 

    if (inp_e.size() == 0)
    {
        cout << endl << "Khong co du lieu duoc nhap vao." << endl;
        err = true;
    }

    
    if (!err)
    {
        res_e = 0;

        for (int i = 0; i < inp_e.size();)                                                                                          //? (*) và (/)
        {
            if (inp_e.size() == 1)
                break;

            else if (inp_o[i] == '*' || inp_o[i] == '/')
            {
                res_e = inp_e[i-1];

                if (inp_o[i] == '*')
                    res_e *= inp_e[i];
                
                else
                {
                    if (inp_e[i] == 0)
                    {
                        cout << endl << "Loi chia cho 0" << endl;
                        err = true;
                        
                        break;
                    }

                    else
                        res_e /= inp_e[i];
                }

                inp_e[i-1] = res_e;

                inp_e.erase(inp_e.begin() + i);
                inp_o.erase(inp_o.begin() + i);
            }

            else
                i++;
        }


        res_e = 0;                                                                                                                  //? --- Reset giá trị res_e do loop trên đã tính tích/thương và inp_o chỉ còn (+) và (-)

        if (inp_o[0] == '+')
            inp_o.erase(inp_o.begin());
        else
        {
            inp_e[0] *= -1;
            inp_o.erase(inp_o.begin());
        }

        for (int i = 0; i < inp_e.size();)                                                                                          //? (*) và (/)
        {
            if (inp_e.size() == 1)
            {
                res_e = inp_e[0];
                break;
            }

            else if (inp_o[i] == '+' || inp_o[i] == '-')
            {
                res_e = inp_e[i];

                (inp_o[i] == '+') ? res_e += inp_e[i+1] : res_e -= inp_e[i+1];

                inp_e[i] = res_e;

                inp_e.erase(inp_e.begin() + i + 1);
                inp_o.erase(inp_o.begin() + i);                                                                                     //? --- Do đã bỏ đi op của số đầu tiên
            }
        }
    }
}