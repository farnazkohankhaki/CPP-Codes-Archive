#include <iostream>
#include <algorithm>

using namespace std;

int n, t;
string s;

int main ()
{
	long long ans = 0;
	cin >> n >> t >> s;
	int p;
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] != s[i + 1])
		{
			p = i + 1;
			break;
		}
	}
	int pmin = 0, mini = n;
	for (int i = p; i < n + p; i++)
	{
		int x = i;
		int y = 1;
		while (s[i % n] == s[(i + 1) % n])
		{
			y++;
			i++;
		}
		if (y < mini)
		{
			mini = y;
			pmin = x;
		}
		ans += y * y;
	}
	ans += (mini - 1) * (mini - 1) + 1 - mini * mini;
	cout << pmin + 1 << endl << ans << endl;
	return 0;
}