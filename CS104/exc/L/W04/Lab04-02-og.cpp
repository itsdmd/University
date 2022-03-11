/*
Tính giá trị 1 biểu thức trung tố từ file (input: file, output: kết quả biểu thức)
- Đọc biểu thức từ file 
Giả sử file chứa 1 biểu thức, 
các toán tử gồm + - * /, toán hạng gồm số nguyên và số thập phân, chỉ chứa dấu ngoặc đơn (), cách nhau đúng 1 khoảng trắng
- Chuyển từ biểu thức trung tố sang hậu tố
- Sử dụng ký pháp Ba Lan ngược tính giá trị biểu thức

*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

//Hàm kiểm tra chuỗi chỉ chứa toán tử hay không
bool CheckOperator(string op)
{
	if (op.size() == 1 && (op == "+" || op == "-" || op == "*" || op == "/"))
		return true;
	return false;
}

//Hàm đưa về độ ưu tiên trong phép toán
int CheckPrecedenceOp(string op)
{
	if (op == "*" || op == "/")
		return 2;
	if (op == "+" || op == "-")
		return 1;
	return 0;
}

//Kiểm tra xem chuỗi đó có phải là số không
bool CheckOperand(string input)
{
	int start = 0,  c=0;
	if (input.size() > 1 && (input[0] == '+' || input[0] == '-'))//số âm, số dương
		start = 1;
	for (int i = start; i < input.size(); i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
			continue;
		else if (input[i] == '.')
		{
			c++;
			if (c > 1)
				return false;
			continue;
		}
		else return false;
	}
	return true;
}

//Hàm chuyển đổi từ trung tố sang hậu tố
queue<string> InfixToPostfix(vector<string> infix)
{
	queue<string> postfix;
	stack<string> instack;
	int i = 0;
	for (int i = 0; i < infix.size(); i++)
	{
		//Nếu là toán hạng (số), push nó vào queue
		if (CheckOperand(infix[i]))
		{
			//sv hoàn thành code này
		}
		else
		{
			//Nếu là các dấu mở ngoặc, push nó vào trong stack
			if (infix[i] == "(")
			{
				//sv hoàn thành code này
			}
			else
			{//Xét trường hợp dấu đóng ngoặc, push vào queue và pop stack operator cho tới khi gặp dấu mở ngoặc 
				if (infix[i] == ")")
				{
					while (!instack.empty() && instack.top() != "(")
					{
						//sv hoàn thành code này
					}
					instack.pop(); //Pop luôn dấu mở ngoặc
				}

				else
				{
					if (CheckOperator(infix[i])) //Nếu là toán tử, xét độ ưu tiên của dấu, nhân chia trước, cộng trừ sau, dấu ngoặc là ít ưu tiên nhất
					{
						while (!instack.empty() && (CheckPrecedenceOp(infix[i]) <= CheckPrecedenceOp(instack.top())))
						{
							//sv hoàn thành code này
						}
						instack.push(infix[i]); 
					}
				}
			}
		}
	}
	//Bỏ tất cả các toán tử còn lại trong stack vào queue
	while (!instack.empty())
	{
		//sv hoàn thành code này
	}
	return postfix;
}

//Hàm tính toán 2 số hạng và 1 toán tử
string Calculate2Number(string num1, string num2, string op)
{
	float n1 = stof(num1);
	float n2 = stof(num2);
	float result = 0;
	if (op == "+")
		result = n1 + n2;
	if (op == "-")
		result = n1 - n2;
	if (op == "*")
		result = n1 * n2;
	if (op == "/")
	{
		if (n2 == 0) 
			return "***"; //Xét trường hợp chia cho số 0
		result = n1 / n2;
	}
	return to_string(result);
}

//Tính toán biểu thức postfix
string CalculatePostfix(queue<string> postfix)
{
	stack<string> instack;
	while (!postfix.empty()) {
		if (CheckOperand(postfix.front())) //Nếu là toán hạng,  
		{//sv hoàn thành đoạn code sau
			//push vào stack,
			//pop ra khỏi queue
		}
		else //Nếu là toán tử, lấy từ stack 2 phần tử, tính toán và đưa kq vào stack
		{
			string num1 ;
			string num2 ;
			//sv hoàn thành đoạn code sau:
			
			
			string result = Calculate2Number(num2, num1, postfix.front()); //Do tính chất stack, phải đảo 2 giá trị mới đúng thứ tự
			postfix.pop();
			//sv hoàn thành đoạn code sau:
			
			//xóa toán hạng vừa sử dụng
			
			//đưa kết quả vừa tính được vào stack			
		}
	}
	return instack.top();
}

int main()
{
	fstream MyFile;
	MyFile.open("RPNotation.txt", ios::in);
	if (MyFile.fail())
	{	cout << "error";
		return 0;
	}
	string input;
	vector<string> infix;
	while (!MyFile.eof())
	{
		getline(MyFile, input, ' ');
		infix.push_back(input);
	}
	queue<string> postfix = InfixToPostfix(infix);

	queue<string> postfix1 = postfix;
	cout << "Result for convert to postfix: ";
	while (!postfix1.empty())
	{
		cout << postfix1.front() << " ";
		postfix1.pop();
	}
	cout << endl;

	cout << "Result for calculate: " << CalculatePostfix(postfix) << endl;

	MyFile.close();
	system("pause");
	
	return 0;
}