#include <iostream>
using namespace std;

int main()
{
    int N, i, D;
    string a;
    i = 0;
    D = 0;
    cin >> N;
    while (i < N)
    {
        cin >> a;
        if (a == "Y")
        {
            cout << "Four" << endl;
            D = 1;
            break;
        }
       else{
        i++;
       }      
    }
    if (D != 1)
    {
        cout << "Three" << endl;
    }
    
        
}