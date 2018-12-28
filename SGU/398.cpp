#include <iostream>
#include <vector>

using namespace std;

const int maxN = 50 + 8;

int mark[maxN] = {0};
vector <int> a[maxN];

int main ()
{
	int n, x, d, t, ans = 0;
	cin >> n >> x;
	mark[x] = 1;
	for (int i = 1; i <= n; i++)
	{
		a[i].clear();
		cin >> d;
		for (int j = 0; j < d; j++)
		{
			cin >> t;
			a[i].push_back(t);
			if (i == x)
				mark[t] = 1;
		}
	}
	for (int i = 0; i < a[x].size(); i++)
		for (int j = 0; j < a[a[x][i]].size(); j++)
			if (!mark[a[a[x][i]][j]])
			{
				mark[a[a[x][i]][j]] = 2;
				ans++;
			}
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
		if (mark[i] == 2)
			cout << i << " ";
	cout << endl;
	return 0;
}
