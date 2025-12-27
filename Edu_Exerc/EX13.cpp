#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, S = 0;
    cin >>N;
    vector<int> score(N);

    for (int i = 0; i < N; i++)
    {
        cin >> score.at(i);
        S += score.at(i);
    }

    int m;
    m = S / N;

    for (int i = 0; i < N; i++)
    {
        cout << abs(m - score.at(i)) << endl;
    }
}