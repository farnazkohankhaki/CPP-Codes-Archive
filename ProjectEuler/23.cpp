#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 1000 * 10;

int n = 28123;
long long ans;
bool mark[MAXN];

void findM (int x)
{
	long long r = 0;
	for (int i = 1; i < x; i++)
		if (x % i == 0)
			r += i;
	if (r > x)
		mark[x] = true;
}

bool isA (int x)
{
	for (int i = 1; i <= x; i++)
		if (mark[i] && mark[x - i])
			return true;
	return false;
}

int main ()
{
	for (int i = 1; i <= n; i++)
		findM (i);
	for (int i = 1; i <= n; i++)
		if (!isA (i))
			ans += i;
	cout << ans << endl;
	return 0;
}