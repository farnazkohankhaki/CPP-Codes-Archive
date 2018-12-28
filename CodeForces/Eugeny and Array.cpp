#include <iostream>

using namespace std;

const int MAXN = 200 * 1000 + 20 * 1000;

int n, m, a[MAXN];

int main ()
{
	cin >> n >> m;
	int count0 = 0, count1 = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == -1)
			count0++;
		else
			count1++;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		int t = y - x + 1;
		if (t % 2 == 0)
		{
			if (t / 2 <= count0 && t / 2 <= count1)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else
			cout << 0 << endl;
	}
	
	return 0;
}