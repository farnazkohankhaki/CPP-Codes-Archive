#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 16 * 1000 + 1000;

int n, w[MAXN], maxi;
vector <int> adj[MAXN];
bool mark[MAXN];

void input ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	int u, v;
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	maxi = w[0];
}

int dfs (int x)
{
	mark[x] = true;
	int r = w[x];
	for (int i = 0; i < adj[x].size(); i++)
	{
		int u = adj[x][i], t;
		if (!mark[u])
		{
			t = dfs (u);
			if (t > 0)
				r += t;
		}
	}
	maxi = max (maxi, r);
	return r;
}

int main ()
{
	input ();
	int x = dfs (0);
	cout << maxi << endl;	
	return 0;
}