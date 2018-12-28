#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll a, b, cnt;

ll gcd (ll a, ll b)
{
	while (a != 0)
	{
		ll y = b % a;
		b = a;
		a = y;
	}
	return b;
}

int main()
{
	cin >> a >> b;
	while (true)
	{
		if (a > b)
			swap(a, b);
		if (a == 0)
		{
			cout << cnt << endl;
			break;
		}
		if (a % 2 + b % 2 == 1)
		{
			cout << -1 << endl;
			break;
		}
		ll x = gcd (a, b);
		a /= x;
		b /= x;
		b -= a;
		a *= 2;
		cnt++;
	}
	return 0;
}