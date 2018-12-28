#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 700 + 100;

int n, m, dis[MAXN];
bool mark[MAXN];
vector <int> adj[MAXN][3];
queue <int> q;

void input()
{
	cin >> n >> m;
	int x, y, c;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> c;
		x--;
		y--;
		c--;
		adj[x][c].push_back(y);
	}
}

void init()
{
	for (int i = 0; i < 3; i++)
	{
		mark[i] = true;
		q.push(i);
	}
}

void bfs()
{
	while (!q.empty())
	{
		int x = q.front();
		int u = x / 3, c = x % 3;
		for (int i = 0; i < 3; i++)
		{
			if (i == c)
				continue;
			for (int j = 0; j < adj[u][i].size(); j++)
			{
				int v = adj[u][i][j];
				if (!mark[v * 3 + i])
				{
					mark[v * 3 + i] = true;
					q.push(v * 3 + i);
					dis[v * 3 + i] = dis[x] + 1;
				}
			}
		}
		q.pop();
	}
}

void output()
{
	vector <int> x;
	for (int i = 3 * n - 3; i < 3 * n; i++)
		if (dis[i] != 0)
			x.push_back(dis[i]);
	if (x.size() == 0)
		cout << -1 << endl;
	else 
	{
		sort (x.begin(), x.end());
		cout << x[0] << endl;
	}
}

int main()
{
	input();
	init();
	bfs();
	output();
	return 0;
}