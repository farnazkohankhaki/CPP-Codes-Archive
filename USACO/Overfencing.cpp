/*
 ID: fkohank1
 PROG: maze1
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

ifstream fin ("maze1.in");
ofstream fout ("maze1.out");

const int MAXN = 200 + 10, hi[4][2] = {{2, 0}, {-2, 0}, {0, 2}, {0, -2}};

int n, w, h, dia[MAXN][MAXN], dis[MAXN][MAXN];
bool mark[MAXN][MAXN];
string s[MAXN];

struct v
{
	int x, y;
} e[2];

void input ()
{
	fin >> w >> h;
	getline (fin, s[0]);
	for (int i = 0; i <= 2 * h; i++)
		getline (fin, s[i]);
	int tmp = 0;
	for (int i = 0; i <= 2 * h; i++)
	{
		if (s[i][0] == ' ')
		{
			e[tmp].x = i;
			e[tmp].y = 1;
			tmp++;
		}
		if (s[i][2 * w] == ' ')
		{
			e[tmp].x = i;
			e[tmp].y = 2 * w - 1;
			tmp++;
		}
	}
	for (int i = 0; i <= 2 * w; i++)
	{
		if (s[0][i] == ' ')
		{
			e[tmp].x = 1;
			e[tmp].y = i;
			tmp++;
		}
		if (s[2 * h][i] == ' ')
		{
			e[tmp].x = 2 * h - 1;
			e[tmp].y = i;
			tmp++;
		}
	}
}
void init ()
{
	for (int i = 1; i < 2 * h; i += 2)
		for (int j = 1; j < 2 * w; j += 2)
			mark[i][j] = false;
}

bool isReach (int x, int y, int j)
{
	x += hi[j][0] / 2;
	y += hi[j][1] / 2;
	return (s[x][y] == ' ');
}

void bfs (int x, int y, int b)
{
	init();
	queue <v> q;
	mark[x][y] = true;
	dis[x][y] = 0;
	v tmp;
	tmp.x = x;
	tmp.y = y;
	q.push(tmp);
	while (!q.empty())
	{
		v u = q.front();
		for (int i = 0; i < 4; i++)
		{
			int nx = u.x + hi[i][0], ny = u.y + hi[i][1];
			if (isReach (u.x, u.y, i) && !mark[nx][ny])
			{
				if (b == 0)
					dis[nx][ny] = dis[u.x][u.y] + 1;
				else
					dis[nx][ny] = min (dis[nx][ny], dis[u.x][u.y] + 1);
				mark[nx][ny] = true;
				v r;
				r.x = nx;
				r.y = ny;
				q.push(r);
			}
		}
		q.pop();
	}
}

void bfsAll ()
{
	for (int i = 0; i < 2; i++)
		bfs (e[i].x, e[i].y, i);	
}

void output ()
{
	int ans = 0;
	for (int i = 1; i < 2 * h; i++)
		for (int j = 1; j < 2 * w; j++)
			ans = max (ans, dis[i][j]);
	fout << ans + 1 << endl;
}

int main ()
{
	input ();
	bfsAll ();
	output ();
	return 0;
}