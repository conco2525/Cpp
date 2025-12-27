#include <bits/stdc++.h>
using namespace std;

int main() {
    int counter = 0;
    string S;
    cin >> S;
    
    for (int i = 0; i < 3; i++)
    {
        
        if (S.at(i) == '1')
        {
            counter++;
        }
        
    }
cout << counter << endl;

}