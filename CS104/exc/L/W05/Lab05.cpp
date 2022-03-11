/*Viết chương trình C++ cài đặt cấu trúc dữ liệu cây nhị phân tìm kiếm
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

//Câu 1: Hoàn thiện hàm tạo NODE mới
NODE* createNode(int k) {
    //Cấp phát vùng nhớ mới cho biến con trỏ pNew
    NODE* pNew = new NODE();
    //Kiểm tra cấp phát vùng nhớ thành công hay không?
    if (pNew == NULL) {
        cout << "Khong du bo nho cap phat";
        return NULL;
    }
    //Gán giá trị k vào node mới
    pNew->key = k;

    //Gán liên kết trái và liên kết phải bằng NULL.
    pNew->pLeft = NULL;
    pNew->pRight = NULL;

    return pNew;
}

//Câu 2: Hoàn thiện hàm thêm 1 khóa k vào cây nhị phân tìm kiếm (BST)
void insertNode(NODE* &pRoot, int k)
{
    //Kiểm tra cây rỗng, nếu rỗng thì tạo node mới từ khóa k
    if (pRoot == NULL)
    {
        pRoot = createNode(k);
        return;
    }

    //Đệ quy trái/phải
    if (k < pRoot->key)
    {
        insertNode(pRoot->pLeft, k);
    }
    
    else
    {
        insertNode(pRoot->pRight, k);
    }
}

//Câu 3: Hoàn thiện các hàm duyệt giữa, duyệt sau
//Duyệt cây pre-order
void NLR(NODE* pRoot)
{
    if (pRoot == NULL) return;
    cout << pRoot->key << " ";
    NLR(pRoot->pLeft);
    NLR(pRoot->pRight);
}

//Duyệt cây in-order
void LNR(NODE* pRoot)
{
    if (pRoot == NULL) return;
    LNR(pRoot->pLeft);
    cout << pRoot->key << " ";
    LNR(pRoot->pRight);
}

//Duyệt cây post-order
void LRN(NODE* pRoot)
{
    if (pRoot == NULL) return;
    LRN(pRoot->pLeft);
    LRN(pRoot->pRight);
    cout << pRoot->key << " ";
}

//Câu 4: Hoàn thiện hàm tìm kiếm giá trị k trên cây
//Trả về NULL nếu không tìm thấy
//Trả về node chứa giá trị k cần tìm
NODE* searchData(NODE *pRoot, int k)
{
    if (pRoot == NULL) return NULL;
    if (pRoot->key == k) return pRoot;
    if (k < pRoot->key) return searchData(pRoot->pLeft, k);
    else return searchData(pRoot->pRight, k);
}

//Câu 5: Hoàn thiện hàm xóa một node có giá trị k ra khỏi cây BST
void deleteNode(NODE* &pRoot, int key)
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
            NODE* pTemp = pRoot;
            pRoot = pRoot->pRight;
            delete pTemp;
        }
        
        else if (pRoot->pRight == NULL)
        {
            NODE* pTemp = pRoot;
            pRoot = pRoot->pLeft;
            delete pTemp;
        }
        
        else
        {
            // Nhỏ nhất bên phải
            NODE* pTemp = pRoot->pRight;
            
            while(pTemp->pLeft != NULL)
            {
                pTemp = pTemp->pLeft;
            }
            
            pRoot->key = pTemp->key;
            deleteNode(pRoot->pRight, pTemp->key);
        }
    }
}

/*Câu 6: Hoàn thiện hàm main để thực hiện
- Thêm các NODE mới vào cây BST với các khóa nhập từ bàn phím
- In giá trị các node trong cây BST theo phép duyệt trước, duyệt giữa và duyệt sau
- Tìm kiếm một khóa k nhập từ bàn phím có tồn tại trong cây BST hay không?
Nếu có in ra "YES"; Nếu không có in ra "NO"
- Xóa một node có giá trị k được nhập từ bàn phím.
In kết quả cây sau khi xóa ra màn hình.
*/
int main()
{
    // Thêm các NODE mới vào cây BST với các khóa nhập từ bàn phím
    NODE* pRoot = NULL;
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cout << "Nhap khong phan tu thu " << i + 1 << ": ";
        cin >> k;
        insertNode(pRoot, k);
    }
    
    // In giá trị các node trong cây BST theo phép duyệt trước, duyệt giữa và duyệt sau
    cout << "\nDuyet cay theo thu tu truoc: ";
    NLR(pRoot);
    cout << "\n";
    cout << "\nDuyet cay theo thu tu giua: ";
    LNR(pRoot);
    cout << "\n";
    cout << "\nDuyet cay theo thu tu sau: ";
    LRN(pRoot);
    cout << "\n";
    
    // Tìm kiếm một khóa k nhập từ bàn phím có tồn tại trong cây BST hay không? Nếu có in ra "YES"; Nếu không có in ra "NO"
    int k;
    cout << "\nNhap k can tim: ";
    cin >> k;
    NODE* pNode = searchData(pRoot, k);
    
    if (pNode == NULL) cout << "NO" << "\n";
    else cout << "YES" << "\n";
    
    // Xóa một node có giá trị k được nhập từ bàn phím.
    cout << "\nNhap k can xoa: ";
    cin >> k;
    deleteNode(pRoot, k);
    cout << "Cay sau khi xoa (NLR): ";
    NLR(pRoot);
    cout << "\n";
    
    return 0;
}