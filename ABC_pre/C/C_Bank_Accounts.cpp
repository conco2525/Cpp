#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    vector<string> acc;
    string s;

    cin >> s;
    acc.push_back(s);
    cout << "1" << endl;

    for(int i=0; i<Q-1; i++){
        cin >> s;
        int j=0, ret=0;
        while(1){
            if(j == acc.size()){
                acc.push_back(s);
                ret = j + 1; 
                break; 
            }
            if(s == acc.at(j)){
                ret = j + 1;
                break;
            }
            j++;
        }
        cout << ret << endl;
    }
}