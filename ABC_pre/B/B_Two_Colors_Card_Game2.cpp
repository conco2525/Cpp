#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, score=0, ans=0;
    vector<string> S(110);
    vector<string> T(110);

    // get these input
    cin >> N;
    for (int i = 0; i < N; i++){cin >> S.at(i);}
    cin >> M;
    for (int i = 0; i < M; i++){cin >> T.at(i);}

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (S.at(i) == S.at(j)){score++;}
        }
        for (int j = 0; j < M; j++)
        {
            if (S.at(i) == T.at(j)){score--;}
        }
    ans = max(score, ans);
    score = 0;
    }
cout << ans << endl;
}