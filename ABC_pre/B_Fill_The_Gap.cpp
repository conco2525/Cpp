#include <iostream>
using namespace std;

int main()
{
    int N, x, y, i, j, M, m;
    cin >> N;
    i = 0;
    M = max(x, y);
    m = min(x, y);

    while (i < N)
    {
    cin >> x >> y;
        if ((M - m) != 1)
        {
            cout << m << " ";
            j = m;
            while (j < M)
            {
                m++;
                cout << m << " ";
                j++;
            }
        }
        else
        {
            cout << m << " " << M << " ";
        }
        i++;
    }
}