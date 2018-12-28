#include <iostream>

using namespace std;

const int MAXN = 100 + 10;

int a, n, d[MAXN];

void dyna()
{
	int c = 1;
	d[0] = a;
	for (int i = 1; c <= n; i++)
	{
		c *= 2;
		d[i] = d[i-1] * d[i-1];
	}
}

int Pow ()
{
	int r = 1;
	for (int c = 0; n > 0; c++)
	{
		if (n % 2)
			r *= d[c];
		n /= 2;
	}
	return r;
}

int main()
{
	cin >> a >> n;
	dyna();
	cout << Pow() << endl;
	return 0;
}