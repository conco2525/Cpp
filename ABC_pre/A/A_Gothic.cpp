#include <bits/stdc++.h>
using namespace std;

int main() {
vector<int> a = {1, 7};
vector<int> b = {3, 3};
vector<int> c = {5, 5};
vector<int> e = {7, 7};
vector<int> f = {9, 9};
bool ans=false;

int m, d;
cin >> m >> d;

vector<int> check(2);
check.at(0) = m;
check.at(1)= d;
if (a == check)
{
    ans = true;
}
if (b == check)
{
    ans = true;
}
if (c == check)
{
    ans = true;
}
if (e == check)
{
    ans = true;
}
if (f == check)
{
    ans = true;
}

if (ans)
{
    cout << "Yes" << endl;
}
else
{
    cout << "No" << endl;
}


}