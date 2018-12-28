#include <iostream>

using namespace std;

const int MAXN = 50 + 5;

bool mark[MAXN][MAXN][MAXN][MAXN];
int n = 50, cnt;

int main()
{
	for (int a = 0; a <= n; a++)
		for (int b = 0; b <= n; b++)
			for (int x = 0; x <= n; x++)
				for (int y = 0; y <= n; y++)
				{
					if (a == x && b == y || a == 0 && b == 0 || y == 0 && x == 0 || mark[a][b][x][y])
						continue;
					if (x * a == -1  * y * b || (x - a) * a == -1 * (y - b) * b || (x - a) * x == -1 * (y - b) * y )
					{
						mark[x][y][a][b] = true;
						cnt++;
					}
				}
	
	cout << cnt << endl;
		
	return 0;
}