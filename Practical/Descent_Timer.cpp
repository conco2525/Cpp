#include <bits/stdc++.h>
using namespace std;

int main()
{

    cout << "========================================\n";
    cout << " DESCENT TIMER\n";
    cout << " Enter: Dist GS ALT x5\n";
    cout << "ALT(000ft) eg: 34000ft -> 34\n";

    while (true)
    {
        cout << "   >> ";
        
        int d=0, a=0, g=1, p=0, s, m;
        cin >> d >> g >> a >> p;

        if(!p){
        s = (d - (a - 10) * 3) * 3600 / g;
        m = (d - (a - 10) * 3) * 60 / g;
        }
        else{
        s = (d - (a - 10) * 3) * 720 / g;
        m = (d - (a - 10) * 3) * 12 / g;
        }

        cout << "  " << m << "min" << endl;
        
        
        this_thread::sleep_for(chrono::seconds(s));
        cout << "\a" << flush;
        
    }
}