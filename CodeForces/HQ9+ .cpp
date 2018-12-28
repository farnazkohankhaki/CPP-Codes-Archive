#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    string p;
    cin >> p;
    while (p[i] != 'H' && p[i] != 'Q' && p[i] != '9' && i < p.size())
        i++;
    if (i < p.size())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
