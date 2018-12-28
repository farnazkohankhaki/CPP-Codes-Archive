#include <iostream>

using namespace std;

const int maxN = 1000 + 8;

int a[maxN], arr[maxN][2][2] = {{{0}}};

int main ()
{
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (a[0] == 0)
		arr[0][0][0] = 1;
	if (a[0] == 1)
	{
		arr[0][1][0] = 1;
		arr[0][0][1] = 1;
	}
	if (a[0] == 2)
		arr[0][1][1] = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] == 0)
			arr[i][0][0] = arr[i - 1][0][0];
		if (a[i] == 1)
		{
			arr[i][0][0] = arr[i - 1][1][0];
			arr[i][0][1] = arr[i - 1][0][0];
			arr[i][1][0] = arr[i - 1][0][1];
		}
		if (a[i] == 2)
		{
			arr[i][0][1] = arr[i - 1][1][0];
			arr[i][1][0] = arr[i - 1][1][1];
			arr[i][1][1] = arr[i - 1][0][1];
		}
		if (a[i] == 3)
			arr[i][1][1] = arr[i - 1][1][1];
	}
	ans = arr[n - 1][0][0] + arr[n - 1][1][0];
	cout << ans << endl;
	return 0;
}