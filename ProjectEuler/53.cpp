#include <iostream>

using namespace std;

const int MAXN = 100 + 10, L = 1000 * 1000;

int d[MAXN][MAXN], cnt, n = 100;

void dyna()
{
	for (int i = 0; i <= n; i++)
		d[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (d[i - 1][j] == -1 || d[i - 1][j - 1] == -1)
			{
				d[i][j] = -1;
				cnt++;
				continue;
			}
			d[i][j] = d[i - 1][j] + d[i - 1][j - 1];
			if (d[i][j] > L)
			{
				cnt++;
				d[i][j] = -1;
			}
		}
}

int main()
{
	dyna();
	cout << cnt << endl;
	return 0;
}