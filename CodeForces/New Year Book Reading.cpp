#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000 + 100;

bool mark[MAXN];
int n, m, w[MAXN], b[MAXN], ans;
vector <int> s;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    for (int i = 0; i < m; i++)
        if(!mark[b[i]])
        {
            mark[b[i]] = true;
            s.push_back(b[i]);
        }
    
    for (int i = 0; i < m; i++)
    {
        int ind = 0;
        for (int j = 0; j < s.size(); j++)
            if(s[j] == b[i])
            {
                ind = j;
                break;
            }
        for (int j = 0; j < ind; j++)
            ans += w[s[j]];
        for (int j = ind; j > 0; j--)
            s[j] = s[j - 1];
        s[0] = b[i];
    }
    
    cout << ans << endl;
    
    return 0;
}