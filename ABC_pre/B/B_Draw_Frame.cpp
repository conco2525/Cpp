#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    for (int i = 0; i < W; i++)
    {
        cout << "#";
    }
    cout << endl;

    for (int j = 0; j < H - 2; j++)
    {
        cout << "#";
        for (int i = 0; i < W - 2; i++)
        {
            cout << ".";
        }
        cout << "#" << endl;
    }

    for (int i = 0; i < W; i++)
    {
        cout << "#";
    }
    cout << endl;
}