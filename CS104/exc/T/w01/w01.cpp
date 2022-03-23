#include <iostream>
using namespace std;

struct PNT
{
    double x, y;
};

struct NODE
{
    NODE *p_Next;
    PNT pnt;
};

bool Satisfied(PNT inp)
{
    if (inp.y == (3 * inp.x + 2))
        return true;
    else
        return false;
}

void PrintPoints(NODE *p_Head)
{
    NODE *p_Temp = p_Head;
    int counter = 1;

    while (p_Temp != NULL)
    {
        if (Satisfied(p_Temp->pnt))
        {
            cout << "[" << counter << "] x = " << p_Temp->pnt.x
                 << " ; y = " << p_Temp->pnt.y << endl;
            counter++;
        }
    }
}

int main()
{
    NODE *p_New = new NODE;
    PrintPoints(p_New);

    return 0;
}