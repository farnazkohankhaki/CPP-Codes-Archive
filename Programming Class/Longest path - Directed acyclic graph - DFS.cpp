#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1000 + 100;

bool mark[maxN];
int n, e, d[maxN], par[maxN];
vector <int> adj[maxN];

void dfs (int v)
{
	mark[v] = true;
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (!mark[u])
			dfs (u);
	}
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (d[v] < d[u] + 1)
		{
			d[v] = d[u] + 1;
			par[v] = u;
		}
	}
}
void dfsAll ()
{
	for (int i = 0; i < n; i++)
		if(!mark[i])
			dfs (i);
}

void output ()
{
	int maxi = 0;
	for (int i = 1; i < n; i++)
		if (d[maxi] < d[i])
			maxi = i;
	cout << d[maxi] << endl;
	while (maxi != -1)
	{
		cout << maxi + 1 << " ";
		maxi = par[maxi];
	}
}

int main ()
{
	cin >> n >> e;
	for (int i = 0, v, u; i < e; i++)
	{
		cin >> v >> u;
		u--;
		v--;
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		par[i] = -1;
	dfsAll();
	output();
	return 0;
}