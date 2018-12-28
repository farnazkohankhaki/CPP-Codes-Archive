#include <iostream>

using namespace std;

const int MAXM = 4000 + 400;

int n, m, h[10], s[10];

int main()
{
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		if (h[y] + 100 > 0)
			s[x] += 3;
		h[y] -= 8;
	}
	for (int i = 0; i < n; i++)
	{
		h[i] += 100;
		if (h[i] > 0)
			s[i] += h[i] / 2;
		cout << h[i] << " " << s[i] << endl;
	}
	return 0;
}