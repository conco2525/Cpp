#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N, Y, a, b, c, d, g, h;
    cin >> N >> Y;
    Y /= 1000;
    a = Y / 5;
    b = Y % 5;
    if (N < b)
    {
        cout << "-1" << " " << "-1" << " " << "-1" << endl;
    }

    else
    {

        c = N - b;

        if ((((a + 1) / 2) <= c) && (c <= a))
        {
            cout << (a - c) << " " << (2 * c - a) << " " << b << endl;
        }

        else if ((a < c) && (c <= (5 * a)))
        {
            d = c - a;

            if ((d % 4) == 0)
            {
                g = d / 4;
                h = 0;
            }
            if ((d % 4) != 0)
            {
                g = d / 4 + 1;
                h = 4 - d % 4;
            }

            if (a < (g + 2 * h))
            {
                cout << "-1" << " " << "-1" << " " << "-1" << endl;
            }

            else if ((a >= (g + 2 * h)))
            {

                cout << h << " " << a - 2 * h - g << " " << 5 * g + b << endl;
            }
        }

        else
        {
            cout << "-1" << " " << "-1" << " " << "-1" << endl;
        }

        cout << a << " " << b << " " << c << " " << d << " " << g << " " << h;
    }
}
