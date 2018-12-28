#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 500000 + 50;
const int mod = 1000;

int n, a[MAXN], s = 99, l = 10000, ans;
vector <int> prime;
bool mark[MAXN];

void findPrime()
{
	for (int i = 2; prime.size() < n+s+10; i++)
		if (!mark[i])
		{
			prime.push_back(i);
			for (int j = 2; j * i <= n * n; j++)
				mark[j * i] = true;
		}
}

void f()
{
	for (int i = 0; i < n; i++)
		a[i] = prime[s + i] % mod;
}

int main()
{
	cin >> n;
	findPrime();
	f();
	int p = max_element(a, a + n) - a;
	int l = p, r = p;
	while (l > 0)
	{
		int x = max_element(a, a + l) - a;
		ans += a[x] * (l - x);
		l = x;
	}
	while (r < n - 1)
	{
		int x = max_element(a + r +	1, a + n) - a;
		ans += a[x] * (x - r);
		r = x;
	}
	cout << ans << endl;
	return 0;
}