#include <bits/stdc++.h>
using namespace std;

int main() {
    int P, Q, a, b;
    cin >> P >> Q >> a >> b;
    if(a < P || a > (P +99) || b < Q || b > (Q + 99)){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }

}