#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B, a;
    cin >> N >> A >> B;
    a = N * A;
    if (a > B){
        cout << B;
    } 
    else {
        cout << a;
    }
}