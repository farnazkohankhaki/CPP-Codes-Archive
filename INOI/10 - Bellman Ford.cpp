#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1000 + 8, maxE = 10000 + 8;
const long long INF = 1ll << 32;

long long dis[maxN];

struct edge 
{
	int u, v, w;
} ed[maxE];

int main()
{
	bool bad = 0;
	int n, e, s, u, v, w;
	cin >> n >> e >> s;
	for (int i = 0; i < e; i++)
		cin >> ed[i].u >> ed[i].v >> ed[i].w;
	
	for (int i = 1; i <= n; i++)
		dis[i] = INF;
	dis[s] = 0;

	for (int l = 0; l < n - 1; l++)
		for (int i = 0; i < e; i++)
			if (dis[ed[i].u] + ed[i].w < dis[ed[i].v] && dis[ed[i].u] != INF)
				dis[ed[i].v] = dis[ed[i].u] + ed[i].w;
	for (int i = 0; i < e; i++)
		if (dis[ed[i].u] + ed[i].w < dis[ed[i].v] && dis[ed[i].u] < INF)
			bad = 1;
	if (bad)
		cout << "BAD";
	else
		for (int i = 1; i <= n; i++)
			if (dis[i] != INF)
				cout << dis[i] << " ";
			else
				cout << "INF" << " ";
	cout << endl;
	return 0;
}