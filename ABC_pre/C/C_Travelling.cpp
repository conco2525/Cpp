#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;
    bool ans = true;
    int t, x, y, T=0, X=0, Y=0;

    for (int i = 0; i < N; i++)
    {        
        cin >> t >> x >> y;

        if (abs(x - X) + abs(Y - y) > (t -T))
        {
            ans = false;
        }
        
        if (((x + y) % 2) != (t % 2))
        {
            ans = false;
        }

        T = t;
        X = x;
        Y = y;
        
    }
    
if (ans)
{
    cout << "Yes" << endl;
}
else{
    cout << "No" << endl;
}

}