#include <iostream>
using namespace std;

int main()
{
    int a, b, M, m, x, N;
    cin >> N >> a >> b;

    for (int i = 0; i < (N); i++) // A1-An
    {
        M = max(a, b);
        m = min(a, b);

        if (a < b)
        {
            while ((M - m) != 0)
            {
               cout << m << " ";
                    m++;
            }
        }

        if (a > b)
        {
            while ((M - m) != 0)
            {
                cout << M << " ";
                M--;
            }
        }
        // f(a, b)

        cin >> x;
        a = b;
        b = x;
    }

cout << b << endl;
}