#include <bits/stdc++.h>
using namespace std;

int main() {
    double ans=0;
    vector<int64_t> prob={1, 0, 0, 0, 0};

    for (int i = 0; i < 30; i++)
    {
        int64_t a, b, c, d;
        a = prob.at(1);
        b = prob.at(2);
        c = prob.at(3);
        d = prob.at(4);

        prob.at(1) = a * 2 + 4;
        prob.at(2) = a * 3 + b * 3;
        prob.at(3) = c * 4 + b * 2;
        prob.at(4) = c;

        // cout << prob.at(4) << endl;
        ans += prob.at(4)*100*(i+2) / pow(5, (i+1));
        cout << ans << endl;
        
    }

}