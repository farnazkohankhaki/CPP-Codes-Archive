#include <iostream>
#include <vector>

using namespace std;

int l = 1000 * 1000;
int d[7] = {0, 9, 99, 999, 9999, 99999, 999999};

vector <int> a;

void plusX (int x)
{
	vector <int> y;
	while (x > 0)
	{
		y.push_back (x % 10);
		x /= 10;
	}
	for (int i = y.size() - 1; i >= 0; i--)
		a.push_back(y[i]);
}

int main ()
{
	int x = 1;
	while (a.size() < l)
	{
		plusX(x);
		x++;
	}
	long long ans = 1;
	for (int i = 0; i < 7; i++)
		ans *= a[d[i]];
	cout << ans << endl;
	return 0;
}