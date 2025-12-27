#include <bits/stdc++.h>
using namespace std;

int main() {

    int X, a, D;
    cin >> X;
    a = X % 10;
    D = X / 10;
    while (D != (D % 10)) 
    {
        a += (D % 10);
        D = D / 10;
    }

    if ((X % (D + a)) == 0)
    {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}