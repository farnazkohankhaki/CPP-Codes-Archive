#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1000 + 8, maxE = 10000 + 8;
const long long INF = 1ll << 32;

int n, e, s;
long long dis[maxN];

struct edge 
{
	int u, v, w;
} ed[maxE];

void input()
{
	cin >> n;
	e = n;
	for (int i = 0; i < n; i++)
		cin >> ed[i].v >> ed[i].u >> ed[i].w;
}

void init()
{
	for (int i = 0; i < n; i++)
		dis[i] = INF;
	dis[s] = 0;
}

void bellmanFord()
{
	for (int l = 0; l < n - 1; l++)
		for (int i = 0; i < e; i++)
			if (dis[ed[i].u] + ed[i].w < dis[ed[i].v])
				dis[ed[i].v] = dis[ed[i].u] + ed[i].w;
}

bool isNC()
{
	for (int i = 0; i < e; i++)
		if (dis[ed[i].u] + ed[i].w < dis[ed[i].v] && dis[ed[i].u] < INF)
			return true;
	return false;
}

void output()
{
	if (isNC())
	{
		cout << "no soulution" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
		cout << dis[i] << " ";
	cout << endl;
}

int main()
{
	input();
	init();
	bellmanFord();
	output();
	return 0;
}