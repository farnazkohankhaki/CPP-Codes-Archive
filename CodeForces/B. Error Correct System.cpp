#include <iostream>
#include <vector>

using namespace std;

const int NUMOFALPH = 26;

int n;
string s, t;
vector <int> d11[NUMOFALPH], d12[NUMOFALPH], d2[NUMOFALPH][NUMOFALPH];

void output()
{
    int dif = 0;
    for (int i = 0; i < n; i++)
        if (s[i] != t[i])
        {
            d2[s[i] - 'a'][t[i] - 'a'].push_back(i);
            d11[s[i] - 'a'].push_back(i);
            d12[t[i] - 'a'].push_back(i);
            dif++;
        }
    
    for (int i = 0; i < NUMOFALPH; i++)
        for (int j = 0; j < NUMOFALPH; j++)
            if (d2[i][j].size() > 0 && d2[j][i].size() > 0)
            {
                cout << dif - 2 << endl << d2[i][j][0] + 1 << " " << d2[j][i][0] + 1 << endl;
                return;
            }
    
    for (int i = 0; i < NUMOFALPH; i++)
        if (d11[i].size() > 0 && d12[i].size() > 0)
        {
            cout << dif - 1 << endl << d11[i][0] + 1 << " " << d12[i][0] + 1 << endl;
            return;

        }
    
    cout << dif << endl << -1 << " " << -1 << endl;
    return;
}

int main()
{
    cin >> n >> s >> t;
    
    output();
    
    return 0;
}