#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 400 + 40;

int n, m, s, t, h[MAXN], adj[MAXN][MAXN];
vector <int> l[MAXN];
queue <int> q;
bool mark[MAXN], marke[MAXN * MAXN];

void input()
{
	cin >> n >> m >> s >> t;
	s--;
	t--;
	int x, y;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		adj[x][y] = adj[y][x] = i;
	}
}

void bfs()
{
	mark[s] = true;
	q.push(s);
	bool f = true;
	while (!q.empty())
	{
		int u = q.front();
		if (u == t)
			f = false;
		for (int i = 0; i < n; i++)
		{
			int num = adj[u][i];
			if (num > 0)
			{
				if (!mark[i])
				{
					mark[i] = true;
					q.push(i);
					h[i] = h[u] + 1;
				}
				if (!marke[num])
				{
					marke[num] = true;
					if (f)
						l[h[u]].push_back(num);
					else
						l[0].push_back(num);
				}
			}
		}
		q.pop();
	}
}

void output()
{
	if (h[t] == 0)
	{
		cout << m << endl;
		for (int i = 1; i <= m; i++)
			cout << 1 << " " << i << endl;
		return;
	}
	cout << h[t] << endl;
	for (int i = 0; i < h[t]; i++)
	{
		cout << l[i].size();
		for (int j = 0; j < l[i].size(); j++)
			cout << " " << l[i][j];
		cout << endl;
	}
}

int main()
{
	input();
	bfs();
	output();
	return 0;
}