#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 100 + 10;

int n, a[MAXN], f[MAXN];
set <int> s;

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	f[0] = a[0];
	for (int i = 1; i < n; i++)
		f[i] = f[i - 1] + a[i];
	int solve = f[n - 1], e = 0, mini;
	s.insert (0);
	for (int i = n - 1; i >= 0; i--)
	{
		mini = (*s.begin());
		solve = max (solve, f[n - 1] - 2 * mini - 2 * f[i]);
		e = e + a[i];
		s.insert (e);
	}
	mini = (*s.begin());
	solve = max (solve, f[n - 1] - 2 * mini);
	cout << solve << endl;
	return 0;
}