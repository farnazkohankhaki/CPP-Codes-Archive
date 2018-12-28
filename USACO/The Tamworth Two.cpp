/*
 ID: fkohank1
 PROG: ttwo
 LANG: C++
 */

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("ttwo.in");
ofstream fout ("ttwo.out");

const int MAXN = 10 + 1, h[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n = 10, xf, yf, xc, yc, t, jf, jc;
bool mark[MAXN][MAXN], m[MAXN * MAXN * MAXN][MAXN * MAXN * MAXN];
string s[MAXN];

void input ()
{
	for (int i = 0; i < n; i++)
		fin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (s[i][j] == 'F')
			{
				xf = i;
				yf = j;
			}
			if (s[i][j] == 'C')
			{
				xc = i;
				yc = j;
			}
		}
}

bool isCell (int x, int y, int j)
{
	x += h[j][0];
	y += h[j][1];
	if (x < 0 || x >= n || y < 0 || y >= n || s[x][y] == '*')
		return false;
	return true;
}

bool isReach (int x, int y)
{
	mark[x][y] = true;
	if (x == xc && y == yc)
		return true;
	int hx, hy;
	bool r = false;
	for (int i = 0; i < 4; i++)
	{
		hx = x + h[i][0];
		hy = y + h[i][1];
		if (isCell (x, y, i) && !mark[hx][hy])
			r = (r || isReach (hx, hy));
	}
	return r;
}

int findAns ()
{
	if (!isReach(xf, yf))
		return 0;
	while (xf != xc || yf != yc)
	{
		if(m[xf * n * n + yf * n + jf][xc * n * n + yc * n + jc])
			return 0;
		m[xf * n * n + yf * n + jf][xc * n * n + yc * n + jc] = true;
		t++;
		if (!isCell (xc, yc, jc))
			jc = (jc + 1) % 4;
		else
		{
			xc += h[jc][0];
			yc += h[jc][1];
		}
		if (!isCell (xf, yf, jf))
			jf = (jf + 1) % 4;
		else
		{
			xf += h[jf][0];
			yf += h[jf][1];
		}
	}
	return t;
}

int main ()
{
	input ();
	fout << findAns () << endl;
	return 0;
}