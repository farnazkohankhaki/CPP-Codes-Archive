#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 10000 + 8;

int a[maxN] = {0};
bool mark[maxN];

int main()
{
	int n, t = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			mark[j] = 0;
		for (int j = 1; j < i; j++)
			if (i % j == 0)
				mark[a[j]] = 1;
		for (int j = 1; j <= n; j++)
			if (!mark[j])
			{
				t = max (t, j);
				a[i] = j;
				break;
			}
	}
	cout << t << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}