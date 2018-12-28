#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1000 + 100;

int a[maxN][maxN], in[maxN], n;

void swp (int i, int j)
{
	swap (in[i], in[j]);
}

bool isless (int i, int j)
{
	int x = in[i], y = in[j];
	for (int l = 0; l < n; l++)
	{
		if (a[x][l] < a[y][l])
			return 1;
		if (a[x][l] > a[y][l])
			return 0;
	}
	return 1;
}

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		in[i] = i;
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	for (int i = 1; i < n; i++)
		for (int k = i; isless (k, k - 1) && k > 0; k--)
				swp (k, k - 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[in[i]][j] << " ";
		cout << endl;
	}
	return 0;
}