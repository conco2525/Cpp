#include <iostream>
using namespace std;

int main()
{
    int N, a;
    cin >> N;

    cin >> a;
    cout << a << " ";

    for (int i = 0; i < (N - 1); i++)
    {
        int b;
        cin >> b;

        if (a < b)
        {
            int x = a + 1;
            while (x < b)
            {
                cout << x << " ";
                x++;
            }
        }
        if (a > b)
        {
            int x = a - 1;
            while (x > b)
            {
                cout << x << " ";
                x--;
            }
        }
        cout << b << " ";
        a = b;
    }
    cout << endl;
}