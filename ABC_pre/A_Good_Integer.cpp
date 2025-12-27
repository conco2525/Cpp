#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, a, b, c, d;
    cin >> N;
    d = N % 10;
    a = N / 1000;
    b = N / 100 - a * 10; 
    c = N / 10 - a * 100 - b * 10;
if (a == b && b == c && c == d ){
    cout << "Yes" << endl;
}
else if (a == b && b == c ){
    cout << "Yes" << endl;
}
else if (c == b && d == c ){
    cout << "Yes" << endl;
}
else {
    cout << "No" << endl;
}
}