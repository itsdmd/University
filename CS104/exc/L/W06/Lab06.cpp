/*
    Họ và tên SV: Đào Minh Đức
    MSSV: 2159003
*/

#include <iostream>

using namespace std;

struct NODE {
    int key;
    NODE *pLeft;
    NODE *pRight;
};

NODE *createNode(int), *searchData(NODE *, int);
void insertNode(NODE *&, int), deleteNode(NODE *&, int), NLR(NODE *), LNR(NODE *), LRN(NODE *),
     rotateLeft(NODE *&), rotateRight(NODE *&), treeBalancing(NODE *&),
     outputDecrease (NODE *);
int treeHeight(NODE *), sumAllNodes(NODE *), sumAllLeafNodes(NODE *);


int main()
{

    NODE *pRoot = NULL;
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cout << "Nhap khong phan tu thu " << i + 1 << ": ";
        cin >> k;
        insertNode(pRoot, k);
        // NLR(pRoot); cout << "\n";        // Debugging
    }


    cout << "\nDuyet cay theo thu tu truoc: ";
    NLR(pRoot);
    cout << "\n";
    cout << "\nDuyet cay theo thu tu giua: ";
    LNR(pRoot);
    cout << "\n";
    cout << "\nDuyet cay theo thu tu sau: ";
    LRN(pRoot);
    cout << "\n";


    int k;
    cout << "\nNhap k can tim: ";
    cin >> k;
    NODE *pNode = searchData(pRoot, k);

    if (pNode == NULL) cout << "NO" << "\n";
    else cout << "YES" << "\n";


    cout << "\nNhap k can xoa: ";
    cin >> k;
    deleteNode(pRoot, k);
    cout << "Cay sau khi xoa (NLR): ";
    NLR(pRoot);
    cout << "\n";

    cout << "\nCac gia tri tren cay theo thu tu giam dan: ";
    outputDecrease(pRoot);

    cout << "\nTong gia tri cua cay: " << sumAllNodes(pRoot)
         << "\nTong gia tri cua cac node la: " << sumAllLeafNodes(pRoot) << "\n";

    return 0;
}



/// ------------------------------- Node Mods ------------------------------ ///

NODE *createNode(int key) {

    NODE *pNew = new NODE();

    if (pNew == NULL) {
        cout << "Khong du bo nho cap phat";
        return NULL;
    }

    pNew->key = key;


    pNew->pLeft = NULL;
    pNew->pRight = NULL;

    return pNew;
}

void insertNode(NODE *&pRoot, int key)
{

    if (pRoot == NULL)
    {
        pRoot = createNode(key);
        return;
    }


    if (key < pRoot->key)
    {
        insertNode(pRoot->pLeft, key);
    }

    else
    {
        insertNode(pRoot->pRight, key);
    }

    treeBalancing(pRoot);
}

void deleteNode(NODE *&pRoot, int key)
{
    if (key < pRoot->key)
    {
        deleteNode(pRoot->pLeft, key);
    }

    else if (key > pRoot->key)
    {
        deleteNode(pRoot->pRight, key);
    }

    else
    {
        if (pRoot->pLeft == NULL)
        {
            NODE *pTemp = pRoot;
            pRoot = pRoot->pRight;
            delete pTemp;
        }

        else if (pRoot->pRight == NULL)
        {
            NODE *pTemp = pRoot;
            pRoot = pRoot->pLeft;
            delete pTemp;
        }

        else
        {

            NODE *pTemp = pRoot->pRight;

            while(pTemp->pLeft != NULL)
            {
                pTemp = pTemp->pLeft;
            }

            pRoot->key = pTemp->key;
            deleteNode(pRoot->pRight, pTemp->key);
        }
    }

    treeBalancing(pRoot);
}


/// ------------------------------- Tree Mods ------------------------------ ///

void rotateLeft(NODE *&pPivot)
{
    NODE *pTemp = pPivot->pRight;
    if (pTemp == NULL) return;

    pPivot->pRight = pTemp->pLeft;
    pTemp->pLeft = pPivot;
    pPivot = pTemp;
}

void rotateRight(NODE *&pPivot)
{
    NODE *pTemp = pPivot->pLeft;
    if (pTemp == NULL) return;

    pPivot->pLeft = pTemp->pRight;
    pTemp->pRight = pPivot;
    pPivot = pTemp;
}

int treeHeight(NODE *pRoot)
{
    int h = 0;

    if (pRoot != NULL)
    {
        int lHeight = treeHeight(pRoot->pLeft);
        int rHeight = treeHeight(pRoot->pRight);

        if (lHeight > rHeight)
            h = lHeight + 1;

        else
            h = rHeight + 1;
    }

    return h;
}

void treeBalancing(NODE *&pRoot)
{
    if (pRoot == NULL) return;

    int leftHeight = treeHeight(pRoot->pLeft);
    int rightHeight = treeHeight(pRoot->pRight);

    if (abs(leftHeight - rightHeight) > 1)
    {
        if (leftHeight > rightHeight)
        {
            // L-L
            if (treeHeight(pRoot->pLeft->pLeft) >= treeHeight(pRoot->pLeft->pRight))
            {
                rotateRight(pRoot);
            }

            // L-R
            else
            {
                rotateLeft(pRoot->pLeft);
                rotateRight(pRoot);
            }
        }
        
        else
        {
            // R-R
            if (treeHeight(pRoot->pRight->pRight) >= treeHeight(pRoot->pRight->pLeft))
            {
                rotateLeft(pRoot);
            }

            // R-L
            else
            {
                rotateRight(pRoot->pRight);
                rotateLeft(pRoot);
            }
        }
    }
}


/// ---------------------------- Tree traversal ---------------------------- ///

void NLR(NODE *pRoot)
{
    if (pRoot == NULL) return;
    cout << pRoot->key << " ";
    NLR(pRoot->pLeft);
    NLR(pRoot->pRight);
}

int countCond(NODE *pRoot)
{
    if (pRoot == NULL) return 0;
    
    else
    {
        if (((pRoot->pRight == NULL) && (pRoot->pLeft != NULL)) || ((pRoot->pLeft == NULL) && (pRoot->pRight != NULL)))
            return 1;

        else
            return countCond(pRoot->pLeft)
                    + countCond(pRoot->pRight);
    }
}

void LNR(NODE *pRoot)
{
    if (pRoot == NULL) return;
    LNR(pRoot->pLeft);
    cout << pRoot->key << " ";
    LNR(pRoot->pRight);
}

void LRN(NODE *pRoot)
{
    if (pRoot == NULL) return;
    LRN(pRoot->pLeft);
    LRN(pRoot->pRight);
    cout << pRoot->key << " ";
}


/// --------------------------------- Misc --------------------------------- ///

NODE *searchData(NODE *pRoot, int key)
{
    if (pRoot == NULL) return NULL;
    if (pRoot->key == key) return pRoot;
    if (key < pRoot->key) return searchData(pRoot->pLeft, key);
    else return searchData(pRoot->pRight, key);
}

void outputDecrease(NODE *pRoot)
{
    if (pRoot == NULL) return;
    outputDecrease(pRoot->pRight);
    cout << pRoot->key << " ";
    outputDecrease(pRoot->pLeft);
}

int sumAllNodes(NODE *pRoot)
{
    if (pRoot == NULL) return 0;
    return pRoot->key + sumAllNodes(pRoot->pLeft) + sumAllNodes(pRoot->pRight);
}

int sumAllLeafNodes(NODE *pRoot)
{
    if (pRoot == NULL) return 0;
    if (pRoot->pLeft == NULL && pRoot->pRight == NULL) return pRoot->key;
    return sumAllLeafNodes(pRoot->pLeft) + sumAllLeafNodes(pRoot->pRight);
}