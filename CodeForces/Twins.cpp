#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int n, a[MAXN];

int main()
{
	int sum = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	sort (a, a + n);
	int mine = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		mine += a[i];
		if (mine > sum / 2)
		{
			cout << n - i << endl;
			i = -1;
		}
	}
	
	return 0;
}
