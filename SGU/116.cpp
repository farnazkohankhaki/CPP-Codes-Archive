#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 10000 + 100;

bool mark[maxN];
int n, d[maxN], par[maxN];
vector <int> sprm, ans;

void prime ()
{
	mark[1] = true;
	int cnt = 0;
	for (int i = 2; i <= n; i++)
		if (!mark[i])
		{
			cnt++;
			if (!mark[cnt])
				sprm.push_back(i);
			for (int j = 2; j <= n / i; j++)
				mark[i * j] = true;
		}
}

void dyna ()
{
	for (int i = 1; i <= n; i++)
	{
		d[i] = 800000;
		for (int j = 0; j < sprm.size(); j++)
			if (i - sprm[j] >= 0 && d[i - sprm[j]] + 1 < d[i])
			{
				d[i] = d[i - sprm[j]] + 1;
				par[i] = i - sprm[j];
			}
	}
}

void output ()
{
	if (d[n] == 800000)
	{
		cout << 0 << endl;
		return;
	}
	cout << d[n] << endl;
	int p = n;
	for (int i = 0; i < d[n]; i++)
	{
		ans.push_back(p - par[p]);
		p = par[p];
	}
	sort (ans.begin(), ans.end());
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << " ";
	cout << endl;
}

int main ()
{
	cin >> n;
	prime ();
	dyna ();
	output ();
	return 0;
}