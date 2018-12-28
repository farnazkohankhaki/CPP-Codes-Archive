#include <iostream>

using namespace std;

const int MAXN = 10 + 10;

bool mark[2][MAXN];
int n, k;
long long d[MAXN][MAXN];

void dyna ()
{
	for (int i = 0; i <= n; i++)
		d[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			d[i][j] = d[i - 1][j] + d[i - 1][j - 1];
}

long long f ()
{
	if (k > n)
		return 0;
	dyna();
	long long r = d[n][k];
	for (int i = n; i > n - k; i--)
		r *= i;
	return r;
}

int main ()
{
	cin >> n >> k;
	cout << f() << endl;
	return 0;
}