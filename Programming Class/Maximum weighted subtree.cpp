#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1000 + 100;

int n, d[maxN], w[maxN];
vector <int> ch[maxN];

void dfs (int v)
{
	d[v] = w[v];
	for (int i = 0; i < ch[v].size(); i++)
	{
		int u = ch[v][i];
		dfs (u);
		d[v] += d[u];
	}
}

int main ()
{
	cin >> n;
	int r, par;
	for (int i = 0; i < n; i++)
	{
		cin >> par >> w[i] ;
		if(par == 0)
			r = i;
		else
		{
			par--;
			ch[par].push_back(i);
		}
	}
	
	dfs(r);
	
	int ans = 0;
	for (int i = 1; i < n; i++)
		if (d[i] > d[ans])
			ans = i;
	
	cout << ans + 1  << " " << d[ans] << endl;
	
	return 0;
}