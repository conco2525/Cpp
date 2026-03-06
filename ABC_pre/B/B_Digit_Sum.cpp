#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, ans=0;
    cin >> N >> K;
    for(int i=1; i < N+1; i++){
        int a, b, c, d, e, f;
        a = i / 100000;
        e = i % 10;
        d = (i / 10) % 10;
        c = (i / 100) % 10;
        b = (i / 1000) % 10;
        f = (i / 10000) % 10;

        int sum;
        sum = a + b + c + d + e + f;
        if (sum == K) ans++; 
    }
cout << ans << endl;
}