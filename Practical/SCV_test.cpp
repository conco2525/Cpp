#include <bits/stdc++.h>
using namespace std;

int main() {
    string outfile="output.csv";
    ofstream ofs(outfile);

    int N = 130;
    srand(static_cast<unsigned int>(time(0)));
    vector<int> SumOfDice(N);

    for (int i = 0; i < 3000; i++)
    {
        int dice = 0;
        for (int i = 0; i <20; ++i)
        {
            dice += rand() % 6 + 1;
            
        }
        SumOfDice.at(dice)++ ;
    }

    for (int i = 0; i < N; i++)
    {
        ofs << SumOfDice.at(i);
        if (i != (N - 1))
        {
            ofs << ",";        }
        
    }
    
    ofs << endl;

}