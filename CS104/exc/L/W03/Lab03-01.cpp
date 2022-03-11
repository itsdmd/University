/*Lab 03 - BT 01: (4điểm)
- Viết chương trình cài đặt danh sách liên kết đơn với kiểu dữ liệu số nguyên dương thực hiện các yêu cầu sau:
1 Input: người dùng nhập các giá trị số nguyên vào danh sách liên kết
2 Xuất danh sách liên kết vừa nhập
3 Cho biết trong DSLK có phần tử k hay không? (giá trị k do người dùng nhập vào)
4 Kiểm tra DSLK có tăng dần không?
5 Thêm giá trị x vào sau giá trị y trong DSKL (giá trị x, y do người dùng nhập vào)
6 Xóa giá trị z trong DSLK (giá trị z do người dùng nhập vào)
7 Xóa tòa bộ DSLK

Họ Tên  : Đào Minh Đức
MSSV    : 2159003
*/
#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node *pNext;
};

Node *CreateNode(int);
void PrintList(Node *);
void AddFirst(Node *&, int);
void AddLast(Node *&, int);
void DeleteFirst(Node *&);
void DeleteLast(Node *&);
Node *SearchList(Node *, int);
bool CheckIncrease(Node *);
void AddAfter_Value(Node *, int, int);
void DeleteNode_Value(Node *&, int);
void DeleteList(Node *);

int main()
{
	Node *pHead = NULL;
	bool begin = true;
	int input;

	do
	{
		cout << "Nhap gia tri cua Node (Nhap -1 de ngung thao tac): ";
		cin >> input;

		if (input != -1)
		{
			if (begin == true)
			{
				begin = false;
				pHead = CreateNode(input);
			}

			else
			{
				AddLast(pHead, input);
			}
		}
	} while (input != -1);

	cout << "DSKL vua nhap la: ";
	PrintList(pHead);
	cout << endl
		 << endl;
	int k;
	cout << "\nNhap gia tri can tim: ";
	cin >> k;

	SearchList(pHead, k);
	cout << "\n\n";
	CheckIncrease(pHead);

	int x, y;
	cout << "\n\nNhap gia tri x: ";
	cin >> x;
	cout << "\nNhap gia tri y: ";
	cin >> y;

	AddAfter_Value(pHead, x, y);

	cout << "Sau khi them Node co gia tri " << x << " vao sau " << y << ". Danh sach lien ket tro thanh: " << endl;
	PrintList(pHead);
	cout << endl
		 << endl;

	int z = 0;
	cout << "\n\nNhap gia tri can xoa: ";
	cin >> z;
	DeleteNode_Value(pHead, z);
	cout << "\n\nSau khi xoa Node co gia tri " << z << ". Danh sach lien ket tro thanh: " << endl;
	PrintList(pHead);

	DeleteList(pHead);

	return 0;
}

Node *CreateNode(int inp)
{
	Node *p = new Node;
	if (p == NULL)
	{
		cout << "Khong the tao Node. \n";
		return NULL;
	}
	p->data = inp;
	p->pNext = NULL;

	return p;
}

Node *SearchList(Node *pHead, int value)
{
	Node *p = pHead;
	while (p != NULL)
	{
		if (p->data == value)
		{
			cout << "Gia tri " << value << " co trong danh sach lien ket. \n";
			return p;
		}

		p = p->pNext;
	}
	cout << "Gia tri " << value << " khong co trong danh sach lien ket. \n";
	return NULL;
}

void PrintList(Node *pHead)
{
	Node *p = pHead;

	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->pNext;
	}
}

void AddFirst(Node *&pHead, int data)
{
	Node *p = CreateNode(data);

	if (p == NULL)
	{
		cout << "Khong the tao Node. \n";
		return;
	}

	p->pNext = pHead;
	pHead = p;
}

void AddLast(Node *&pHead, int data)
{
	Node *p = CreateNode(data);

	if (p == NULL)
	{
		cout << "Khong the tao Node. \n";
		return;
	}

	if (pHead == NULL)
	{
		pHead = p;
		return;
	}

	Node *pTmp = pHead;

	while (pTmp->pNext != NULL)
	{
		pTmp = pTmp->pNext;
	}

	pTmp->pNext = p;
}

void DeleteFirst(Node *&pHead)
{
	if (pHead == NULL)
	{
		return;
	}

	Node *p = pHead;
	pHead = pHead->pNext;

	delete p;
}

void DeleteLast(Node *&pHead)
{
	if (pHead == NULL)
	{
		return;
	}

	if (pHead->pNext == NULL)
	{
		delete pHead;
		pHead = NULL;
		return;
	}

	Node *p = pHead;

	while (p->pNext->pNext != NULL)
	{
		p = p->pNext;
	}

	delete p->pNext;
	p->pNext = NULL;
}

bool CheckIncrease(Node *pHead)
{
	if (pHead == NULL)
	{
		return false;
	}

	Node *p = pHead;

	while (p->pNext != NULL)
	{
		if (p->data > p->pNext->data)
		{
			cout << "DSKL khong tang dan. \n";
			return false;
		}
		p = p->pNext;
	}

	cout << "DSKL tang dan. \n";

	return true;
}

void AddAfter_Value(Node *pHead, int vadd, int value)
{
	if (pHead == NULL)
	{
		return;
	}

	Node *p = pHead;

	while (p != NULL)
	{
		if (p->data == value)
		{
			Node *pTmp = CreateNode(vadd);
			if (pTmp == NULL)
			{
				return;
			}
			pTmp->pNext = p->pNext;
			p->pNext = pTmp;
			return;
		}

		p = p->pNext;
	}
}

void DeleteNode_Value(Node *&pHead, int value)
{
	if (pHead == NULL)
	{
		return;
	}

	if (pHead->data == value)
	{
		DeleteFirst(pHead);
		return;
	}

	Node *p = pHead;

	while (p->pNext != NULL)
	{
		if (p->pNext->data == value)
		{
			Node *pTmp = p->pNext;
			p->pNext = p->pNext->pNext;
			delete pTmp;
			return;
		}
		p = p->pNext;
	}
}

void DeleteList(Node *pHead)
{
	if (pHead == NULL)
	{
		return;
	}

	Node *p = pHead;

	while (p != NULL)
	{
		Node *pTmp = p;
		p = p->pNext;
		delete pTmp;
	}
}