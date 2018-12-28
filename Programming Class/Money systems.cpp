#include <iostream> 

using namespace std;

const int maxN = 100 + 10, maxM = 100 + 10;

int n, m, d[maxN][maxM], v[maxN];

void dyna()
{
	d[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k * v[i] <= j; k++)
				d[i][j] += d[i - 1][j - k * v[i]];
}

int main ()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	dyna();
	cout << d[n][m] << endl;
	return 0;
}