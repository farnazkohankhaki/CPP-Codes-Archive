#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10 + 10, delta = 20102;

int n = 10, a[MAXN], p = 50, cnt = 0;
bool prm[MAXN];

void init()
{
	prm[2] = true;
	for (int i = 3; i <= 7; i += 2)
		prm[i] = true;
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
}

int minS()
{
	int c = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != i + 1)
			c++;
	return (c + 1) / 2;
}

int main()
{
	init();
	while (next_permutation(a, a + n))
	{
		int ms = minS();
		if (prm[ms])
			cnt++;
		if (cnt == p)
		{
			cout << a[3] % delta << endl;
			break;
		}
	}
	return 0;
}