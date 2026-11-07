#include <bits/stdc++.h>
using namespace std;



int nokori(char a, char b, char c, char d, char e) {
    int n=5;
    if(a == 'o') n--;  
    if(b == 'o') n--; 
    if(c == 'o') n--; 
    if(d == 'o') n--; 
    if(e == 'o') n--; 
    return n;
}

int stri(string S){
    char a, b, c, d, e;
    a = S.at(0);
    b = S.at(1);
    c = S.at(2);
    d = S.at(3);
    e = S.at(4);
    return nokori(a, b, c, d, e);
}

int tate(string A, string B, string C, string D, string E, int i){
    char a, b, c, d, e;
    a = A.at(i);
    b = B.at(i);
    c = C.at(i);
    d = D.at(i);
    e = E.at(i);
    return nokori(a, b, c, d, e);
}

int nnm1(string A, string B, string C, string D, string E){
    char a, b, c, d, e;
    a = A.at(0);
    b = B.at(1);
    c = C.at(2);
    d = D.at(3);
    e = E.at(4);
    return nokori(a, b, c, d, e);
}

int nnm2(string A, string B, string C, string D, string E){
    char a, b, c, d, e;
    a = A.at(4);
    b = B.at(3);
    c = C.at(2);
    d = D.at(1);
    e = E.at(0);
    return nokori(a, b, c, d, e);
}


int main() {
    string A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    int ans=0;

    ans = min(stri(A), stri(B));
    ans = min(ans, stri(C));
    ans = min(ans, stri(D));
    ans = min(ans, stri(E));
    ans = min(ans, tate(A, B, C, D, E, 0));
    ans = min(ans, tate(A, B, C, D, E, 1));
    ans = min(ans, tate(A, B, C, D, E, 2));
    ans = min(ans, tate(A, B, C, D, E, 3));
    ans = min(ans, tate(A, B, C, D, E, 4));
    ans = min(ans, nnm1(A, B, C, D, E));
    ans = min(ans, nnm2(A, B, C, D, E));

    cout << ans << endl;
}