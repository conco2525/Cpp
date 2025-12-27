#include <bits/stdc++.h>
using namespace std;

int main()
{

    int A, B, D, x, S = 0, d = 0, p, q, r, s;
    cin >> A >> B;
    x = A;
    for (int i = 0; i < (B - A + 1); i++)
    {
        s = x % 10;
        r = (x / 10) % 10;
        q = (x / 1000) % 10;
        p = (x / 10000);

        if ((s == p) && (r == q))
        {
            S++;
        }
        x++;
    }

    cout << S << endl;
}