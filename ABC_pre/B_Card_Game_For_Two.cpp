#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Alice=0, Bob=0;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++){ cin >> S.at(i); }
    sort (S.begin(), S.end());
    reverse(S.begin(), S.end());

    for (int i = 0; i < N; i++)
    {
        if ((i & 1) == 0)
        {
            Alice += S.at(i);
        }
        
        else{
            Bob += S.at(i);
        }
    }

cout << (Alice - Bob) << endl;
    
}
