/*
 ID: fkohank1
 PROG: money
 LANG: C++
 */

#include <iostream> 
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin ("money.in");
ofstream fout ("money.out");

const int maxN = 25 + 10, maxM = 10000 + 100;

long long n, m, d[maxN][maxM], v[maxN];

void dyna()
{
	d[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k * v[i] <= j; k++)
				d[i][j] += d[i - 1][j - k * v[i]];
}

int main ()
{
	fin >> n >> m;
	for (int i = 1; i <= n; i++)
		fin >> v[i];
	dyna();
	fout << d[n][m] << endl;
	return 0;
}