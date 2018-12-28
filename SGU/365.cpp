#include <iostream>

using namespace std;

const int MAXN = 100 + 10;

long long s, d[MAXN][MAXN];

void build ()
{
	for (int i = 0; i < s + 20; i++)
		d[i][0] = 1;
	for (int i = 1; i < s + 20; i++)
		for (int j = 1; j <= i; j++)
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
}

long long findAns ()
{
	long long r = 0;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= s; j++)
		{
			if (s + i - j - 2 >= 0 && i - 2 >= 0)
				r += d[s + i - j - 2][i - 2] * d[j + i - 2][i - 1];
			else
				r += d[j + i - 2][i - 1];
		}
	return r - s + 1;
}

int main ()
{
	cin >> s;
	build();
	cout << findAns () << endl;
	return 0;
}