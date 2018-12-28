#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 300 + 30;

bool mark[MAXN];
int n, a[MAXN], ncmp;
vector <int> comp[MAXN], pcmp[MAXN];
string adj[MAXN];

void dfs(int u)
{
    mark[u] = true;
    comp[ncmp].push_back(u);
    for (int i = 0; i < n; i++)
        if (adj[u][i] == '1' && !mark[i])
            dfs(i);
    return;
}

void dfsAll()
{
    for (int i = 0; i < n; i++)
        if (!mark[i])
        {
            dfs(i);
            ncmp++;
        }
    return;
}

void findCmp()
{
    for (int i = 0; i < ncmp; i++)
        for (int j = 0; j < comp[i].size(); j++)
            pcmp[i].push_back(a[comp[i][j]]);
    return;
}

void findNewA()
{
    for (int i = 0; i < ncmp; i++)
        sort(comp[i].begin(), comp[i].end());
    
    for (int i = 0; i < ncmp; i++)
        sort(pcmp[i].begin(), pcmp[i].end());

    
    for (int i = 0; i < ncmp; i++)
        for (int j = 0; j < comp[i].size(); j++)
        {
            int p = comp[i][j];
            a[p] = pcmp[i][j];
        }
    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> adj[i];
    
    dfsAll();

    findCmp();
    
    findNewA();
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    
    return 0;
}