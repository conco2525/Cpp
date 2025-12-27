#include <iostream>
using namespace std;

int main()
{
    int x, y, a, b;
    cin >> x >> y;

    switch(x){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        a = 1;
    }

     switch(y){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        b = 1;
    }

    switch(x){
        case 4:
        case 6:
        case 9:
        case 11:
        a = 2;
    }

    switch(y){
        case 4:
        case 6:
        case 9:
        case 11:
        b = 2;
    }
    
    if (x == 2)
    {
        a = 0;
    }
    if (y == 2)
    {
        b = 0;
    }


    if (a == b)
    {
        cout << "Yes" << endl;

    }
    else if (a != b){
        cout << "No" << endl;
    }
    
    
}
