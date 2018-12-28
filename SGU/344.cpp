#include <iostream>

using namespace std;

const int maxA = 1000 + 8;

string s[maxA];
bool mark[maxA][maxA] = {{0}};
int ans = 0, n, m;

void f (int i, int j)
{
	int cnt = 0;
	if (i > 1)
		cnt += mark[i - 2][j];
	if (i > 0 && j > 0)
		cnt += mark[i - 1][j - 1];
	if (i > 0 && j < n - 1)
		cnt += mark[i - 1][j + 1];
	if (cnt > 0)
		if (!mark[i - 1][j])
		{
			mark[i - 1][j] = 1;
			ans++;
			f (i - 1, j);
		}
	cnt = 0;
	if (i > 0 && j > 0)
		cnt += mark[i - 1][j - 1];
	if (j > 1)
		cnt += mark[i][j - 2];
	if (i < m - 1 && j > 0)
		cnt += mark[i + 1][j - 1];
	if (cnt > 0)
		if (!mark[i][j - 1])
		{
			mark[i][j - 1] = 1;
			ans++;
			f (i, j - 1);
		}
	cnt = 0;
	if (i > 0 && j < n - 1)
		cnt += mark[i - 1][j + 1];
	if (j < n - 2)
		cnt += mark[i][j + 2];
	if (i < m - 1 && j < n - 1)
		cnt += mark[i + 1][j + 1];
	if (cnt > 0)
		if (!mark[i][j + 1])
		{
			mark[i][j + 1] = 1;
			ans++;
			f (i, j + 1);
		}
	cnt = 0;
	if (i < m - 1 && j > 0)
		cnt += mark[i + 1][j - 1];
	if (i < m - 2)
		cnt += mark[i + 2][j];
	if (i < m - 1 && j < n - 1)
		cnt += mark[i + 1][j + 1];
	if (cnt > 0)
		if (!mark[i + 1][j])
		{
			mark[i + 1][j] = 1;
			ans++;
			f (i + 1, j);
		}
}
	
int main ()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (s[i][j] == 'X')
				if (!mark[i][j])
				{
					mark[i][j] = 1;
					ans++;
					f (i, j);
				}
	cout << ans << endl;
	return 0;
}