#include <iostream> 
#include <algorithm>

using namespace std;

const int maxN = 100 + 10, maxM = 100 + 10, inf = 100000 + 10;

int n, m, d[maxN][maxM], v[maxN], t[maxN][maxM];

void dyna()
{
	for (int i = 1; i <= m; i++)
		d[0][i] = inf;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
		{
			d[i][j] = inf;
			for (int k = 0; k * v[i] <= j; k++)
				if (d[i][j] > d[i - 1][j - k * v[i]] + k)
				{
					t[i][j] = k;
					d[i][j] = d[i - 1][j - k * v[i]] + k;
				}
		}
}

void output()
{
	if (d[n][m] == inf)
	{
		cout << ":|" << endl;
		return;
	}
	cout << d[n][m] << endl;
	int p1 = n, p2 = m;
	while (p2 > 0)
	{
		if (t[p1][p2] > 0)
			cout << p1 << ": " << t[p1][p2] << endl;
		p2 -= t[p1][p2] * v[p1];
		p1--;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	dyna();
	output();
	return 0;
}