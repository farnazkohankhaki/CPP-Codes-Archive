#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int MAXN = 10000 + 1000;

ll n, a[MAXN], d[MAXN], cnt, ans[MAXN];

bool hate (ll y, ll x)
{
	while (y % 2 == 0 && y > x)
	{
		y /= 2;
		if (y == x)
			return true;
	}
	return false;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--)
	{
		bool p = true;
		for (int j = 0; j < cnt && p; j++)
			if (hate(ans[j], a[i]))
				p = false;
		if (p)
			ans[cnt++] = a[i];
	}
	cout << cnt << endl;
	for (int i = cnt - 1; i >= 0; i--)
		cout << ans[i] << endl;
	return 0;
}