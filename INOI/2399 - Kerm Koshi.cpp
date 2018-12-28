#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 100000 + 8;

int a[maxN], h[maxN], g[maxN];

int main()
{
	int n, k, c, and1, and2;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n);
	for (int i = 0; i < k; i++)
		cin >> h[i] >> g[i];
	for (int i = 0; i < k; i++)
	{
		and1 = lower_bound (a, a + n, h[i]) - a;
		and2 = upper_bound (a, a + n, g[i]) - a;
		c = and2 - and1;
		cout << c << endl;
	}
	return 0;
}