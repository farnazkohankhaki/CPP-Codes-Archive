#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxN = 100 + 8, INF = -50 * 100 - 1;

int a[maxN][maxN], d[maxN][maxN];

int main()
{
	int f, v, r, tmp, tmp2, tmp3;
	cin >> f >> v;
	vector <int> ans;
	ans.clear();
	for (int i = 0; i < f; i++)
		for (int j = 0; j < v; j++)
			cin >> a[i][j];
	for (int i = 0; i < v; i++)
		d[0][i] = a[0][i]; 
	for (int i = 1; i < f; i++)
		for (int j = 0; j < v; j++)
		{
			tmp = INF;
			for (int l = i - 1; l < j; l++)
				tmp = max (tmp, d[i - 1][l]);
			d[i][j] = tmp + a[i][j];
		}
	r = INF;
	for (int i = f - 1; i < v; i++)
		r = max (r, d[f - 1][i]);
	cout << r << endl;
	tmp = v;
	for (int i = f - 1; i >= 0; i--)
	{
		tmp2 = INF;
		for (int j = i; j < tmp; j++)
			if (d[i][j] > tmp2)
			{
				tmp2 = d[i][j];
				tmp3 = j;
			}
		tmp = tmp3;
		ans.push_back (tmp);
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] + 1 << " ";
	cout << endl;
	return 0;
}