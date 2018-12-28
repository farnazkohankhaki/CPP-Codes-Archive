#include <iostream>

using namespace std;

const int MAXN = 100 + 10;

int n, a[MAXN], t[MAXN], f[MAXN];

int number()
{
	int ans = 1;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		f[i] = f[i - 1] * i;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
			if (a[j] < a[i])
				t[a[i]]--;
		ans += t[a[i]] * f[n - i];
	}
	return ans;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		t[i] = i - 1;
	}
	cout << number() << endl;
	return 0;
}