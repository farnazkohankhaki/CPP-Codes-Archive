#include <iostream>

using namespace std;

const int maxA = 100 + 8;

string a[maxA];
bool mark[maxA][maxA] = {{0}};

int main ()
{
	int n, m, d = 0, x = 0, y = 0, ans = 0;
	string p;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> p;
	for (int i = 0; i < p.size(); i++)
	{
		if (p[i] == 'R')
		{
			d++;
			d %= 4;
		}
		if (p[i] == 'L')
		{
			d += 3;
			d %= 4;
		}
		if (p[i] == 'M')
		{
			if (d == 0)
			{
				if (x < n && y < m)
					
					if (!mark[x][y])
					{
						mark[x][y] = 1;
						ans += a[x][y] - '0';
					}
					else
						ans += (a[x][y] - '0') / 2;
				
				if (x > 0 && y < m)
					if (!mark[x - 1][y])
					{
						mark[x - 1][y] = 1;
						ans += a[x - 1][y] - '0';
					}
					else
						ans += (a[x - 1][y] - '0') / 2;
	
				y++;
			}
			if (d == 1)
			{
				if (x < n && y < m)

					if (!mark[x][y])
					{
						mark[x][y] = 1;
						ans += a[x][y] - '0';
					}
					else
						ans += (a[x][y] - '0') / 2;
				
				if (x < n && y > 0)
					if (!mark[x][y - 1])
					{
						mark[x][y - 1] = 1;
						ans += a[x][y - 1] - '0';
					}
					else
						ans += (a[x][y - 1] - '0') / 2;
				x++;
			}
			if (d == 2)
			{
				if (x < n && y > 0)
					if (!mark[x][y - 1])
					{
						mark[x][y - 1] = 1;
						ans += a[x][y - 1] - '0';
					}
					else
						ans += (a[x][y - 1] - '0') / 2;
				
				if (x > 0 && y > 0)
					if (!mark[x - 1][y - 1])
					{
						mark[x - 1][y - 1] = 1;
						ans += a[x - 1][y - 1] - '0';
					}
					else
						ans += (a[x - 1][y - 1] - '0') / 2;
				y--;
			}
			if (d == 3)
			{
				if (x > 0 && y < m)
					if (!mark[x - 1][y])
					{
						mark[x - 1][y] = 1;
						ans += a[x - 1][y] - '0';
					}
					else
						ans += (a[x - 1][y] - '0') / 2;
				
				if (x > 0 && y > 0)
					if (!mark[x - 1][y - 1])
					{
						mark[x - 1][y - 1] = 1;
						ans += a[x - 1][y - 1] - '0';
					}
					else
						ans += (a[x - 1][y - 1] - '0') / 2;
				x--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}