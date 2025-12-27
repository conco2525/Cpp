#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 1, N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        if (K > x)
        {
            x += x;
        }
        else
        {
            x += K;
        }
    }
    cout << x << endl;
}

// 8:50