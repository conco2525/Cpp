#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    int ans=0;
    for (int i = 0; i < N; i++)
    {
        char t = S.at(i);
        if (t == 'o'){
            ans++;
        }
        
    }
    if (ans % 2) cout << "odd" << endl;
    else cout << "even" << endl;
    
}