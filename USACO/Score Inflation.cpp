/*
 ID: fkohank1
 PROG: inflate
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("inflate.in");
ofstream fout ("inflate.out");

const int MAXN = 10000 + 100;

int m, n, d[2][MAXN];

struct problem
{
	int t, p;
} prb[MAXN];

void build ()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int x = j - prb[i].t;
			if (x >= 0)
				d[1][j] = max (d[1][j], d[1][x] + prb[i].p);
		}
		for (int j = 1; j <= m; j++)
			d[0][j] = d[1][j];
	}
}

int main()
{
	fin >> m >> n;
	for (int i = 1; i <= n; i++)
		fin >> prb[i].p >> prb[i].t;
	build ();
	fout << d[1][m] << endl;
	return 0;
}