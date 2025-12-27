#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, M, S = 0, x;
    cin >> N >> K;
    M = (K + 1) / 2;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (x < M)
        {
            S += x;
        }
        else{
            S += (K - x);
        }
        
    }
cout << S * 2 << endl;
}