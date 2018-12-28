#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int main()
{
	cin >> n >> m;
	int ans = 0;
	if (n % 2 == 0)
		swap (n, m);
	if (m % 2 == 0)
		ans = n * m / 2;
	else
		ans = (n * m - 1) / 2;
	cout << ans << endl;
	return 0;
}