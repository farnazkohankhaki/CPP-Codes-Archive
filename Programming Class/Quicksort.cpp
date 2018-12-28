#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int n, a[MAXN];

void qsort (int s, int t)
{
	if (t - s < 2)
		return;
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
	qsort (s, q);
	qsort (q + 1, t);
}
	
int main ()
{
	srand (time (0));
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	qsort (0, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}