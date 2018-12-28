#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200 * 1000 + 100;
const int h[3][6][3] = {{{0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
					    {{0, 1, 0}, {1, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
					    {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}}};
const int hs[3] = {1, 2, 6};
const int hn[3] = {1, 2, 3};

int n, a[MAXN][3];
long long d[MAXN];

void dyna()
{
	for (int i = n - 1; i >= 0; i--)
	{
		d[i] = d[i + 1] + a[i][0];
		for (int j = 0; j < 3; j++)
			for (int l = 0; l < hs[j]; l++)
			{
				long long f = d[i + j + 1];
				for (int k = 0; k < hn[j]; k++)
					f += a[i + k][h[j][l][k]];
				d[i] = min (d[i], f);
			}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	
	dyna();
	
	cout << d[0] << endl;
	
	return 0;
}