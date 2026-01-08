#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> x, int N)
{
    int y = 0;
    for (int i = 0; i < N; i++)
    {
        y += x.at(i);
    }
    return y;
}

int main()
{
    int N, D, P;
    cin >> N >> D >> P;
    vector<int> F(N);
    for (int i = 0; i < N; i++)
    {
        cin >> F.at(i);
    }
    sort(F.begin(), F.end());
    reverse(F.begin(), F.end());


}