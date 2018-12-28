#include <iostream>

using namespace std;

const int maxN = 100 + 8;

string s[maxN];
bool mark[maxN][maxN] = {{0}};

int main()
{
	int n, m, ptx, pty, py, px, a;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> s[i];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == 'P')
			{
				ptx = i;
				pty = j;
				break;
			}
	px = ptx + 1;
	py = pty;
	
	while (px != n  && py >= 0 && py < m)
	{
		if (mark[px][py])
			break;
		mark[px][py] = 1;
		if (s[px][py] == '/')
			a = 0;
		if (s[px][py] == '\\')
			a = 1;
		if (s[px][py] == '.')
			a = 2;
		if (a == 0)
		{
			py--;
			if (s[px][py] == '/')
				px++;
		}
		if (a == 1)
		{
			py++;
			if (s[px][py] == '\\')
				px++;
		}
		if (a == 2)
			px++;
	}
	if (px == n)
		cout << py + 1 << endl;
	else
		cout << -1 << endl;
	return 0;
}