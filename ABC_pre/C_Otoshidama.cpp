#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Y, counter = 0, a = -1, b = -1, c = -1;
    cin >> N >> Y;

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= (N - i); j++)
        {

            if ((i * 10000 + j * 5000 + (N - j - i) * 1000) == Y)
            {
                counter++;
                a = i;
                b = j;
                c = (N - j - i);
            }
        }
    }

    cout << a << " " << b << " " << c << " " << endl;
}