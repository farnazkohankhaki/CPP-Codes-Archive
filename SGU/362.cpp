#include <iostream>

using namespace std;

const int maxN = 10 + 20;

bool mark [maxN][maxN] = {{0}};

int main ()
{
	int n, m, i, j;
	bool f = 0;
	cin >> n >> m >> i >> j;
	for (int l = 0; l <= n + 1; l++)
	{
		mark[l][0] = 1;
		mark[l][m + 1] = 1;
	}
	for (int l = 0; l <= m; l++)
	{
		mark[0][l] = 1;
		mark[n + 1][l] = 1;
	}
	while (!f)
	{
		f = 1;
		mark[i][j] = 1;
		if (!mark[i + 1][j])
		{
			cout << "D";
			i++;
			f = 0;
		}
		if (!mark[i][j - 1] && f)
		{
			cout << "L";
			j--;
			f = 0;
		}
		if (!mark[i - 1][j] && f)
		{
			cout << "U";
			i--;
			f = 0;
		}
		if (!mark[i][j + 1] && f)
		{
			cout << "R";
			j++;
			f = 0;
		}
	}
	cout << endl;
	return 0;
}