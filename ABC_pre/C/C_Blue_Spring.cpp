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
    int N, D, P, ans;
    cin >> N >> D >> P;
    vector<int> F(N);

    for (int i = 0; i < N; i++)
    {
        cin >> F.at(i);
    }
    sort(F.begin(), F.end());
    reverse(F.begin(), F.end());
    ans = sum(F, N);

    for (int i=1; true; i++)
    {
        int m;
        if(F.size() >= D){
        F.erase(F.begin(), F.begin() + D);
        m = sum(F, F.size()) + P * i;
        ans = min(m, ans);
        }
        else {m = P * i;
        ans = min(m, ans);
        break;}
        
    }
cout << ans << endl;

}
