#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, N, Q;
    cin >> H >> W >> N >> Q;
    vector<int> row(N);
    vector<int> col(N);

    for(int i=0; i<N; i++){
        cin >> row.at(i) >> col.at(i);
    }
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());

    for(int i = 0; i < Q; i++){
    int t, L, R;
    cin >> t >> L >> R;
    
    if(t == 1){
        int ans = upper_bound(row.begin(), row.end(), R)
        - lower_bound(row.begin(), row.end(), L);
        cout << ans << endl;
    }
    if(t == 2){
        int ans = upper_bound(col.begin(), col.end(), R)
        - lower_bound(col.begin(), col.end(), L);
        cout << ans << endl;
    }
}

}