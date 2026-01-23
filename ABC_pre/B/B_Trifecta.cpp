#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, m=500, m_num=0;
    cin >> N;
    vector<int> time(N);

    for (int i = 0; i < N; i++)
    {
        cin >> time.at(i);
        if (time.at(i) < m)
        {
            m = time.at(i);
            m_num = i;
        }
        
    }
    cout << m_num+1 << " ";

    int n=500, n_num=0;
    for (int i = 0; i < N; i++)
    {
        if(i == m_num){
            continue;
        }
        else if(time.at(i) < n){
            n = time.at(i);
            n_num = i;
        }
    }
    cout << n_num+1 << " ";
    
    int l=500, l_num=0;
    for (int  i = 0; i < N; i++)
    {
        if(i == m_num || i == n_num){
            continue;
        }
        else if(time.at(i) < l){
        l = time.at(i);
        l_num = i;
        }
    }
    cout << l_num+1 << endl;
    
}