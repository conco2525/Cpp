#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;
    bool ans = true;
    
    for (int i = 0; i < N; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;

        if ((x + y) > t)
        {
            ans = false;
        }
        
        if (((x + y) % 2) != (t % 2))
        {
            ans = false;
        }
        
    }
    
if (ans)
{
    cout << "Yes" << endl;
}
else{
    cout << "No" << endl;
}

}