#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200 + 20;

int n, m;
vector <int> adj[MAXN];
int col[MAXN];
bool mark[MAXN];
vector <int> d[2];

void input ()
{
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		u--;
		v--;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
}

bool dfs (int u, int cl)
{
	bool r = true;
	mark[u] = true;
	col[u] = cl;
	d[cl].push_back(u);
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (!mark[v])
			r &= dfs (v, (cl + 1) % 2);
		else if (col[v] == col[u])
			return false;
	}
	return r;
}

bool dfsAll ()
{
	for (int i = 0; i < n; i++)
		if (!mark[i])
			if (!dfs(i, 0))
				return false;
	return true;
}

void output (bool ans)
{
	if (!ans)
	{
		cout << "no" << endl;
		return;
	}
	cout << "yes" << endl;
	cout << d[0].size() << endl;
	for (int i = 0; i < d[0].size(); i++)
		cout << d[0][i] + 1 << " ";
	cout << endl;
}

int main ()
{
	input ();
	bool ans = dfsAll ();
	output (ans);
	return 0;
}