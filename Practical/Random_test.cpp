#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N = 200;
    srand(static_cast<unsigned int>(time(0)));
    vector<int> SumOfDice(N);

    for (int i = 0; i < N; i++)
    {
        int dice = 0;
        for (int i = 0; i < 20; ++i)
        {
            dice += rand() % 6;
            
        }
        SumOfDice.at(dice)++ ;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < SumOfDice.at(i); j++)
        {
            cout << "]";
        }
        cout << endl;
    }
    
}