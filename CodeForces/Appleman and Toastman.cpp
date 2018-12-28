#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

const int MAXN = 300 * 1000 + 30 * 1000;

ll n, a[MAXN];

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	sort (a, a + n);
	ll ans = 0;
	for (int i = 0; i < n - 1; i++)
		ans += a[i] * (i + 2);
	
	ans += a[n - 1] * n;
	
	cout << ans << endl;
	
	return 0;
}