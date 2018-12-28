#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int n, e, d[MAXN], h[MAXN];
bool mark[MAXN], r[MAXN];

vector <int> adj[MAXN];

struct edge
{
	int u, v;
};

vector <int> cutV;
vector <edge> cutE;

void input()
{
	cin >> n >> e;
	int u, v;
	for (int i = 0; i < e; i++)
	{
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int dfs(int u)
{
	int ans = 0;
	bool iscv = false;
	mark[u] = true;
	d[u] = h[u];
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (!mark[v])
		{
			ans++;
			h[v] = h[u] + 1;
			dfs(v);
			d[u] = min (d[u], d[v]);
			if (d[v] >= h[u])
			{
				iscv = true;
				edge ed;
				ed.u = u;
				ed.v = v;
				cutE.push_back(ed);
			}
		}
		else
			d[u] = min (d[u], h[v]);
	}
	if (iscv && !r[u])
		cutV.push_back(u);
	return ans;
}

void dfsAll()
{
	for (int i = 0; i < n; i++)
		if (!mark[i])
		{
			r[i] = true;
			int x = dfs(i);
			if (x > 1)
				cutV.push_back(i);
		}
}
	
void output ()
{
	cout << "cut vertices:" << endl;
	for (int i = 0; i < cutV.size(); i++)
		cout << cutV[i] + 1 << " ";
	cout << endl << "cut edges:" << endl;
	for (int i = 0; i < cutE.size(); i++)
		cout << cutE[i].u + 1 << " " << cutE[i].v + 1 << endl;
}

int main()
{
	input();
	dfsAll();
	output();
	return 0;
}