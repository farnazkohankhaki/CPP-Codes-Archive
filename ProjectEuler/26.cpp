#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000 * 10 + 100;

int n = 1000;

int mark[MAXN], d[MAXN];

int find(int x)
{
	for (int i = 0; i < n * 10; i++)
		mark[i] = 0;
	int y = 10;
	int cnt = 0;
	while (mark[y] == 0)
	{
		cnt++;
		mark[y] = cnt;
		y = (y % x) * 10;
	}
	if (y != 0)
		return cnt - mark[y] + 1;
	else
		return 0;
}

int main()
{
	for (int i = 2; i < n; i++)
		d[i] = find(i);
	cout << max_element(d, d + n + 1) - d << endl;
	return 0;
}