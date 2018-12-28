#include <iostream>

using namespace std;

const int maxA = 100 + 8;

int arr[maxA][maxA];

void f (int i, string s)
{
	for (int j = 0; j < s.size(); j++)
		arr[i][j + 1] = s[j] - '0';
}

int main()
{
	int n, m, ans = 0;
	string s;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		f (i, s);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] != 0)
				ans += 2;
			if (arr[i][j] - arr[i - 1][j] > 0)
				ans += arr[i][j] - arr[i - 1][j];
			if (arr[i][j] - arr[i + 1][j] > 0)
				ans += arr[i][j] - arr[i + 1][j];
			if (arr[i][j] - arr[i][j - 1] > 0)
				ans += arr[i][j] - arr[i][j - 1];
			if (arr[i][j] - arr[i][j + 1] > 0)
				ans += arr[i][j] - arr[i][j + 1];
		}
	cout << ans << endl;
	return 0;
}