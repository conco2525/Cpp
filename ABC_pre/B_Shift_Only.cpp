#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N, x, C = 0, D= 0, m = 0, I = 0;
    cin >> N;
    cin >> x;

    for (int k = 0; true; k++)
        {
            D = x % 2;

            if (D == 0)
            {
                x = x / 2;
                I++;
            }
            else
            {
                break;  
            }
        }

        m = I;

    for (int j = 0; j < (N - 1); j++)
    {
        C = 0;
        cin >> x;
        for (int i = 0; true; i++)
        {
            D = x % 2;

            if (D == 0)
            {
                x = x / 2;
                C++;
            }
            else
            {
                break;
            }
        }
        m = std::min(m, C);
    }

    cout << m << endl;
}

// 41min