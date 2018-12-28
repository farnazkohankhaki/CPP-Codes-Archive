#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1000 * 1000 * 10 + 1000;
const int L = 1000 * 100;

bool mark[MAXN];
int cnt, a[7] = {1, 2, 3, 4, 5, 6, 7};

void findPrime()
{
	mark[1] = mark[0] = true;
	for (int i = 2; i < L; i++)
		if (!mark[i])
			for (int j = 2; j * i < MAXN; j++)
				mark[j * i] = true;
}

int findN()
{
	int r = 0, d = 1;
	for (int i = 0; i < 7; i++)
	{
		r += a[i] * d;
		d *= 10;
	}
	return r;
}

int main()
{
	findPrime();
	while (next_permutation(a, a + 7))
	{
		int x = findN();
		if (!mark[x])
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}