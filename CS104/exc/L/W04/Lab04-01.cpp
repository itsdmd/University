/*Viết chương trình C++ cài đặt cấu trúc dữ liệu ngăn xếp và hàng đợi bằng danh sách liên kết
  Thao tác cần cài đặt:
  •Stack: push, pop(delete node và lưu lại giá trị của node trước khi xóa)
  •Queue: enqueue, dequeue(delete node và lưu lại giá trị của node trước khi xóa)
  Họ và tên sv: Đào Minh Đức
  MSSV:  2159003
  */

#include<iostream>
using namespace std;

struct NODE
{
	int data;
	NODE* pNext;
};

NODE* CreateNODE(int);
void PrintList(NODE*);
void DeleteList(NODE*);
void Push(NODE*&, int);
void Pop(NODE*&, int&);
void Enqueue(NODE*&, int);
void Dequeue(NODE*&, int&);

int main()
{
	//Stack
	NODE* pHeadStack = NULL;
	
	//Queue
	NODE* pHeadQueue = NULL;
	
	//Thuc hien cac thao tac voi Stack
	int input;
	do
	{
		cout << "Cac thao tac co the thuc hien voi Ngan xep: " << endl;
		
		do
		{
			cout << "Nhap 1.Push - Nhap 2.Pop - Nhap 0 de dung: ";
			cin >> input;
		} while (input < 0 || input > 2);
		switch (input)
		{
		case 1:
			int value;
			cout << "Nhap gia tri can Push vao Ngan xep: ";
			cin >> value;
			Push(pHeadStack, value);
			cout << endl << "Sau khi thuc hien thao tac Push gia tri " << value << " vao Ngan xep. Ngan xep tro thanh: " << endl;
			PrintList(pHeadStack);
			cout << endl;
			break;
		case 2:
			if (pHeadStack==NULL)
				cout << endl << "Ngan xep dang rong. Khong the thuc hien thao tac Pop." << endl;
			else
			{
				int tmp;
				Pop(pHeadStack, tmp);
				cout << endl << "Gia tri tra ve cua thao tac Pop doi voi Ngan xep: " << tmp << endl;
				if (pHeadStack)
				{
					cout << "Sau khi thuc hien thao tac Pop doi voi Ngan xep. Ngan xep tro thanh: " << endl;
					PrintList(pHeadStack);
				}
				else
					cout << "Sau khi thuc hien thao tac Pop doi voi Ngan xep. Ngan xep rong." << endl;
				cout << endl;
			}
			break;
		case 0:
			break;
		}
	} while (input != 0);

	//Thuc hien cac thao tac voi Queue
	system("cls");
	
	input = -1;
	do
	{
		cout << "Cac thao tac co the thuc hien voi Hang doi: " << endl;
		
		do
		{
			cout << "Nhap 1.Enqueueso - Nhap 2. Dequeue - Nhap 0 de dung: ";
			cin >> input;
		} while (input < 0 || input > 2);
		switch (input)
		{
		case 1:
			int value;
			cout << "Nhap gia tri can Enqueue vao Hang doi: ";
			cin >> value;
			Enqueue(pHeadQueue, value);
			
			cout << endl << "Sau khi thuc hien thao tac Enqueue gia tri " << value << " vao Hang doi. Hang doi tro thanh: " << endl;
			PrintList(pHeadQueue);
			cout << endl;
			break;
		case 2:
			if (!pHeadQueue)
				cout << endl << "Hang doi dang rong. Khong the thuc hien thao tac Dequeue." << endl;
			else
			{
				int tmp1;
				Dequeue(pHeadQueue, tmp1);
				cout << endl << "Gia tri tra ve cua thao tac Dequeue doi voi Hang doi: " << tmp1 << endl;
				if (pHeadQueue)
				{
					cout << "Sau khi thuc hien thao tac Dequeue doi voi Hang doi. Hang doi tro thanh: " << endl;
					PrintList(pHeadQueue);
				}
				else
					cout << "Sau khi thuc hien thao tac Dequeue doi voi Hang doi. Hang doi rong." << endl;
				cout << endl;
			}
			break;
		case 0:
			break;
		}
	} while (input != 0);

	//Xoa cac danh sach lien ket de tranh ro ri bo nho
	DeleteList(pHeadStack);
	DeleteList(pHeadQueue);

	return 0;
}

void Push(NODE*& pHead, int data)
{
	NODE* pNew = CreateNODE(data);
	pNew->pNext = pHead;
	pHead = pNew;
}

void Pop(NODE*& pHead, int& output)
{
	if (pHead)
	{
		NODE* pTmp = pHead;
		output = pHead->data;
		pHead = pHead->pNext;
		delete pTmp;
	}
}

void Enqueue(NODE*& pHead, int data)
{
	NODE* pNew = CreateNODE(data);
	if (!pHead)
		pHead = pNew;
		
	else
	{
		NODE* pTmp = pHead;
		while (pTmp->pNext)
			pTmp = pTmp->pNext;
		pTmp->pNext = pNew;
	}
}

void Dequeue(NODE*& pHead, int& output)
{
	if (pHead)
	{
		NODE* pTmp = pHead;
		output = pHead->data;
		pHead = pHead->pNext;
		delete pTmp;
	}
}

NODE* CreateNODE(int data)
{
	NODE* pNew = new NODE;
	pNew->data = data;
	pNew->pNext = NULL;
	
	return pNew;
}

void PrintList(NODE* pHead)
{
	if (pHead)
	{
		NODE* pTmp = pHead;
		while (pTmp)
		{
			cout << pTmp->data << " ";
			pTmp = pTmp->pNext;
		}
	}
	
	else
		cout << "NULL";
}

void DeleteList(NODE* pHead)
{
	if (pHead)
	{
		NODE* pTmp = pHead;
		while (pTmp)
		{
			pHead = pHead->pNext;
			delete pTmp;
			pTmp = pHead;
		}
	}
}