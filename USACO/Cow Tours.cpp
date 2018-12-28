/*
 ID: fkohan1
 PROG: cowtour
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

ifstream fin ("cowtour.in");
ofstream fout ("cowtour.out");

const int MAXN = 150 + 15;
const double INF = 500000.0;

struct makan
{
	double x, y;
} m[MAXN];

int n, cmpN, comp[MAXN];
string s[MAXN];
double ans = INF, d[MAXN][MAXN], md[MAXN], dia[MAXN];
bool mark[MAXN];


void input ()
{
	fin >> n;
	for (int i = 0; i < n; i++)
		fin >> m[i].x >> m[i].y;
	for (int i = 0; i < n; i++)
		fin >> s[i];
}

void dfs (int u)
{
	mark[u] = true;
	comp[u] = cmpN;
	for (int i = 0; i < n; i++)
		if (s[u][i] == '1' && !mark[i])
			dfs (i);
}

void findComp ()
{
	for (int i = 0; i < n; i++)
		if (!mark[i])
		{
			dfs (i);
			cmpN++;
		}
}

double dis (int u, int v)
{
	int x1 = m[u].x, x2 = m[v].x, y1 = m[u].y, y2 = m[v].y; 
	double r =  sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return r;
}

void init ()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (s[i][j] == '1')
				d[i][j] = dis (i, j);
			else
				d[i][j] = INF;
}
			
void floWar ()
{
	init();
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
}

void findMaxDis ()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (d[i][j] > md[i] && i != j && comp[i] == comp[j])
				md[i] = d[i][j];
}

void findCompDia ()
{
	for (int k = 0; k < cmpN; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (comp[i] == comp[j] && i != j)
					dia[k] = max (dia[k], d[i][j]);
}

void findNewDia ()
{
	findMaxDis ();
	findCompDia ();
	double x;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (comp[i] != comp[j])
			{
				x = max (dis (i, j) + md[i] + md[j], max (dia[comp[i]], dia[comp[j]]));
				ans = min (ans, x);
			}
}			
		
int main ()
{
	input ();
	findComp ();	
	floWar ();
	findNewDia();
	fout << setprecision(6) << fixed << ans << endl;
	return 0;
}