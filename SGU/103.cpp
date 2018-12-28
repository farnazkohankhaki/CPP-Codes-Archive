#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 300 + 30;

bool mark[MAXN], mark2[MAXN];
int s, f, n, m, w[MAXN][MAXN], c[MAXN], r[MAXN], t[MAXN][2], par[MAXN], d[MAXN];
vector <int> adj[MAXN], path;

void inpit()
{
	cin >> s >> f;
	s--;
	f--;
	cin >> n >> m;
	char tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp == 'P')
			c[i] = 1;
		cin >> r[i] >> t[i][0] >> t[i][1];
	}
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		u--;
		v--;
		cin >> w[u][v];
		w[v][u] = w[u][v];
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
}

int findC (int u, int time)
{
	if (r[u] > time)
		return c[u];
	time -= r[u];
	int x = t[u][0] + t[u][1];
	int re = time % x;
	int f = (c[u] + 1) % 2;
	if (re < t[u][f])
		return f;
	else
		return (f + 1) % 2;
}

int findT (int u, int v, int time)
{
	for (int i = time; i < time + (t[u][0] + t[u][1]) * (t[v][0] + t[v][1]); i++)
		if (findC(u, i) == findC(v, i))
			return i - time;
	return -1;
}

void update (int u)
{
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (mark[v])
			continue;
		int ti = findT(u, v, d[u]);
		if (ti != -1)
		{
			if (!mark2[v])
			{
				d[v] = d[u] + ti + w[u][v];
				mark2[v] = true;
				par[v] = u;
			}				
			else if (d[v] > d[u] + ti + w[u][v])
			{
				d[v] = d[u] + ti + w[u][v];
				par[v] = u;
			}
		}
	}
}

int findMin()
{
	int r = -1;
	for (int i = 0; i < n; i++)
		if (!mark[i] && mark2[i])
		{
			r = i;
			break;
		}
	if (r == -1)
		return r;
	for (int i = r + 1; i < n; i++)
		if (!mark[i] && mark2[i] && d[i] < d[r])
			r = i;
	return r;
}

void djk()
{
	mark[s] = true;
	update(s);
	for (int i = 1; i < n; i++)
	{
		int u = findMin();
		if (u == -1)
			break;
		mark[u] = true;
		update(u);
	}
}

void output()
{
	if (!mark[f])
	{
		cout << 0 << endl;
		return;
	}
	cout << d[f] << endl;
	path.push_back(f + 1);
	while (f != s)
	{
		path.push_back(par[f] + 1);
		f = par[f];
	}
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << " ";
	cout << endl;
}

int main()
{
	inpit();
	djk();
	output();
	return 0;
}