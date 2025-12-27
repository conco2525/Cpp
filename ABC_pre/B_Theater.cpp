#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, p, l, r, S = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> l >> r;
        p = r - l + 1;
        S += p;
    }
    cout << S << endl;
}