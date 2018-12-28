#include <iostream>

using namespace std;

const int maxN = 100 + 10;

int n, m, a[maxN][maxN], par[maxN][maxN][2], p[maxN][maxN], d[maxN][maxN];

void dyna ()
{
	for (int i = 0; i < n; i++)
	{
		p[i][0] = a[i][0];
		for (int j = 1; j < m; j++)
			p[i][j] = a[i][j] + p[i][j - 1];
	}
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < m; j++)
		{
			par[i][j][0] = j;
			d[i][j] = d[i + 1][j];
			for (int k = 1; k < m; k++)
			{
				int x = (j + k) % m, sum =  p[i][j] - p[i][x];
				if (x < j && d[i][j] < d[i + 1][x] + p[i][m - 1] - sum)
				{
					d[i][j] = d[i + 1][x] + p[i][m - 1] - sum;
 					par[i][j][0] = x;
					par[i][j][1] = m - j + x;
				}
				if (x > j && d[i][j] < d[i + 1][x] - sum)
				{

					d[i][j] = d[i + 1][j] - sum;
					par[i][j][0] = x;
					par[i][j][1] = x - j;
				}
			}
			d[i][j] += a[i][j];
		}
}

void findR (int r)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < par[i][r][1]; j++)
			cout << "r ";
		cout << "d ";
	}
	cout << endl;
}

int main ()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	dyna();
	int ans = 0;
	for (int i = 1; i < m; i++)
		if (d[0][ans] < d[0][i])
			ans = i;
	cout << d[0][ans] << endl << 0 << ", " << ans << endl;
	findR (ans);	
	return 0;
}