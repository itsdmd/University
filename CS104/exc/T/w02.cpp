#include <iostream>
#include <string>

using namespace std;

/// ------------------------------------------------------------------------ ///
///                               Declarations                               ///
/// ------------------------------------------------------------------------ ///

struct NODE
{
    NODE *p_Next;

    int data;
};

NODE *CreateNode(int k);
void InsertToHead(NODE *&p_Head, int k), InsertToTail(NODE *p_Head, int k), InsertAfter(NODE *p_Target, int k),
    DelHead(NODE *&p_Head), DelTail(NODE *&p_Head), DelAfter(NODE *p_Target);

/// ------------------------------------------------------------------------ ///
///                                 Functions                                ///
/// ------------------------------------------------------------------------ ///

int main()
{
    //

    return 0;
}

/// ----------------------------- CreateNode() ----------------------------- ///
NODE *CreateNode(int inp)
{
    NODE *p_New = new NODE();
    p_New->data = inp;
    p_New->p_Next = NULL;
    return p_New;
}

/// ---------------------------- InsertToHead() ---------------------------- ///
void InsertToHead(NODE *&p_Head, int k)
{
    NODE *p_New = CreateNode(k);

    if (p_Head == NULL)
    {
        p_Head = p_New;
    }

    else
    {
        p_New->p_Next = p_Head;
        p_Head = p_New;
    }
}

/// ---------------------------- InsertToTail() ---------------------------- ///
void InsertToTail(NODE *p_Head, int k)
{
    NODE *p_New = CreateNode(k);
    NODE *p_Temp = p_Head;

    while (p_Temp->p_Next != NULL)
    {
        p_Temp = p_Temp->p_Next;
    }

    p_Temp->p_Next = p_New;
}

/// ----------------------------- InsertAfter() ---------------------------- ///
void InsertAfter(NODE *&p_Target, int k)
{
    NODE *p_New = CreateNode(k);

    p_New->p_Next = p_Target->p_Next;
    p_Target->p_Next = p_New;
}

/// ------------------------------- DelHead() ------------------------------ ///
void DelHead(NODE *&p_Head)
{
    NODE *p_Temp = p_Head;

    p_Head = p_Head->p_Next;
    delete p_Temp;
}

/// ------------------------------- DelTail() ------------------------------ ///
void DelTail(NODE *p_Head)
{
    NODE *p_Temp = p_Head;

    if (p_Head->p_Next == NULL)
        p_Head = NULL;

    while (p_Temp->p_Next->p_Next != NULL)
    {
        p_Temp = p_Temp->p_Next;
    }

    NODE *p_Tail = p_Temp->p_Next;
    p_Temp->p_Next = NULL;
    delete p_Tail;
}

/// ------------------------------ DelAfter() ------------------------------ ///
void DelAfter(NODE *&p_Target)
{
    NODE *p_ToDel = p_Target->p_Next;

    if (p_ToDel != NULL)
    {
        p_Target->p_Next = p_ToDel->p_Next;
        delete p_ToDel;
    }
}