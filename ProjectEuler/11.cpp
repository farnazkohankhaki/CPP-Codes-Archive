#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 20 + 8;

int a[maxN][maxN];

int main()
{
	int maxp = 0;
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= 20; j++)
			cin >> a[i][j];
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= 17; j++)
			maxp = max (maxp, a[i][j] * a[i][j + 1] * a[i][j + 2] * a[i][j + 3]);
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= 17; j++)
			maxp = max (maxp, a[j][i] * a[j + 1][i] * a[j + 2][i] * a[j + 3][i]);
	for (int i = 1; i <= 17; i++)
		for (int j = 1; j <= 17; j++)
			maxp = max (maxp, a[i][j] * a[i + 1][j + 1] * a[i + 2][j + 2] * a[i + 3][j + 3]);
	for (int i = 1; i <= 17; i++)
		for (int j = 4; j <= 20; j++)
			maxp = max (maxp, a[i][j] * a[i + 1][j - 1] * a[i + 2][j - 2] * a[i + 3][j - 3]);
	cout << maxp << endl;
	return 0;
}
