#include <iostream>
#include <climits>
using namespace std;

int main()
{
    long long a, b, c, d, _min;

    cout << endl << "Nhap 4 so nguyen a, b, c, d: ";
    cin >> a >> b >> c >> d;

    
    // Gán max để tránh vào case 0 không mong muốn khi chạy switch-case
    if (a == c)
    {
        a = LONG_LONG_MAX;
    }

    if (a == b || a == d)
    {
        a = LONG_LONG_MAX;
    }

    if (c == b || c == d)
    {
        c = LONG_LONG_MAX;
    }


    switch (a > b)
    {
        case 0: // b > a
        {
            switch (c > b)
            {
                case 0: // b > a, b > c
                {
                    switch (a > c)
                    {
                        case 0: // b > a, b > c, c > a
                        {
                            switch (a > d)
                            {
                                case 0: // b > a, b > c, c > a, d > a
                                {
                                    //cout << "E1";
                                    _min = a;
                                    break;
                                }

                                case 1: // b > a, b > c, c > a, a > d
                                {
                                    //cout << "E2";
                                    _min = d;
                                    break;
                                }
                            }

                            break;
                        }

                        case 1: // b > a, b > c, a > c
                        {
                            switch (c > d)
                            {
                                case 0: // b > a, b > c, a > c, d > c
                                {
                                    //cout << "E3";
                                    _min = c;
                                    break;
                                }

                                case 1: // b > a, b > c, a > c, c > d
                                {
                                    //cout << "E4";
                                    _min = d;
                                    break;
                                }
                            }

                            break;
                        }
                    }
                }

                case 1: // b > a, c > b
                {
                    switch(a > d)
                    {
                        case 0: // b > a, c > b, d > a
                        {
                            //cout << "E5";
                            _min = a;
                            break;
                        }

                        case 1: // b > a, c > b, a > d
                        {
                            //cout << "E6";
                            _min = d;
                            break;
                        }
                    }

                    break;
                }
            }

            break;
        }

        case 1: // a > b
        {
            switch (c > b)
            {
                case 0: // a > b, b > c
                {
                    switch (d > c)
                    {
                        case 0: // a > b, b > c, c > d
                        {
                            //cout << "E7";
                            _min = d;
                            break;
                        }

                        case 1: // a > b, b > c, d > c
                        {
                            //cout << "E8";
                            _min = c;
                            break;
                        }
                    }

                    break;
                }

                case 1: // a > b, c > b
                {
                    switch (d > b)
                    {
                        case 0: // a > b, c > b, b > d
                        {
                            //cout << "E9";
                            _min = d;
                            break;
                        }
                        
                        case 1: // a > b, c > b, d > b
                        {
                            //cout << "E10";
                            _min = b;
                            break;
                        }
                    }

                    break;
                }
            }

            break;
        }
    }

    cout << endl << "So nho nhat la: " << fixed << _min << endl;
    
    return 0;
}