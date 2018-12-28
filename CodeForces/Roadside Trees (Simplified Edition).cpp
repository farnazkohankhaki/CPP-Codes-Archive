#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 100 * 1000 + 10000;

int n, h[MAXN], sum;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	int lh = 0;
	sum = 2 * n - 1;
	for (int i = 0; i < n; i++)
	{
		sum += abs(h[i] - lh);
		lh = h[i];
	}
	cout << sum << endl;
	return 0;
}
