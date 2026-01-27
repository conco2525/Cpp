#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    string S, T;
    cin >> N >> M >> S >> T;
    vector<int> sv(N), tv(M);
    
    
    int m = 1e9;
    for(int j=0; j < (N - M + 1); j++){

    int diff=0;
    for (int i = 0; i < M; i++){

        if((sv.at(i + j) - tv.at(i)) >= 0){
            diff += (sv.at(i + j) - tv.at(i));
        }

        else{
            diff += (sv.at(i + j) - tv.at(i) + 10);
        }
    }
//    cout << diff << endl;
    m = min(m, diff);
    }

    cout << m << endl;
}