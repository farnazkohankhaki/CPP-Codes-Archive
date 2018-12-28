#include <iostream>
#include <queue>

using namespace std;

const int MAXV = 50 * 50 + 50, MAXN = 50 + 5;
const int h[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int n, m, st, f, d[MAXV];
string s[MAXN];
queue <int> q;
bool mark[MAXV];

void init()
{
	cin >> n >> m;
	getline (cin, s[0]);
	for (int i = 0; i < n; i++)
		getline (cin, s[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == 'S')
				f = i * m + j;
			if (s[i][j] == 'B')
				st = i * m + j;
		}
}

bool isHole (int x, int y)
{
	return (s[x][y] == 'C');
}
bool isWall (int x, int y)
{
	return (s[x][y] == 'W');
}

bool isCell (int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}

bool isStar (int x, int y)
{
	return (s[x][y] == 'S');
}

int getNum (int x, int y)
{
	return x * m + y;
}

int findNei (int k, int di)
{
	int x = k / m, y = k % m;
	while (true)
	{
		x += h[di][0];
		y += h[di][1];
		if (!isCell (x, y) || isWall (x, y))
			return getNum (x-h[di][0], y-h[di][1]);
		if (isHole (x, y))
			return k;
		if (isStar (x, y))
			return getNum (x, y);
	}
}

void update(int v) 
{
	for (int i = 0; i < 4; i++)
	{
		int u = findNei (v, i);
		if (!mark[u])
		{
			q.push(u);
			mark[u] = true;
			d[u] = d[v] + 1;
		}
	}
}

void bfs ()
{
	q.push(st);
	mark[st] = true;
	while (!q.empty())
	{
		update(q.front());
		q.pop();
	}
}
	
int main()
{
	init();
	bfs();
	if (mark[f])
		cout << d[f] << endl;
	else
		cout << "!" << endl;
	return 0;
}