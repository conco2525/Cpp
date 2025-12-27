#include <bits/stdc++.h>
using namespace std;

int main() {
   int N;
   string S;
   char x;

   cin >> S;
   N = S.size();
   x = S.at(N - 1);

   if (x == 'T')
   {
    cout << "YES" << endl;
   }
   else {
    cout << "NO" << endl;
   }
   

}