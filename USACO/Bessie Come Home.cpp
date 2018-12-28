/*
 ID: fkohank1
 PROG: comehome
 LANG: C++
 */

#include <iostream> 
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin ("comehome.in");
ofstream fout ("comehome.out");

const int MAXN = 200 + 20;

int s = 25, n = 70, e, cnt, d[MAXN], w[MAXN][MAXN];
vector <int> adj[MAXN];
bool mark[MAXN];

void init ()
{
	for (int i = 0; i <= n; i++)
		d[i] = -1;
	d[s] = 0;
}

void input ()
{
	fin >> e;
	int we, u, v;
	char x, y;
	for (int i = 0; i < e; i++)
	{
		fin >> x >> y >> we;
		int u = (int) x - 'A', v = (int) y - 'A';
		if (adj[u].size() == 0)
			cnt++;
		if (adj[v].size() == 0)
			cnt++;
		if (w[u][v] == 0)
		{
			w[u][v] = we;
			w[v][u] = we;
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
		else
		{
			w[u][v] = min (w[u][v], we);
			w[v][u] = min (w[v][u], we);
		}
	}
}

int findMin ()
{
	int r = n;
	for (int i = 0; i < n; i++)
		if (!mark[i] && (d[r] > d[i] || d[r] == -1) && d[i] != -1)
			r = i;
	return r;
}

void update (int x)
{
	for (int i = 0; i < adj[x].size(); i++)
	{
		int u = adj[x][i];
		if (d[u] == -1 || d[u] > d[x] + w[x][u])
			d[u] = d[x] + w[u][x];

	}
}

void djk ()
{
	mark[s] = true;
	update (s);
	for (int i = 0; i < cnt - 1; i++)
	{
		int u = findMin();
		mark[u] = true;
		update (u);
	}
}

void output ()
{
	int r = n;
	for (int i = 0; i < s; i++)
	{
		if (d[i] != -1 && i != s)
		{
			if (d[r] == -1)
				r = i;
			else if (d[r] > d[i])
				r = i;
		}
	}
	char ans = r + 'A';
	fout << ans << " " << d[r] << endl;
}
		
int main ()
{
	init();
	input();
	djk();
	output();
	return 0;
}