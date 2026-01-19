#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N=5;
    srand(static_cast<unsigned int>(time(0)));
    vector<int> box(N);
    int firstball = 0, secondball = 0, trial = 10000000;

    for (int i = 0; i < trial; i++)
    {
        int red = rand() % N;

        // prepare box which contains some red balls
        for (int j = 0; j < red; j++)
        {
            box.at(j) = 1;
        }

        int z = rand() % N;

        if (box.at(z))          // when the first ball is red
        {
            firstball++;
            int y = z;
            while (y == z){
                y = rand() % N;
            }
            if (box.at(y)) // when the second one is also red
            {
                secondball++;
            }
        }
        else{
            continue;
        }

        for (int i = 0; i < N; i++)
        {
            box.at(i) = 0;
        }
        
    }

    cout << "trial1:" << firstball << " then trial2:" << secondball << endl;
}