#include <iostream>
using namespace std;

int main()
{
    int N, A, M;
    cin >> N >> A;
    M = N % 500;
    if (M > A)
    {
        cout << "No" << endl; /* code */
    }
    if (M <= A)
    {
        cout << "Yes" << endl; /* code */
    }
}