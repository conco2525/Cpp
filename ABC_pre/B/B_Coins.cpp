#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, W, counter=0;
    cin >> a >> b >> c >> W;

    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            for (int k = 0; k <= c; k++)
            {
                int x;
                x = i * 500 + j * 100 + k * 50;
                if (x == W)
                {
                    counter++;
                }
                
                
            }
            
        }
        
    }
    
cout << counter << endl;
}