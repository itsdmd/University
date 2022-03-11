/*Viết chương trình C++ cài đặt cấu trúc dữ liệu cây nhị phân tìm kiếm
  Họ và tên SV:
  MSSV:  
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
    //TODO: Code here

    //Gán liên kết trái và liên kết phải bằng NULL.
    //TODO: Code here

    return pNew;
}

//Câu 2: Hoàn thiện hàm thêm 1 khóa k vào cây nhị phân tìm kiếm (BST)
void insertNode(NODE* &pRoot, int k) {
    //Kiểm tra cây rỗng, nếu rỗng thì tạo node mới từ khóa k
    //TODO: Code here

    //Đệ quy trái/phải
    //TODO: Code here
}

//Câu 3: Hoàn thiện các hàm duyệt giữa, duyệt sau
//Duyệt cây pre-order
void NLR(NODE* pRoot) {
    if(pRoot == NULL) return;
    cout << pRoot->key << " ";
    NLR(pRoot->pLeft);
    NLR(pRoot->pRight);
}

//Duyệt cây in-order
void LNR(NODE* pRoot) {
    //TODO: Code here
}

//Duyệt cây post-order
void LRN(NODE* pRoot) {
    //TODO: Code here
}

//Câu 4: Hoàn thiện hàm tìm kiếm giá trị k trên cây
//Trả về NULL nếu không tìm thấy
//Trả về node chứa giá trị k cần tìm
NODE* searchData(NODE *pRoot, int k) {
    //TODO: Code here
}

//Câu 5: Hoàn thiện hàm xóa một node có giá trị k ra khỏi cây BST
void deleteNode(NODE* &pRoot, int key) {
    if(key < pRoot->key) {
        //TODO: gọi đệ quy sang cây con trái
    }
    else if(key > pRoot->key) {
        //TODO: gọi đệ quy sang cây con phải
    }
    else {//Tìm thấy node cần xóa
        if(/*TODO: nếu là node lá*/) {
            //TODO: code here
        }
        else if (/*TODO: nếu là node có một con bên trái*/) {
            //TODO: code here
        }
        else if (/*TODO: nếu là node có một con bên phải*/) {
            //TODO: code here
        }
        else { //Node có 2 con
            /* Tìm phần tử thế mạng:
            - Nhỏ nhất bên cây con phải
            - Lớn nhất bên cây con trái */
            //TODO: code here

            //Chép giá trị phần tử thế mạng lên node có 2 con cần xóa
            //TODO: code here

            //Gọi đệ quy cây con trái/phải để xóa node chứa giá trị thế mạng
            //TODO: code here
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
int main() {
    //TODO: code here
    return 0;
}

