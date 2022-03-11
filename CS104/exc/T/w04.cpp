#include <iostream>
#include <string>

using namespace std;



/// ------------------------------------------------------------------------ ///
///                               Declarations                               ///
/// ------------------------------------------------------------------------ ///

// Create node for binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create new node
Node* NewNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Find node in binary tree, return NULL if not found
Node* FindNode(Node* pRoot, int data)
{
    if (pRoot == NULL)
        return NULL;
        
    if (pRoot->data == data)
        return pRoot;
        
    Node* pLeft = FindNode(pRoot->left, data);
    
    if (pLeft != NULL)
        return pLeft;
        
    return FindNode(pRoot->right, data);
}

// Insert node into binary tree
bool InsertNode(Node*& pRoot, int data) {
    if (pRoot == NULL)
    {
        Node *p_New= NewNode(data);
        pRoot = p_New;
        
        return true;
    }
    
    if (data < pRoot->data)
        return InsertNode(pRoot->left, data);
    
    else if (data > pRoot->data)
        return InsertNode(pRoot->right, data);
    
    else
        return false;
}

// Delete node from binary tree
bool DeleteNode(Node*& pRoot, int data) {
    if (pRoot == NULL)
        return false;
    
    if (data < pRoot->data)
        return DeleteNode(pRoot->left, data);
    
    else if (data > pRoot->data)
        return DeleteNode(pRoot->right, data);
    
    else
    {
        if (pRoot->left == NULL && pRoot->right == NULL)
        {
            delete pRoot;
            pRoot = NULL;
            return true;
        }
        
        else if (pRoot->left == NULL)
        {
            Node* temp = pRoot;
            pRoot = pRoot->right;
            delete temp;
            return true;
        }
        
        else if (pRoot->right == NULL)
        {
            Node* temp = pRoot;
            pRoot = pRoot->left;
            delete temp;
            return true;
        }
        
        else
        {
            Node* temp = FindNode(pRoot->left, data);       // Nhỏ nhất trong cây con phải
            pRoot->data = temp->data;
            DeleteNode(pRoot->left, temp->data);
            return true;
        }
    }
}



/// ------------------------------------------------------------------------ ///
///                                 Functions                                ///
/// ------------------------------------------------------------------------ ///

int main()
{
    //
    
    return 0;
}