#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> dif(N);

    for (int i = 0; i < N; i++) // N times roupe
    {
        int x = 0;
        cin >> x;
        dif.at(i) = x - (i + 1); // save the differencial as array (named "dif")
    }
    
    // get the GCD of dif
    int g = dif.at(0); //**abslute value?? check it**/
    for (int i = 1; i < N; i++)
    {
        g = gcd(g, dif.at(i));
    }
cout << g << endl;
}
