#include <iostream>
#include <queue>
#include <cmath>
#include <map>

#define ll long long

using namespace std;

const int MAXN = 100 * 1000 + 1000;

ll n, m, k, d, f[MAXN], s[MAXN], t[MAXN];
bool mark[MAXN];
queue <ll> q;
map <ll, int> x2index;

void input()
{
	cin >> d >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++)
		cin >> f[i];
}

void init()
{
	for (int i = m; i < m + k; i++)
		f[i] = m - i;
	for (int i = 0; i < m + k; i++)
		x2index[f[i]] = i;
}

bool update(int x, int i, int u)
{
	int y = x + (s[i] - x) * 2;
	if (y >= d)
		return true;
	if (x2index.find(y) != x2index.end())
	{
		int ind = x2index[y];
		if (!mark[ind])
		{
			q.push(ind);
			mark[ind] = true;
			t[ind] = t[u] + 1;
		}
	}
	return false;
}

int bfs()
{
	q.push(m);
	mark[m] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		int x = f[u];
		for (int i = 0; i < n; i++)
			if (abs(x - s[i]) <= k && update(x, i, u))
				return t[u] + 1;
	}
	return -1;
}

int main()
{
	input();
	init();
	cout << bfs() << endl;
	return 0;
}