#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s;
vector <int> e;

void findE()
{
    for (int i = 0; i < s.size(); i++)
        if ((s[i] - '0') % 2 == 0)
            e.push_back(i);
    return;
}

void output()
{
    if (e.size() == 0)
    {
        cout << -1 << endl;
        return;
    }
    
    int n = s.size();
    for (int i = 0; i < e.size(); i++)
        if (s[e[i]] < s[n - 1] || i == e.size() - 1)
        {
            swap(s[e[i]], s[n - 1]);
            cout << s << endl;
            return;
        }
    
    return;
}

int main()
{
    cin >> s;
    
    findE();
    
    output();
    
    return 0;
}