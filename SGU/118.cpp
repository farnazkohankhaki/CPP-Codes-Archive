#include <iostream>

using namespace std;

const int maxN = 1000 + 8;
long long a[maxN], b[maxN];

long long f (long long x)
{
	long long tmp;
	while (x > 9)
	{
		tmp = 0;
		while (x > 0)
		{
			tmp += x % 10;
			x /= 10;
		}
		x = tmp;
	}
	return x;
}

int main()
{
	int n, k;
	long long r;
	cin >> k;
	for (int l = 0; l < k; l++)
	{
		r = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		b[0] = f (a[0]);
		for (int i = 1; i < n; i++)
			b[i] = f (b[i - 1] * a[i]);
		for (int i = 0; i < n; i++)
			r = f (b[i] + r);
		cout << r << endl;
	}
	return 0;
}