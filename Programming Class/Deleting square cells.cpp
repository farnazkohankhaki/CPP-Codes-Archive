#include <iostream>

using namespace std;

const int maxN = 1000 + 100;

int n, m, k, mark[maxN][maxN];

struct Counter 
{
	int cnt;
	int dir;
	void plus ()
	{
		cnt = (cnt + 1) % (n * m);
		if (cnt == 0)
			dir = (dir +1) % 2;
	}
	int getx ()
	{
		if (!dir)
			return cnt / m;
		else
			return cnt % n;
	}
	int gety ()
	{
		if (!dir)
			return cnt % m;
		else
			return cnt / n;
	}
} ind;

int main ()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mark[i][j] = 1;
	ind.dir = 1;
	ind.cnt = n * m - 1;
	for (int i = 1; i < n * m; i++)
	{
		int t = 0;	
		while (t != k)
		{
			ind.plus();
			t += mark[ind.getx()][ind.gety()];
		}
		mark[ind.getx()][ind.gety()] = 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (mark[i][j])
			{
				cout << i + 1 << " , " << j + 1 << endl;
				break;
			}
	return 0;
}