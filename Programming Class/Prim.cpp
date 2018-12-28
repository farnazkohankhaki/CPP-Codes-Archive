#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 + 10;

int n, e, s, mst, d[MAXN], par[MAXN], w[MAXN][MAXN];
vector <int> adj[MAXN];
bool mark[MAXN];

void input ()
{
	int u, v, we;
	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		cin >> u >> v >> we;
		u--;
		v--;
		adj[v].push_back(u);
		adj[u].push_back(v);
		w[u][v] = we;
		w[v][u] = we;
	}
}

void init ()
{
	for (int i = 1; i <= n; i++)
		d[i] = -1;
}

void update (int u)
{
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (d[v] == -1 || d[v] > w[u][v])
		{
			d[v] = w[u][v];
			par[v] = u;
		}
	}
}

int findMin ()
{
	int r = n;
	for (int i = 0; i < n; i++)
		if (!mark[i] && d[i] != -1 && (d[r] > d[i] || r == n))
			r = i;
	return r;
}
		
void prim ()
{
	mark[s] = true;
	update (s);
	for (int i = 0; i < n - 1; i++)
	{
		int u = findMin();
		mark[u] = true;
		mst += w[u][par[u]];
		update (u);
	}
}

void output ()
{
	for (int i = 0; i < n; i++)
		if (!mark[i])
		{
			cout << "NOT CONNECTED" << endl;
			return;
		}
	cout << mst << endl;
	for (int i = 0; i < n; i++)
		if (i != s)
			cout << i + 1 << " , " << par[i] + 1 << endl;
}

int main ()
{
	input ();
	init();
	prim ();
	output ();
	return 0;
}	