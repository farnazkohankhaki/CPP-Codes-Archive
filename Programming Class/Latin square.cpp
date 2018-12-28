#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int a[5] = {1, 2, 3, 4, 5};
const int h[2][2] = {{0, 1}, {1, 0}};

int n = 5, cnt, b[5][5];
bool mark[5][6], markd[5][5];

void dfs (int x, int y)
{
	markd[x][y] = true;
	for (int i = 0; i < 2; i++)
	{
		int nx = x + h[i][0], ny = y + h[i][1];
		if (nx == n || ny == n || ny < 0 || nx < 0)
			continue;
		if (!markd[nx][ny] && b[nx][ny] % 2 == 1)
			dfs(nx, ny);
	}
}
	
bool isR()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			markd[i][j] = false;
	if (b[0][0] % 2 == 0 || b[n - 1][n - 1] % 2 == 0)
		return false;
	dfs(0, 0);
	if (markd[n - 1][n - 1])
		return true;
	return false;
}

bool isA (int x)
{
	for (int i = 0; i < n; i++)
		if (mark[i][b[x][i]])
			return false;
	return true;
}

void chM (int x, bool y)
{
	for (int i = 0; i < n; i++)
		mark[i][b[x][i]] = y;
}

void BT(int x)
{
	if (x == n)
	{
		if (isR())
			cnt++;
		return;
	}
	
	for (int i = 0; i < n; i++)
		b[x][i] = a[i];
	
	do 
	{
		if (!isA(x))
			continue;
		chM(x, 1);
		BT(x + 1);
		chM(x, 0);
	} while (next_permutation(b[x], b[x] + n));
}

int main()
{
	BT(0);
	cout << cnt << endl;
	return 0;
}