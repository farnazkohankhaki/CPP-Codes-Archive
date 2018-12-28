#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int d = 10000;

int n;
double la;

int main ()
{
	cin >> la >> n;
	long long ans = 0, m, v, l = la * d + 0.5;
	for (int i = 0; i < n; i++)
	{
		cin >> m >> v;
		v *= d;
		long long x = m * v / l;
		long long y = m * v - x * l;
		ans += y;
		if (ans >= l)
			ans -= l;
	}
	
	long long t = l - ans;
	if (t < ans)
		ans = t;
	
	int x = ans % d;
	string s = "";
	
	for (int i = 0; i < 4; i++)
	{
		s += x % 10 + '0';
		x /= 10;
	}
	reverse(s.begin(), s.end());
	
	cout << ans / d << "." << s << endl;
	
	return 0;
}