/*
Tính giá trị 1 biểu thức trung tố từ file (input: file, output: kết quả biểu thức)
- Đọc biểu thức từ file
Giả sử file chứa 1 biểu thức,
các toán tử gồm + - * /, toán hạng gồm số nguyên và số thập phân, chỉ chứa dấu ngoặc đơn (), cách nhau đúng 1 khoảng trắng
- Chuyển từ biểu thức trung tố sang hậu tố
- Sử dụng ký pháp Ba Lan ngược tính giá trị biểu thức

Họ và tên sv: Đào Minh Đức
MSSV:  2159003

*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// Hàm kiểm tra chuỗi chỉ chứa toán tử hay không
bool CheckOperator(string op)
{
	if (op.size() == 1 && (op == "+" || op == "-" || op == "*" || op == "/"))
		return true;
	
	return false;
}

// Hàm đưa về độ ưu tiên trong phép toán
int CheckPrecedenceOp(const string &op)
{
	if (op == "*" || op == "/")
		return 2;
	
	if (op == "+" || op == "-")
		return 1;
	
	return 0;
}

// Kiểm tra xem chuỗi đó có phải là số không
bool CheckOperand(const string &input)
{
	int start = 0, c = 0;
	
	if (input.size() > 1 && (input[0] == '+' || input[0] == '-')) // số âm, số dương
		start = 1;
	
	for (int i = start; i < int(input.size()); i++)
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
		
		else
			return false;
	}
	
	return true;
}

// Hàm chuyển đổi từ trung tố sang hậu tố
queue<string> InfixToPostfix(vector<string> infix)
{
	queue<string> postfix;
	stack<string> instack;
	
	for (int i = 0; i < int(infix.size()); i++)
	{
		// Nếu là toán hạng (số), push nó vào queue
		if (CheckOperand(infix[i]))
		{
			postfix.push(infix[i]);
		}
		
		else
		{
			// Nếu là các dấu mở ngoặc, push nó vào trong stack
			if (infix[i] == "(")
			{
				instack.push(infix[i]);
			}
			
			else if (infix[i] == ")")
			{
				// Nếu là dấu đóng ngoặc, thì lấy từng phần tử trong stack ra và push vào queue
				while (instack.top() != "(")
				{
					postfix.push(instack.top());
					instack.pop();
				}
				
				instack.pop();
			}
			
			else
			{
				// Nếu là toán tử, thì kiểm tra độ ưu tiên của toán tử và push vào stack
				if (instack.empty() || CheckPrecedenceOp(infix[i]) > CheckPrecedenceOp(instack.top()))
				{
					instack.push(infix[i]);
				}
				
				else
				{
					while (!instack.empty() && CheckPrecedenceOp(infix[i]) <= CheckPrecedenceOp(instack.top()))
					{
						postfix.push(instack.top());
						instack.pop();
					}
					instack.push(infix[i]);
				}
			}
		}
	}
	
	// Bỏ tất cả các toán tử còn lại trong stack vào queue
	while (!instack.empty())
	{
		postfix.push(instack.top());
		instack.pop();
	}
	
	return postfix;
}

// Hàm tính toán 2 số hạng và 1 toán tử
string Calculate2Number(const string &num1, const string &num2, const string &op)
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
			return "***"; // Xét trường hợp chia cho số 0
		result = n1 / n2;
	}
	
	return to_string(result);
}

// Tính toán biểu thức postfix
string CalculatePostfix(queue<string> postfix)
{
	stack<string> instack;
	while (!postfix.empty())
	{
		if (CheckOperand(postfix.front()))
		{
			instack.push(postfix.front());
			postfix.pop();
		}
		
		else
		{
			string num1 = instack.top();
			instack.pop();
			string num2 = instack.top();
			instack.pop();
			string op = postfix.front();
			postfix.pop();
			string result = Calculate2Number(num2, num1, op);
			if (result == "***")
				return "***";
			instack.push(result);
		}
	}
	
	return instack.top();
}

int main()
{
	fstream MyFile;
	//MyFile.open("/home/dmd/Documents/ObsidianVaults/University/Courses/CS104/exc/L/W04/RPNotation.txt", ios::in);
	MyFile.open("RPNotation.txt", ios::in);
	
	if (MyFile.fail())
	{
		cout << "Error open file!";
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
	//system("pause");
	
	return 0;
}