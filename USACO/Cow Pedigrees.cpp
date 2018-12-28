/*
 ID: fkohan1
 PROG: nocows
 LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("nocows.in");
ofstream fout ("nocows.out");

const int MAXN = 200 + 8, MAXK = 100 + 8, delta = 9901;

int n, k, d[MAXN][MAXK], p[MAXN][MAXK];

void dyna()
{
	d[1][1] = 1;
	for (int i = 1; i <= k; i++)
		p[1][i] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= k; j++)
		{
			int x = 0, y = 0;
			for (int l = 1; l < i; l++)
			{
				x += d[l][j - 1] * p[i - 1 - l][j - 1];
				y += d[l][j - 1] * d[i - 1 - l][j - 1];
			}

			d[i][j] = x * 2 - y;
			p[i][j] = p[i][j - 1] + d[i][j];
			d[i][j] %= delta;
			p[i][j] %= delta;
		}
}

int main()
{
	fin >> n >> k;
	dyna();
	fout << d[n][k] << endl;
	return 0;
}

