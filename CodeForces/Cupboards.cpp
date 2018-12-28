#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10000 + 1000;

int n, d[MAXN][2], t;

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> d[i][0] >> d[i][1];
	int x1 = 0, y1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (d[i][0] == 0)
			x1++;
		if (d[i][1] == 0)
			y1++;
	}
	int x2 = n - x1, y2 = n - y1;
	t += min (x1, x2) + min (y1, y2);
	cout << t << endl;
	return 0;
}