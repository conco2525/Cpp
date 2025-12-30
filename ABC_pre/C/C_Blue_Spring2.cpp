#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> x, int N){
    int y =0;
    for (int i = 0; i < N; i++)
    {
        y += x.at(i);
    }
return y;
}

int main() {
    int N, D, P;
    cin >> N >> D >> P;
    vector<int> F(N);

    for (int i = 0; i < N; i++)
    {
        cin >> F.at(i);
    }
    sort(F.begin(), F.end());
    reverse(F.begin(), F.end());
    int ans = sum(F, N);
    int m = ans;

    for (int i = 0; i < (N / D); i++)
    {
        m = m - sum(F, D) + P;
        F.erase(F.begin(), F.begin() + D);
        ans = min(m, ans);
    }
    ans = min((P * ((N + D -1) / D)), ans);
    
cout << ans << endl;

}
