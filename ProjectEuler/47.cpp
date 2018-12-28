#include <iostream>
#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 1000 * 1000;

bool mark[MAXN];
int n = 1000000, p = 4;

void findPrime ()
{
	mark[0] = mark[1] = true;
	for (int i = 2; i <= sqrt (n); i++)
		if (!mark[i])
			for (int j = 2; j * i <= n; j++)
				mark[i * j] = true;
}

bool isP (int x)
{
	int cnt = 0;
	for (int i = 1; i < sqrt (x); i++)
		if (x % i == 0)
		{
			if (!mark[i])
				cnt++;
			if (!mark[x / i])
				cnt++;
		}
	if ((int)sqrt(x) * (int)sqrt(x) == x)
		cnt++;
	if (cnt == p)
		return true;
	return false;
}

int main ()
{
	findPrime();
	int a[4];
	for (int i = 1; i < n; i++)
	{
		bool r = true;
		for (int j = 0; j < p; j++)
		{
			a[j] = i + j;
			if (!isP (a[j]))
				r = false;
		}
		if (r)
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}	