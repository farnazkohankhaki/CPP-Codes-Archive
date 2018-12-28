#include <iostream>

using namespace std;

const int maxN = 100 + 8, h[6][3] = {{0, 1, 0}, {1, 0, 0}, {0, -1, 0}, {-1, 0, 0}, {0, 0, 1}, {0, 0, -1}};

int n, a[maxN][maxN][maxN] = {{{0}}};

int f (int i, int j, int k)
{
	int x = 0, y = 6;
	for (int l = 0; l < 6; l++)
		x += a[i + h[l][0]][j + h[l][1]][k + h[l][2]];
	if (i == 1 || i == n)
		y--;
	if (j == 1 || j == n)
		y--;
	if (k == 1 || k == n)
		y--;
	return x / y;
}

int main ()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				cin >> a[i][j][k];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				cout << f (i, j, k);
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}