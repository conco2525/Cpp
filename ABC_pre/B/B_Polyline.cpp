#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, a, ans=0;
    cin >> N >> K >>a;

    if(a == K) ans=1;

    for(int i=0; i<N; i++){
        int b;
        cin >> b;
        if((a-K)*(b-K) < 0) ans++;
        else if(b == K) ans++;
        a = b;
    }
    cout << ans << endl;
}