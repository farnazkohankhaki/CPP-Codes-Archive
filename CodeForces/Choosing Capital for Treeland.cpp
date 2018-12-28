#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2 * 100 * 1000 + 1000;

int n, t, d[MAXN], dis[MAXN];
vector <int> adj[MAXN], di[MAXN];
bool mark[MAXN];

void input ()
{
	cin >> n;
	int u, v;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		di[u].push_back(-1);
		di[v].push_back(1);
	}
}

void dfs (int x)
{
	mark[x] = true;
	for (int i = 0; i < adj[x].size(); i++)
	{
		int u = adj[x][i];
		if (!mark[u])
		{
			dis[u] = dis[x] + 1;
			d[u] = d[x];
			if (di[x][i] == -1)
				d[u]++;
			else
				t++;
			dfs (u);
		}
	}
}

void output ()
{
	vector <int> ans;
	int mini = t;
	ans.push_back(0);
	for (int i = 1; i < n; i++)
	{
		int x = t - dis[i] + 2 * d[i];
		if (x < mini)
		{
			mini = x;
			ans.clear();
			ans.push_back(i);
		}
		else if (x == mini)
			ans.push_back(i);
	}
	cout << mini << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] + 1 << " ";
	cout << endl;
}

int main ()
{
	input ();
	dfs (0);
	output ();
	return 0;
}