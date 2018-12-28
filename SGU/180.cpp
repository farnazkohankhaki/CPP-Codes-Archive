#include <iostream>

using namespace std;

const int MAXN = 1000 * 100 + 100;

int n, a[MAXN], tmp[MAXN];

long long merge (int x, int m, int y)
{
	int p1 = x, p2 = m, cnt = x;
	long long r = 0;
	while (p1 < m && p2 < y)
	{
		if (a[p2] < a[p1])
		{
			tmp[cnt] = a[p2];
			r += m - p1;
			cnt++;
			p2++;
		}
		else
		{
			tmp[cnt] = a[p1];
			cnt++;
			p1++;
		}
	}
	if (p2 == y)
		for (int i = p1; i < m; i++)
			a[cnt + i - p1] = a[i];
	for (int i = x; i < cnt; i++)
		a[i] = tmp[i];
	return r;
}

long long findInv (int x, int y)
{
	if (x + 1 >= y)
		return 0;
	long long r = 0, m = (x + y) / 2;
	r += findInv (x, m) + findInv (m, y);
	r += merge (x, m, y);
	return r;
}

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << findInv (0, n) << endl;
	return 0;
}