#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 + 10;

bool mark[MAXN], r[MAXN][2];
int n, st[MAXN], ans[MAXN][MAXN], adj[MAXN][MAXN], e[MAXN][MAXN];
vector <int> comp, a[MAXN];

void input()
{
	cin >> n;
	int u;
	for (int i = 0; i < n; i++)
	{
		cin >> u;
		while (u != 0)
		{
			u--;
			a[i].push_back(u);
			adj[i][u]++;
			e[i][u]++;
			cin >> u;
		}
	}
}

void dfs (int u)
{
	mark[u] = true;
	comp.push_back(u);
	for (int i = 0; i < a[u].size(); i++)
	{
		int v = a[u][i];
		if (!mark[v])
			dfs(v);
	}
}

int findS()
{
	int u = comp[0];
	for  (int i = 1; i < comp.size(); i++)
		if (a[u].size() == 2)
			u = comp[i];
	return u;
}

void makeR()
{
	vector <int> o;
	o.clear();
	for (int i = 0; i < comp.size(); i++)
		if (a[comp[i]].size() % 2)
			o.push_back(comp[i]);
	for (int i = 0; i < o.size(); i += 2)
	{
		int u = o[i], v = o[i + 1];
		adj[u][v]++;
		adj[v][u]++;
	}
}

int findC (int u)
{
	for (int i = 0; i < 2; i++)
		if (!r[u][i])
			return i;
	return 0;
}

void dfsE (int u)
{
	for ( ; st[u] < n; st[u]++)
		if (adj[u][st[u]])
		{
			int v = st[u];
			int c = findC(u);
			adj[u][v]--;
			adj[v][u]--;
			if (e[u][v])
			{
				e[u][v]--;
				e[v][u]--;
				ans[u][v] = ans[v][u] = c;
				r[u][c] = r[v][c] = true;
			}
			dfsE(v);
		}
}

bool dfsAll()
{
	for (int i = 0; i < n; i++)
		if (!mark[i])
		{
			comp.clear();
			dfs(i);
			int u = findS();
			int d = a[u].size();
			makeR();
			dfsE(u);
			if (d == 2 && !(r[u][0] && r[u][1]))
				return false;
		}
	return true;
}

void output (bool f)
{
	if (!f)
	{
		cout << "No solution" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a[i].size(); j++)
			cout << ans[i][a[i][j]] + 1 << " ";
		cout << 0 << endl;
	}
}

int main()
{
	input();
	bool f = dfsAll();
	output(f);
	return 0;
}