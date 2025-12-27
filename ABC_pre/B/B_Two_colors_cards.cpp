#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, score, N_counter, M_counter, j = 0, Max, NMax = 0, MMax, k;
    cin >> N;
    string word;
    vector<string> Ninp(N);

    // get these input
    for (int i = 0; i < N; i++)
    {
        cin >> Ninp.at(i);
    }
    cin >> M;
    vector<string> Minp(M);
        for (int i = 0; i < M; i++)
    {
        cin >> Minp.at(i);
    }

    while (j < (N)) 
    {

        word = Ninp.at(j);

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

    NMax = max(NMax, score);

    N_counter = 0;
    M_counter = 0;
    j++;
    }

while (k < (M)) 
    {
        
    word = Minp.at(k);
  
            
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

    MMax = max(MMax, score);

    N_counter = 0;
    M_counter = 0;
    k++;
    }

Max = max(NMax, MMax);
cout << Max << endl;
}