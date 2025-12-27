#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, A, B, i;
    string p;
    cin >> N >> A;
    i = 0;
    while (i < N)
    {
        cin >> p >> B;
        if (p == "+")
        {
            A = A + B;
        }
        else if (p == "-")
        {
            A = A - B;
        }
        else if (p == "*")
        {
            A = A * B;
        }
        else if (p == "/" && B != 0)
        {
            A = A / B;
        }
        else
        {
            cout << "error" << endl;
            break;
        }
        cout << i + 1 << ":" << A << endl;
        i++;
    }
}
