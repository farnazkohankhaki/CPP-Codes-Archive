#include <iostream>

using namespace std;

const int maxN = 100 + 10;

int n, x, y, d, dx[4] = {1, -1, -1, 1}, dy[4] = {1, 1, -1, -1};

int main()
{
	cin >> n;
	d = 1;
	for (int i = 0; i < n; i++)
	{
		x += dx[i % 4] * d;
		y += dy[i % 4] * d;
		d *= 2;
	}
	cout << x << " , " << y << endl;
	return 0;
}