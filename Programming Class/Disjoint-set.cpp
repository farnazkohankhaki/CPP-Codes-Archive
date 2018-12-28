#include <iostream>
#include <cmath>

using namespace std;

const int maxN = 1000 + 8;

int par[maxN] = {0}, size[maxN], p[maxN][2] = {{0}};
int root (int v)
{
	if (par[v] == 0)
		return v;
	int y = par[v];
	par[v] = root (par[v]);
	p[v][0] += p[y][0];
	p[v][1] += p[y][1];
	
	return par[v];
}

int main()
{
	int n ,m, a, b, d, roota, rootb, t[4], pr, k;
	char tmp, c;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		size[i] = 1;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> d >> c;
		roota = root (a);
		rootb = root (b);
		if (roota != rootb)
		{
			if (size[roota] > size[rootb])
			{
				swap (a, b);
				swap (roota, rootb);
			}			
			par[roota] = rootb;
			p[roota][0] = p[b][0] - p[a][0];
			p[roota][1] = p[b][1] - p[a][1];
			if (c == 'n')
				p[roota][0] += d;
			if (c == 'e')
				p[roota][1] += d;
			if (c == 's')
				p[roota][0] -= d;
			if (c == 'w')
				p[roota][1] -= d;
		}
	}
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		roota = root (a);
		rootb = root (b);
		if (roota == rootb)
		{
			pr = abs (p[b][0] - p[a][0]) + abs (p[b][1] - p[a][1]);
			cout << pr << endl;
		}
		else 
			cout << "NO" << endl;
	}
	return 0;
}