#include <iostream>

using namespace std;

int n, q;

int find (int x, int y)
{
	if (x == 1)
		return y;
	int m = x / 2;
	if (y <= m)
		return x - m + find (m, m - y + 1);
	else
		return find (x - m, x - y + 1);
}

int main ()
{
	cin >> n >> q;
	cout << find (n, q) << endl;
	return 0;
}