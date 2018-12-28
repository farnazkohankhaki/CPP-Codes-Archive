#include <iostream>

using namespace std;

const int MAXN = 100 + 10;

int n, num, f[MAXN], a[MAXN], mark[MAXN];

void find()
{
	num--;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1] * i;
		mark[i] = 1;
	}
	
	for (int i = 1; i <= n; i++)
	{
		int x = num / f[n - i], sum = 0, j;
		for (j = 1; sum <= x; j++)
			sum += mark[j];
		j--;
		mark[j] = 0;
		a[i] = j;
		num -= f[n - i] * x;
	}
}

int main()
{
	cin >> n >> num;
	find();
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
