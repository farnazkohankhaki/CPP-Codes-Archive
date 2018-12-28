#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 100 + 10;
const char MAN = 'X', STONE = 'O', FINAL = 'F', WALL = '#';
const int h[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n;
string s[MAXN];

struct Cell
{
	int x, y;
	Cell() {}
	Cell(int xx, int yy): x(xx), y(yy) {}
	int toInt()
	{
		return x*n+y;
	}
	bool move(int k)
	{
		x += h[k][0];
		y += h[k][1];
		
		if (x < 0 || x >= n || y < 0 || y >= n)
			return false;
		return (s[x][y] != WALL);
	}
	bool equal(Cell a)
	{
		return x == a.x && y == a.y;
	}
} final;

struct Status
{
	int d;
	Cell man, stone;
	int toInt()
	{
		return man.toInt()*n*n + stone.toInt();
	}
	bool move(int k) 
	{
		return (man.move(k) && (!man.equal(stone) || (man.equal(stone) && stone.move(k))));
	}
} first;

queue <Status> q;
bool mark[MAXN * MAXN * MAXN * MAXN];
int d[MAXN * MAXN * MAXN * MAXN];

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j= 0; j < n; j++)
			if (s[i][j] == MAN)
				first.man = Cell(i,j);
			else if (s[i][j] == STONE)
				first.stone = Cell(i,j);
			else if (s[i][j] == FINAL)
				final = Cell(i,j);
	}
}

int bfs()
{
	q.push(first);
	mark[first.toInt()] = true;
	while (!q.empty())
	{
		Status t = q.front();
		if (t.stone.equal(final))
			return d[t.toInt()];
		for (int i= 0; i < 4; i++)
		{
			Status p = t;
			if (p.move(i) && !mark[p.toInt()])
			{
				q.push(p);
				mark[p.toInt()] = true;
				d[p.toInt()] = d[t.toInt()] + 1;
			}
			
		}
		q.pop();
	}
	return -1;
}

int main()
{
	input();
	cout << bfs() << endl;
	return 0;
}