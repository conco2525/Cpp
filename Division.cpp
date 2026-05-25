#include <bits/stdc++.h>
using namespace std;

int div(int a, int b, char s, int c, int d){
    if (b == 0 || c == 0) return 0;
    if(s == '+'){
        int x, y, z;
        x = a*d + b*c;
        y = b*d; 
        z = gcd(x, y);
        x = x / z;
        y = y / z;
        return x, y;
    }
    
}

int main() {
    int a, b, c, d;
    char s;
    cin >> a >> b >> s >> c >> d;
    cout << div(a, b, s, c, d) << endl;
}