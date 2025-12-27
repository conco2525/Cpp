#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, ans;
    cin >> N;

    for (int j = 0; j < N; j++)
    {
        int x, counter=0;
        cin >> x;

        for (int i = 0; true; i++)
        {
            if ((x % 2) == 0)
            {
                x = x / 2;
                counter++;
            }

            else
            {
                break;
            }

        }
    
    if (j == 0)
    {
        ans = counter;
    }
        

    ans = min(ans, counter);
        
    }

cout << ans << endl;
}