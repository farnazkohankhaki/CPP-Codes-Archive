#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1000 + 100;

bool mark[maxN] = {0};
vector <int> adj[maxN], com[maxN];
int n, e, cnt = 0;

void DFS(int x)
{
	mark[x] = true;
	com[cnt].push_back(x);
	for (int i = 0; i < adj[x].size(); i++)
		if (!mark[adj[x][i]])
			DFS (adj[x][i]);			
}

void dfsAll() 
{
	for (int i = 0; i < n; i++)
		if (!mark[i])
		{
			DFS (i);
			cnt++;
		}
}	

void output() 
{
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
	{
		cout << com[i].size();
		for (int j = 0; j < com[i].size(); j++)
			cout << " " << com[i][j] + 1;
		cout << endl;
	}
}

int main ()
{
	cin >> n >> e;
	for (int i = 0; i < n; i++)
	{
		adj[i].clear();
		com[i].clear();
	}
	
	for (int v, u, i = 0; i < e; i++)
	{
		cin >> v >> u;
		adj[v - 1].push_back(u - 1);
		adj[u - 1].push_back(v - 1);
	}
	
	dfsAll();
	output();

	return 0;
}