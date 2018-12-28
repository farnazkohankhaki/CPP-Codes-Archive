#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 15 * 1000 + 150;

int n, ans;
long long sum;

struct city
{
	int x, p;
	bool operator < (const city &a) const
	{
		return (x < a.x);
	}
} a[MAXN];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].p;
		sum += a[i].p;
	}
	sort (a, a + n);
	long long sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		sum2 += a[i].p;
		ans = a[i].x;
		if (sum2 * 2 > sum)
			break;
	}
	cout << ans << ".00000" << endl;
	return 0;
}