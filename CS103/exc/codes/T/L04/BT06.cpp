#include <iostream>
#include <climits>
using namespace std;

int main()
{
    long long arr[4], temp;

    cout << endl << "Nhap 4 so nguyen a, b, c, d: ";
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];

    for (int i = 0; i < 3; i++)     // Vòng xét chuỗi
    {
        for (int j = 0; j < 3; j++) // Vòng xét hoán vị
        {
            if (arr[j] > arr[j+1])
            {
                // Hoán vị
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }


    cout << endl << "Thu tu tang dan cua 4 so nguyen: ";
    
    for (int k = 0; k < 4; k++)
    {
        cout << fixed << arr[k] << " ";
    }

    cout << endl;
   
    
    return 0;
}