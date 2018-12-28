#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int n, r[MAXN], c[MAXN], d[MAXN][MAXN], INF = 10000 + 10;

void dyna() //[ , )
{
	for (int i = n - 1; i >= 0; i--)
		for (int j = i + 2; j <= n; j++)
		{
			d[i][j] = INF;
			for (int k = i + 1; k < j; k++)
				d[i][j] = min (d[i][j], d[i][k] + d[k][j] + r[i] * c[j - 1] * r[k]); 
		}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> r[i] >> c[i];
	dyna();
	cout << d[0][n] << endl;
	return 0;
}