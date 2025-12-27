#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, score, N_counter, M_counter, j = 0, Max = 0;
    cin >> N;
    string word;
    vector<string> Ninp;
    vector<string> Minp;

    // get these input
    for (int i = 0; i < N; i++)
    {
        cin >> Ninp.at(i);
    }
    cin >> M;
        for (int i = 0; i < M; i++)
    {
        cin >> Minp.at(i);
    }


    while (j < max(M, N))
    {
        if (Ninp.size() > Minp.size())
        {
            word = Ninp.at(j);
        }

        if (Ninp.size() < Minp.size())
        {
            word = Minp.at(j);
        }
  
        
    
    
    for (int i = 0; i < N; i++) //count the word in N
    {
        if (Ninp.at(i) == word)
        {
            N_counter++;
        }
        
    }
    
    for (int i = 0; i < M; i++) // count the word in M
    {
        if (Minp.at(i) == word)
        {
            M_counter++;
        }
    }

    score = N_counter - M_counter;

    Max = max(Max, score);
    }
    
}