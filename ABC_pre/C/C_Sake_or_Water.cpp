#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K, X, ans, sum=0;
    cin >> N >> K >> X;
    vector<int> A(N);
    ans = N - K;

    for(int i=0; i < N; i++){
        cin >> A.at(i);
    }

    sort(A.begin(), A.end(), greater<int>());
    for (int i = (N - K); i < N; i++)
    {
        sum += A.at(i);
        ans++;
        if (sum >= X)
        {
            break;
        }
        else if (i == (N - 1))
        {
            ans = -1;
        }
        
    }
cout << ans << endl;
}