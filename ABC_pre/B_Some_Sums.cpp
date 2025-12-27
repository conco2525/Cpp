#include <bits/stdc++.h>
using namespace std;

int Sum(int x){
    int sum = (x % 10);
    while (x > 9)
    {
        x = x / 10;
        sum += (x % 10);
    }
    return sum;
    
}

int main() {
    int N, A, B, ans=0;
    cin >> N >> A >> B;

for (int i = 1; i <= N; i++)
{
    if ((Sum(i) >= A) && (Sum(i) <= B))
    {
        ans += i;
    }
    
}
cout << ans << endl;

}