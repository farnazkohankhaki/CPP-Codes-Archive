#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int maxN = 1000 + 8, maxV = 1000000 + 8, INF = 2 << 25;

long long n, arr[maxV], dis[maxV];
vector <int> h[maxV];

struct cmp 
{
	bool operator () (const int a, const int b) const
	{
		if (dis[a] != dis[b])
			return (dis[a] < dis[b]);
		else
			return (a < b);
	}
};

set <int, cmp> s;

int main()
{
	char t;
	int tmp, x;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[(i - 1) * n + j];
			dis[(i - 1) * n + j] = INF;
			if (j != n)
				cin >> t;
		}
	dis[1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		h[i].push_back (i - 1);
		h[i - 1].push_back (i);
	}
	for (int i = 2; i <= n; i++)
	{
		h[(i - 2)* n + 1].push_back((i - 1) * n + 1);
		h[(i - 1) * n + 1].push_back ((i - 2) * n + 1);
	}
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= n; j++)
		{
			h[(i - 1) * n + j].push_back((i - 1) * n + j - 1);
			h[(i - 1) * n + j - 1].push_back((i - 1) * n + j);
			h[(i - 1) * n + j].push_back((i - 2) * n + j);
			h[(i - 2) * n + j].push_back((i - 1) * n + j);
		}
	for (int i = 1; i <= n * n; i++)
		s.insert (i);
	for (int i = 0; i < n * n; i++)
	{
		x = *s.begin();
		for (int j = 0; j < h[x].size(); j++)
			if (dis[x] + arr[h[x][j]] < dis[h[x][j]])
			{
				s.erase (h[x][j]);
				dis[h[x][j]] = dis[x] + arr[h[x][j]];
				s.insert (h[x][j]);
			}
		s.erase (x);
	}
	cout << dis [n * n] << endl;
	return 0;
}