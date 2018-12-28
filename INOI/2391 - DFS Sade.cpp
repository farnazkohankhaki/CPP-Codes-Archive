#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1000 + 8;

vector <int> v[maxN];
int n, m;
bool mark[maxN] = {0};

void DFS (int t)
{
	mark[t] = 1;
	cout << t << " ";
	for (int i = 0; i < v[t].size(); i++)
	{
		if (!mark[v[t][i]])
			DFS(v[t][i]);
	}
}

int main()
{
	int h, g;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> h >> g;
		v[h].push_back(g);
		v[g].push_back(h);
	}
	for (int i = 1; i <= n; i++)
		if (!mark[i])
		{
			DFS(i);
			cout << endl;
		}
	return 0;
}