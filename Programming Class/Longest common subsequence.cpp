#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1000 + 100;

int n, m, sn[maxN], sm[maxN], d[maxN][maxN], par[maxN][maxN];
vector <int> ans;

void dyna()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (sn[i] == sm[j])
				d[i][j] = d[i - 1][j - 1] + 1;
			else if (d[i - 1][j] > d[i][j - 1])
			{
				d[i][j] = d[i - 1][j];
				par[i][j] = 1;
			}
			else
			{
				d[i][j] = d[i][j - 1];
				par[i][j] = 2;
			}
		}
}
void output()
{
	cout << d[n][m] << endl;
	int p1 = n, p2 = m;
	while (p1 > 0 && p2 > 0)
	{
		if (par[p1][p2] == 0)
		{
			ans.push_back(sn[p1]);
			p1--;
			p2--;
		}
		else if (par[p1][p2] == 1)
			p1--;
		else
			p2--;
	}
	for (int i =  ans.size() - 1; i >= 0; i--)
		cout << ans[i] << " ";
	cout << endl;
}
	
int main ()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> sn[i];
	for (int i = 1; i <= m; i++)
		cin >> sm[i];
	dyna();
	output();
	return 0;
}