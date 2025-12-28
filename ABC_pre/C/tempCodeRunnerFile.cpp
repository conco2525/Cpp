#include <bits/stdc++.h>
using namespace std;

int check_dreamer(string x){

    int y =x.size();
    if (y < 7)
    {
        return 0;
    }
    
    else if (x.substr(y-7, 7) == "dreamer")
    {
        return 1;
    }
    else{
        return 0;
    }
}

int check_dream(string x){

    int y =x.size();
    if (y < 5)
    {
        return 0;
    }
    
    else if (x.substr(y-5, 5) == "dream")
    {
        return 1;
    }
    else{
        return 0;
    }
}


int check_eraser(string x){

    int y =x.size();
    if (y < 6)
    {
        return 0;
    }
    
    else if (x.substr(y-6, 6) == "eraser")
    {
        return 1;
    }
    else{
        return 0;
    }
}

int check_erase(string x){

    int y =x.size();
    if (y < 5)
    {
        return 0;
    }
    
    else if (x.substr(y-5, 5) == "erase")
    {
        return 1;
    }
    else{
        return 0;
    }
}


int main() {
    string S;
    cin >> S;

    
while (true){

    if (S.size() == 0)
    {
        cout << "Yes" << endl;
        break;
    } 
    

    else if (check_dreamer(S)){
        S.erase(S.size() - 7);
        continue;
    }

    else if (check_eraser(S)){
        S.erase(S.size() - 6);
        continue;
    }
    
    else if (check_erase(S)){
        S.erase(S.size() - 5);
        continue;
    }
    
    else if (check_dream(S)){
        S.erase(S.size() - 5);
        continue;
    }


        cout << "No" << endl;
        break;

}

}