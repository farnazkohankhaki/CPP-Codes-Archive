#include <iostream>

using namespace std;

const int MAX_N = 100 * 1000 + 10 * 1000;

int m, d[MAX_N];
string s;

int main()
{
    cin >> s;
    
    for (int i = 1; i < s.size(); i++)
    {
        d[i] = d[i - 1];
        if (s[i] == s[i - 1])
            d[i]++;
    }
    
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << d[r - 1] - d[l - 1] << endl;
    }
    
    return 0;
}