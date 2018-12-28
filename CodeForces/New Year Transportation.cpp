#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000;

bool mark[MAXN];
int n, t;
vector <int> adj[MAXN];

void dfs(int x)
{
    mark[x] = true;
    for (int i = 0; i < adj[x].size(); i++)
    {
        int y = adj[x][i];
        if (!mark[y])
            dfs(y);
    }
    return;
}

int main()
{
    cin >> n >> t;
    for (int i = 0; i < n - 1; i++)
    {
        int tmp;
        cin >> tmp;
        adj[i].push_back(i + tmp);
    }
    
    dfs(0);
    
    if (mark[t - 1])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}