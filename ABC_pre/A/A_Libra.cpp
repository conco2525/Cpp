#include <iostream>
using namespace std;

int main()
{
    int A, B, C, D, l, r;
    cin >> A >> B >> C >> D;
    l = A + B;
    r = C + D;
    if (l > r){
         cout << "Left" << endl;
    } 
    if (r > l)
    {
         cout << "Right" << endl;
    }
    if (r == l) {
         cout << "Balanced" << endl;
    }    

   
}