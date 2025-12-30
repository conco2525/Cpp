#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<int> Num(H * W);
    //vector<string> input(H);

    for (int j = 0; j < H; j++)  //get all of the data as one array
    {
        string S;
        cin >> S;
        for (int  i = 0; i < W; i++)
        {
            if (S.at(i) == '.')
            {
                Num.at(j + i) = 0;
            }

            if (S.at(i) == '#')
            {
                Num.at(j +  i) = -9;
            }
            
            
        }

    }

    // top of the pic
    
    for (int i = 1; i < W-1; i++)
    {
        if (Num.at(i) < 0)
        {
            Num.at(i + 1)++;  
        }
        
    }
    
    
}