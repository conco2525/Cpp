#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, m=0;
    cin >> N;

    // find the m and get S as array

    vector<string> S(N);
    for (int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        S.at(i) = a;
        int b = a.size();
        m = max(m, b);
    }
    

    // output all strings
    
    for(int j=0; j < N; j++){
    string s=S.at(j);
    int x = s.size();
        for (int i = 0; i < (m - x)/2; i++)
        {
            cout << ".";
        }
        cout << s;
        for (int i = 0; i < (m - x)/2; i++)
        {
            cout << ".";
        }
    cout << endl;
    }
}