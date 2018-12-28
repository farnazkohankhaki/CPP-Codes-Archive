#include <iostream>

using namespace std;

const int MAXN = 1000 * 100 + 1000;

int n = 10000, t = 30000, d[MAXN];

void findD (int x)
{
	for (int i = 1; i < x; i++)
		if (x % i == 0)
			d[x] += i;
}

long long findAmi ()
{
	long long r = 0;
	for (int i = 1; i < n; i++)
	{
		int x = d[i];
		if (d[x] == i && x != i)
			r += i;
	}
	return r;
}

int main ()
{
	for (int i = 1; i < t; i++)
		findD (i);
	cout << findAmi() << endl;
	return 0;
}