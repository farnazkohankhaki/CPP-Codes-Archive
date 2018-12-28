/*
 ID: fkohank1
 PROG: castle
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("castle.in");
ofstream fout ("castle.out");

const int maxN = 50 + 8, maxC = 2500 + 8;

int a[maxN][maxN], mark[maxN][maxN] = {{0}}, com = 0, c[maxN][maxN] = {{0}}, sc[maxC] = {0};


void DFS (int i, int j)
{
	mark[i][j] = 1;
	c[i][j] = com;
	if (a[i][j] % 2 == 0 && !mark[i][j - 1])
		DFS(i, j - 1);
 
	if ((a[i][j] / 2) % 2 == 0 && !mark[i - 1][j])
		DFS(i - 1, j);
 
	if ((a[i][j] / 4) % 2 == 0 && !mark[i][j + 1])
		DFS(i, j + 1);
 
	if ((a[i][j] / 8) % 2 == 0 && !mark[i + 1][j])
		DFS(i + 1, j);
}

int main()
{
	int m, n, maxr = 0, mmix, xmix, ymix, dmix;
	fin >> m >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			fin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!mark[i][j])
			{
				com++;
				DFS (i, j);
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			sc[c[i][j]]++;
	for (int i = 1; i <= com; i++)
		maxr = max (maxr, sc[i]);
	fout << com << endl << maxr << endl;
	mmix = maxr;
	for (int i = 1; i <= m; i++)
		for (int j = n; j > 0; j--)
		{
			if (c[j][i] != c[j - 1][i] && mmix < (sc[c[j][i]] + sc[c[j - 1][i]]))
			{
				dmix = 1;
				xmix = j;
				ymix = i;
				mmix = sc[c[j][i]] + sc[c[j - 1][i]];
			}
			if (c[j][i] != c[j][i + 1] && mmix < (sc[c[j][i]] + sc[c[j][i + 1]]))
			{
				dmix = 2;
				xmix = j;
				ymix = i;
				mmix = sc[c[j][i]] + sc[c[j][i + 1]];
			}
		}
	fout << mmix << endl << xmix << " " << ymix << " ";
	if (dmix == 1)
		fout << "N" << endl;
	else
		fout << "E" << endl;	
	return 0;
}