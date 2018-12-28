#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 + 10;

int n, d[MAXN], a[MAXN][MAXN];
bool mark[MAXN];

void init()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		d[i] = -1;
}

int findMin()
{
	int r = n;
	for (int i = 0; i < n; i++)
		if (!mark[i] && (r == n || d[i] < d[r]) && d[i] != -1)
			r = i;
	return r;
}

void update(int u)
{
	for (int i = 0; i < n; i++)
		if (d[u] + a[u][i] < d[i] || d[i] == -1)
			d[i] = d[u] + a[u][i];
}

void djk()
{
	for (int i = 0; i < n; i++)
	{
		int u = findMin();
		mark[u] = true;
		update(u);
	}
}

int main()
{
	init();
	djk();
	cout << d[n - 1] << endl;
	return 0;
}