#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, a, j = 0, counter = 0;
    cin >> N >> M;
    vector<int> ans(N), inp(M * 2); // this will be the answer

    // get the input
    for (int i = 0; i < (M * 2); i++)
    {
        cin >> inp.at(i);
    }

    // count "1" town
    while (j < (N))
    {
        for (int i = 0; i < (M * 2); i++)   // the number of town is double of that of road
        {
            a = inp.at(i);
            if (a == (j + 1))       // this means a is 1 town(j = 0)
            {
                counter++;
                ans.at(j) = counter;
            }

        }       // Ok we now got the vector of 1
        j++;
        counter = 0; // inicialize the counter
                // do this 1, 2, 3, ... N city(this is N times)
    }
                // then, cout the answer

    for (int k = 0; k < N; k++)
    {
        cout << ans.at(k) << endl;
    }
}