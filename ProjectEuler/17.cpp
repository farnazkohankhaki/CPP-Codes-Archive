#include <iostream>

using namespace std;

const int s1[10] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
const int s2[10] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
const int s3[10] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
const int h1 = 7, h2 = 3;

int ans, n = 1000;

int find (int x)
{
	int r = 0;
	int y = x / 100;
	if (y > 0)
	{
		r += s1[y];
		r += h1;
		if (y * 100 != x)
			r += h2;
	}
	x %= 100;
	y = x / 10;
	if (y > 0 && y == 1)
	{
		r += s2[x % 10];
		x /= 100;
	}
	else if (y > 0)
		r += s3[y];
	r += s1[x % 10];
	return r;
}

int main()
{
	ans = 11;
	for (int i = 1; i < n; i++)
		ans += find(i);
	cout << ans << endl;
	return 0;
}