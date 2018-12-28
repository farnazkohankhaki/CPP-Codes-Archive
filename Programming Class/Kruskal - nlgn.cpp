#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 10, MAXE = 10000 + 1000;

struct Edge 
{
	int u, v, w;
	bool operator < (const Edge &x) const
	{
		if (w < x.w)
			return 1;
		else
			return 0;
	}
} edge[MAXE];

int n, e, mst, d[MAXN], ncmp[MAXN];
vector <int> comp[MAXN];
vector <Edge> ans;

void input ()
{
	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
		edge[i].u--;
		edge[i].v--;
	}
}

void init ()
{
	for (int i = 0; i < n; i++)
	{
		ncmp[i] = i;
		comp[i].push_back (i);
	}
}

void merge (int x, int y)
{
	for (int i = 0; i < comp[y].size(); i++)
	{
		int u = comp[y][i];
		comp[x].push_back(u);
		ncmp[u] = x;
	}
}

void kruskal ()
{
	sort (edge, edge + e);
	for (int i = 0; i < e; i++)
	{
		int u = edge[i].u, v = edge[i].v;
		if (ncmp[u] != ncmp[v])
		{
			ans.push_back(edge[i]);
			mst += edge[i].w;
			int cu = ncmp[u], cv = ncmp[v];
			if (comp[cu].size() > comp[cv].size())
				merge (cu, cv);
			else
				merge (cv, cu);
		}
	}
}

void output ()
{
	for (int i = 1; i < n; i++)
		if (ncmp[i] != ncmp[0])
		{
			cout << "NOT CONNECTED" << endl;
			return;
		}
	cout << mst << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].u + 1 << " , " << ans[i].v + 1 << endl;
}

int main ()
{
	input ();
	init ();
	kruskal ();
	output ();
	return 0;
}