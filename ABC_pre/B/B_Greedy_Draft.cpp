#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> drink(M);
    vector<int> ans(N);

    for(int j=0; j < N; j++){
    int L=0;
    cin >> L;
    bool find=true;
    for (int i = 0; i < L; i++){
        int x=0;
        cin >> x;
        if(drink.at(x -1) == 0 && find){
            ans.at(j) = x;
            drink.at(x -1) = 1;
            find = false;
        }
    }
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans.at(i) << endl;
    }
    
}