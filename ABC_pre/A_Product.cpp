#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, x;
    cin >> a >> b;
    x = (a * b) % 2;

    if (x == 1)
    {
        cout << "Odd" << endl;
    }

    if (x == 0)
    {
        cout << "Even" << endl;
    }
    

}