#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N, M, Q;
    string S, T;
    cin >> N >> M >> S >> T >> Q;
    int takahashi = 0, aoki = 0;

    for (int k = 0; k < Q; k++)
    {

        // check one word
        string x;
        cin >> x;
        for (int i = 0; i < x.size(); i++)
        {

            int a=0, b=0;
            // check one character
            // check takahashi
            for (int j = 0; j < N; j++)
            {
                if (x.at(i) == S.at(j))
                {
                    a = 1;
                }
            }
            // check aoki
            for (int j = 0; j < M; j++)
            {
                if (x.at(i) == T.at(j))
                {
                    b = 1;
                }
            }
            if (a)
            {
                takahashi++;
            }
            if (b)
            {
                aoki++;
            }
            

        }

        if (takahashi == x.size() && aoki == x.size())
        {
            cout << "Unknown" << endl;
        }

        else if (takahashi == x.size())
        {
            cout << "Takahashi" << endl;
        }

        else if (aoki == x.size())
        {
            cout << "Aoki" << endl;
        }

        takahashi = 0;
        aoki = 0;
    }
}