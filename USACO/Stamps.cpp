/*
 ID: fkohank1
 PROG: stamps
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("stamps.in");
ofstream fout ("stamps.out");

const int MAXN = 50 + 5, MAXK = 10000 * 200 + 200, INF = 202;

int n, k, m, a[MAXN], d[MAXK], f;

void update (int x)
{
	for (int i = 0; i < n; i++)
		if (x - a[i] >= 0)
			d[x] = min (d[x], d[x - a[i]] + 1);
}

void build ()
{
	for (int i = 1; i <= f * k; i++)
		d[i] = INF;
	for (int i = 1; i <= f * k; i++)
		update (i);
}

void output ()
{
	for (int i = 0; i <= f * k; i++)
	{
		m = i;
		if (d[i] > k)
		{
			m--;
			break;
		}
	}
	fout << m << endl;
}

int main ()
{
	fin >> k >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> a[i];
		f = max (f, a[i]);
	}
	build();
	output();
	return 0;
}