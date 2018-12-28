#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int n, m, a[MAXN][MAXN], x[MAXN][MAXN], y[MAXN][MAXN], d[MAXN][MAXN], ansx[MAXN][MAXN], ansy[MAXN][MAXN];

void input ()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
}

void init ()
{
	for (int i = 0; i < n; i++)
		a[i][m] = 2;
	for (int i = 0; i <= m; i++)
		a[n][i] = 2;
}

void build ()
{
	init();
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
		{
			x[i][j] = 1;
			y[i][j] = 1;
			if (a[i][j] == a[i + 1][j])
				x[i][j] = x[i + 1][j] + 1;
			if (a[i][j] == a[i][j + 1])
				y[i][j] = y[i][j + 1] + 1;
			int mx = x[i][j];
			for (int k = j; k < j + y[i][j]; k++)
			{
				mx = min (mx, x[i][k]);
				if ((k - j + 1) * mx > d[i][j])
				{
					d[i][j] = (k - j + 1) * mx;
					ansx[i][j] = mx + i - 1;
					ansy[i][j] = k;
				}
			}
		}
}

void output ()
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (d[i][j] > d[ans / m][ans % m])
				ans = i * m + j;
	int mx = ans / m, my = ans % m;
	cout << d[mx][my] << endl;
	cout << "up , left : " << mx + 1 << " , " << my + 1 << endl;
	cout << "down, right : " << ansx[mx][my] + 1 << " , " << ansy[mx][my] + 1 << endl;
}

int main ()
{
	input();
	build();
	output();
	return 0;
}