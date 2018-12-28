#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 1000 + 100;

int n, m, a[MAXN][MAXN], b[MAXN][MAXN];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
		
	for (int j = m - 1; j >= 0; j--)
		for (int i = n - 1; i >= 0; i--)
		{
			b[i][j] = a[i][j];
			if (i < n - 1)
				b[i][j] = min (b[i][j], b[i + 1][j]);
			if (j < m - 1)
				b[i][j] = min (b[i][j], b[i][j + 1]);
			if (i > 0 && j < m - 1)
				b[i][j] = min (b[i][j], b[i - 1][j + 1]);

		}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}
		
	return 0;
}