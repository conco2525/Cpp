#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 1, i = 1, N;
    string S;
    char p;
    cin >> S;
    N = S.size();
    while (i < N)
    {
        p = S.at(i);

        if (p == '+')
        {
            x++;
        }
        else{
            x--;
        }
        
    i = i + 2;

    }
cout << x << endl;
}