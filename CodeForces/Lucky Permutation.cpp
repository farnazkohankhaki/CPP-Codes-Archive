#include <iostream>

using namespace std;

const int MAXN = 100 *  1000 + 1000;

int n, mdd, a[MAXN];

void f()
{
	int x = n / 4;
	int y = x * 4;
	for (int i = 1; i <= y / 2; i += 2)
	{
		a[i] = i + 1;
		a[i + 1] = n - i + 1;
		a[n - i + 1] = n - i;
		a[n - i] = i;
	}
	if (mdd == 1)
		a[n/2 + 1] = n/2 + 1;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	cin >> n;
	mdd = n % 4;
	if (mdd == 3 || mdd == 2)
		cout << -1 << endl;
	else
		f();
	return 0;
}