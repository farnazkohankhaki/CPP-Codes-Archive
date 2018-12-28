#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 100, MAXR = 100 + 10;

long long n, a[MAXN], r[MAXR], ans;

int mab2 (int x)
{
	int r = 0;
	while (x > 0)
	{
		r += x%2;
		x /= 2;
	}
	return r;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		r[mab2(a[i])]++;
	for (int i = 0; i < 100; i++)
		ans += r[i]*(r[i]-1)/2;
	cout << ans << endl;
	return 0;
}