/*
 ID: fkohan1
 PROG: agrinet
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin ("agrinet.in");
ofstream fout ("agrinet.out");

const int MAXN = 100 + 10;

int n, a[MAXN][MAXN], d[MAXN], par[MAXN], cost;
bool mark[MAXN];

void input ()
{
	fin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fin >> a[i][j];
}

void init ()
{
	for (int i = 1; i <	n; i++)
		d[i] = -1;
}

void update (int u)
{
	for (int i = 0; i < n; i++)
		if (d[i] == -1 || a[u][i] < d[i])
		{
			par[i] = u;
			d[i] = a[u][i];
		}
}

int findMin ()
{
	int r = n;
	for (int i = 0; i < n; i++)
		if (!mark[i] && d[i] != -1 && (r == n || d[i] < d[r]))
			r = i;
	return r;
}

void prim ()
{
	init();
	mark[0] = true;
	update (0);
	for (int i = 0; i < n - 1; i++)
	{
		int u = findMin ();
		mark[u] = true;
		cost += a[par[u]][u];
		update (u);
	}
}


int main ()
{
	input ();
	prim ();
	fout << cost << endl;
	return 0;
}