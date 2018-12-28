#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 100 + 8;

long long a[maxN][maxN] = {{0}};

int main()
{
	long long b;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j <= i; j++)
			cin >> a[i][j];
	for (int i = 1; i < 100; i++)
	{
		a[i][0] += a[i - 1][0];
		for (int j = 1; j <= i; j++)
			a[i][j] += 	max (a[i - 1][j - 1], a[i - 1][j]);
		
	}
	b = 0;
	for (int i = 0; i < 100; i++)
		b = max(b, a[99][i]);
	cout << b << endl;
	return 0;
}