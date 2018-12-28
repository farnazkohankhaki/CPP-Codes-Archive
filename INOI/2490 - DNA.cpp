#include <iostream>

using namespace std;

const int maxN = 6 + 8;

int a[maxN][maxN] = {{0}}, n, r = 0;

void f (int x, int y)
{
	if (y > n)
	{
		r++;
		return;
	}
	int nx, ny;
	if (x == n)
	{
		nx = 1;
		ny = y + 1;
	}
	else
	{
		nx = x + 1;
		ny = y;
	}
	if (a[y][x] == 0)
		for (int i = 1; i <= 4; i++)
		{
			a[y][x] = i;
			bool chk = 1, mark[5] = {0};
			if (x != 1 &&  y != 1)
			{
				mark[a[y][x]] = 1;
				mark[a[y - 1][x - 1]] = 1;
				mark[a[y - 1][x]] = 1;
				mark[a[y][x - 1]] = 1;
				for (int j = 1; j <= 4; j++)
					if (!mark[j])
						chk = 0;
			}
			if (chk)
				f (nx, ny);
			a[y][x] = 0;
		
		}
	else
	{
		bool chk = 1, mark[5] = {0};
		if (x != 1 &&  y != 1)
		{
			mark[a[y][x]] = 1;
			mark[a[y - 1][x - 1]] = 1;
			mark[a[y - 1][x]] = 1;
			mark[a[y][x - 1]] = 1;
			for (int i = 1; i <= 4; i++)
				if (!mark[i])
					chk = 0;
		}
		if (chk)
			f (nx, ny);
	}
}

int main()
{
	n = 6;
	a[1][3] = 2;
	a[2][1] = 1;
	a[2][6] = 3;
	a[5][2] = 4;
	a[6][4] = 4;
	f (1, 1);
	cout << r % (28813 * 28813) << endl;
	return 0;
}