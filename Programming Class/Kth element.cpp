#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int n, k, a[MAXN];

int qsort (int s, int t, int x)
{
	if (t - s < 2)
		return a[s];
	int r = s + rand () % (t - s);
	swap (a[s], a[r]);
	int p = s, q = t - 1, key = a[s];
	while (p < q)
	{
		while (a[p] <= key && p < t)
			p++;
		while (a[q] > key && q > s)
			q--;
		if (p < q)
			swap (a[p], a[q]);
	}
	swap (a[s], a[q]);
	if (x == q - s + 1)
		return a[q];
	else if (x < q - s + 1)
		return qsort (s, q, x);
	else
		return qsort (q + 1, t, x - q - 1 + s);
}

int main ()
{
	srand (time (0));
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << qsort (0, n, k) << endl;
	return 0;
}