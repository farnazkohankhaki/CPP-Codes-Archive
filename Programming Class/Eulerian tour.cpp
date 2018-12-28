#include <iostream>

using namespace std;

const int MAXN = 1000 + 100, MAXE = 100000 + 10000;

int n, m, adj[MAXN][MAXN], st[MAXN], et[MAXE], etl;

void input()
{
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u][v]++;
		adj[v][u]++;
	}
}

void dfsEulerian(int v)
{
	for (; st[v] < n; st[v]++)
		if (adj[v][st[v]])
		{
			adj[v][st[v]]--;
			adj[st[v]][v]--;
			dfsEulerian(st[v]);
		}
	et[etl++] = v;
}

void eulerianTour()
{
	dfsEulerian(0);
}

bool isEulerian()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (adj[i][j])
				return false;
	return true;
}

void output()
{
	if (isEulerian())
		for (int i = 0; i < etl; i++)
			cout << et[i] << " ";
	else
		cout << "NOT EULERIAN" << endl;
}

int main()
{
	input();
	eulerianTour();
	output();
	return 0;
}