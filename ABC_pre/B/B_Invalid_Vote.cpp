#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> can(N);
    vector<int> count(N);

    for(int i=0;i<N;i++) cin >> can.at(i);

    for(int i = 0; i < M; i++)
    {
        string s;
        cin >> s;
        for(int j=0;j<N;j++)
        {
            
            int k=0, check=0;
            while(1){
                if(s.at(k) != can.at(j).at(k)){
                    check++;
                }
                if(check > 1) break;
                else if(k == s.size() -1) {
                    count.at(j)++;
                    break;
                }
                k++;
            }
        }
        
    }

    for (int i = 0; i < N; i++)
    {
        cout << count.at(i) << endl;
    }
    
    
}