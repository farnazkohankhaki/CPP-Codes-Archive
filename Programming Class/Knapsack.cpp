#include <iostream>

using namespace std;

const int maxN = 100 + 10, maxV = 100 + 10;

int n, v, w[maxN], p[maxN], d[maxN][maxV];
bool f[maxN][maxV];

void dyna() 
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= v; j++) 
		{
			d[i][j] = d[i - 1][j];
			if (w[i] <= j && d[i - 1][j - w[i]] + p[i] > d[i][j])
			{
				d[i][j] = d[i - 1][j - w[i]] + p[i];
				f[i][j] = true;
			}
		}
}
void output ()
{
	cout << d[n][v] << endl;
	if (d[n][v] == 0)
		return;
	int p1 = n, p2 = v;
	while (p2 != 0)
	{
		if (!f[p1][p2])
			p1--;
		else
		{
			p2 -= w[p1];
			cout << p1-- << " ";
		}
	}
	cout << endl;
}

int main()
{
	cin >> n >> v;
	for (int i = 1; i <= n; i++)
		cin >> p[i] >> w[i];
	dyna();
	output();
	return 0;
}