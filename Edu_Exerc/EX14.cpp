#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int M, m;

  M = max(max(A, B), C);
  m = min(min(A, B), C);

  cout << (M - m) << endl;
}
