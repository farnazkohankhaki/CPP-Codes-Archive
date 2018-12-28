#include <iostream>
#include <algorithm>

using namespace std;

long long n, t[2], cnt, r[2];

int main()
{
	cin >> n >> t[0] >> t[1];
	while (cnt < n)
	{
		int x = 0;
		if (r[0] > r[1])
			x = 1;
		cnt++;
		r[x] += t[x];
	}
	int x = 0;
	if (r[0] > r[1])
		x = 1;
	long long y = r[(x+1)%2] - r[x];
	if (y != 0)
	{
		r[x] = r[x] + t[x];
		cnt++;
	}
	cout << cnt << " " << max(r[0], r[1]) << endl;
	return 0;
}