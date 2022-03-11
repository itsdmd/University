#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int n;

    cout << endl << "Nhap mot so co gia tri tu 0 den 9: ";
    cin >> s;

    n = stoi(s);        // Đổi string qua int

    if (n >= 0 && n <= 9)
    {
        switch (n)
        {
        case 0: cout << "Khong";
            break;
        case 1: cout << "Mot";
            break;
        case 2: cout << "Hai";
            break;
        case 3: cout << "Ba";
            break;
        case 4: cout << "Bon";
            break;
        case 5: cout << "Nam";
            break;
        case 6: cout << "Sau";
            break;
        case 7: cout << "Bay";
            break;
        case 8: cout << "Tam";
            break;
        case 9: cout << "Chin";
            break;
        }
    }

    else
    {
        cout << "Khong doc duoc." << endl;
        main();
    }
    
    return 0;
}