#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int n, m, k[MAXN], t[MAXN], tz, in[MAXN], tt[MAXN];
queue <int> q[MAXN];

void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> k[i] >> t[i];
}

void updateQ(int u)
{
	for (int i = 0; i < m; i++)
	{
		int x = u;
		while (!q[i].empty())
		{
			if (in[i] > x)
			{
				in[i]-= x;
				tt[i]-= x;
				break;
			}
			x -= in[i];
			q[i].pop();
			if (q[i].empty())
			{
				in[i] = 0;
				tt[i] = 0;
				break;
			}
			int y = q[i].front();
			tt[i] -= in[i];
			in[i] = t[y];
		}
	}
}

int findQ()
{
	int r = 0;
	for (int i = 1; i < m; i++)
		if (q[i].size() < q[r].size())
			r = i;
	return r;
}

void f()
{
	tz = k[0];
	for (int i = 0; i < n; i++)
	{
		int x = k[i] - tz;
		updateQ(x);
		int y = findQ();
		cout << y + 1 << " " << tt[y] + k[i] + t[i] << endl;
		tz = k[i];
		q[y].push(i);
		if (in[y] == 0)
			in[y] = t[i];
		tt[y]+= t[i];
	}
}

int main()
{
	input();
	f();
	return 0;
}