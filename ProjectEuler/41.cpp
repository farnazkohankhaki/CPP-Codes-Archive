#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1000 * 1000 * 10 + 10000;
bool mark[MAXN];


int n = 7, m = 1000 * 1000 * 10, a[7] = {1, 2, 3, 4, 5, 6, 7};

void findPrime ()
{
	mark[0] = mark[1] = true;
	for (int i = 2; i <= sqrt (m); i++)
		if (!mark[i])
			for (int j = 2; j * i <= m; j++)
				mark[i * j] = true;
}

int findN ()
{
	int r = 0;
	for (int i = 0; i < n; i++)
	{
		r *= 10;
		r += a[i];
	}
	return r;
}

int findPan()
{
	int r = 0;
	int x = findN();
	if (!mark[x])
		r = x;
	while (next_permutation (a, a + n))
	{
		x = findN();
		if (!mark[x])
			r = x;
	}
	return r;
}
	
int main ()
{
	findPrime();
	int x = findPan();
	cout << x << endl;
	return 0;
}