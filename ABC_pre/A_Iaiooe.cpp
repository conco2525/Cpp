#include <iostream>
using namespace std;

int main()
{
    char x;
    cin >> x;

    if ((x != 'a') && (x != 'e') && (x != 'i') && (x != 'u') && (x != 'o'))
    {
        cout << "consonant";
    }

    else
    {
        cout << "vowel";
    }
}