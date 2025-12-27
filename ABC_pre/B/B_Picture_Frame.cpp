#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    string S;
    
    for (int i = 0; i < (W + 2); i++) //top of the frame
    {
        cout << "#";
    }

    cout << endl;

    // get picture and depict
    for (int i = 0; i < H; i++)
    {
        cin >> S;
    cout << "#" << S << "#" << endl;
    }

    for (int i = 0; i < (W + 2); i++) //bottom of the frame
    {
        cout << "#";
    }
cout << endl;
}