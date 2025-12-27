#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, i = 0, a;
    cin >> N;
    vector<int> inp(N);

    for (int i = 0; i < N; i++) // get input
    {
        int x;
        cin >> x;
        inp.at(i) = x;
    }

    a = 1; // initialize
    while (i < N)
    {
        a = inp.at(a - 1);
        if (a == 2)
        {
            break;
        }
        
        i++;
    }

    if (i >= N)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << i + 1 << endl;
    }
}