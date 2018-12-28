#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 100 + 10, maxK = 100 + 10;

int n, k, d[maxK][maxN][maxN];

void dyna()
{
	for (int i = 1; i < n + 2; i++)
		for (int j = i + 1; j < n + 2; j++)
			d[1][i][j] = j - i;
	for (int l = 2; l <= k; l++)
		for (int i = n + 1; i > 0; i--)
			for (int j = n + 1; j > i; j--)
			{
				d[l][i][j] = d[l - 1][i][j];
				for (int q = j - 1; q > i; q--)
					d[l][i][j] = min (d[l][i][j], max (d[l - 1][i][q] + 1, d[l][q + 1][j] + 1));
			}
}

int main()
{
	cin >> n >> k;
	dyna();
	cout << d[k][1][n + 1] << endl;
	return 0;
}