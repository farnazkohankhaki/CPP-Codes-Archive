#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1000 + 100;

int n, e, d[maxN] = {0}, p[maxN], f[maxN];
vector <int> adj[maxN], q;

void topol ()
{
	int x;
	q.clear();
	for (int i = 0; i < n; i++)
		if (d[i] == 0)
			q.push_back(i);
	for (int i = 0; i < n; i++)
	{
		x = q[i];
		for (int j = 0; j < adj[x].size(); j++)
		{
			d[adj[x][j]]--;
			if (d[adj[x][j]] == 0)
				q.push_back(adj[x][j]);
		}
	}
}
	

int main ()
{
	int tmp1, tmp2, l, ans = -1;
	cin >> n >> e;
	for (int i = 0; i < n; i++)
		adj[i].clear ();
	for (int i = 0; i < e; i++)
	{
		cin >> tmp1 >> tmp2;
		adj[tmp1 - 1].push_back (tmp2 - 1);
		d[tmp2 - 1]++;
	}

	topol ();

	for (int i = n - 1;  i >= 0; i--)
	{
		l = q[i];
		tmp1 = -1;
		tmp2 = n;
		for (int j = 0; j < adj[l].size(); j++)
			if (p[adj[l][j]] > tmp1)
			{
				tmp1 = p[adj[l][j]];
				tmp2 = adj[l][j];
			}
		p[l] = tmp1 + 1;
		f[l] = tmp2;
	}
	for (int i = 0; i < n; i++)
		if (p[i] > ans)
		{
			ans = p[i];
			tmp1 = i;
		}
	cout << ans << endl << tmp1 + 1;
	for (int i = 0; i < ans; i++)
	{
		tmp1 = f[tmp1];
		cout << " " << tmp1 + 1;
	}
	cout << endl;
	return 0;
}