/*
 ID: fkohan1
 PROG: concom
 LANG: C++
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin ("concom.in");
ofstream fout ("concom.out");

const int MAXN = 100 + 10;

int n = 100, a[MAXN][MAXN], p[MAXN];
bool mark[MAXN];

queue <int> q;
vector <int> ans[MAXN];

void input ()
{
	int t, x, y, v;
	fin >> t;
	for (int i = 0; i < t; i++)
	{
		fin >> x >> y >> v;
		x--;
		y--;
		a[x][y] = v;
	}
}
	
void init()
{
	for (int i = 0; i < n; i++)
	{
		mark[i] = false;
		p[i] = 0;
	}
}

void bfs (int u)
{			
	init();
	mark[u] = true;
	q.push(u);
	while (!q.empty())
	{
		int v = q.front();
		for (int i = 0; i < n; i++)
			if (!mark[i])
			{
				p[i] += a[v][i];
				if (p[i] >= 50)
				{
					mark[i] = true;
					q.push(i);
					if (u != i)
						ans[u].push_back(i);
				}
			}
		q.pop();
	}
}

void output ()
{
	for (int i = 0; i < n; i++)
	{
		sort (ans[i].begin(), ans[i].end());
		for (int j = 0; j < ans[i].size(); j++)
			fout << i + 1 << " " << ans[i][j] + 1 << endl;
	}
}

int main ()
{
	input ();
	for (int i = 0; i < n; i++)
		bfs (i);
	output ();
	return 0;
}