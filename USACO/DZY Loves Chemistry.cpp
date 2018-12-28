#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 50 + 5;

int n, m, numC;
vector <int> r[MAXN];
bool mark[MAXN];

void dfs (int x)
{
	mark[x] = true;
	for (int i = 0; i < r[x].size(); i++)
		if (!mark[r[x][i]])
			dfs(r[x][i]);
	
	return;
}

void dfsAll()
{
	for (int i = 1; i <= n; i++)
		if (!mark[i])
		{
			dfs(i);
			numC++;
		}
	
	return;
}
			
int main ()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		r[x].push_back(y);
		r[y].push_back(x);
	}
	
	dfsAll ();
	double p = n - numC;
	long long ans = pow (2.0, p) ;
	
	cout << ans << endl;

	return 0;
}