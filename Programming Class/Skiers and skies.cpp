#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1000 + 100;

int n, p[maxN], s[maxN];

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort (p, p + n);
	sort (s, s + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += abs (p[i] - s[i]);
	cout << ans << endl;
	for (int i = 0; i < n; i++)
		cout << p[i] << ": " << s[i] << endl;
	return 0;
}