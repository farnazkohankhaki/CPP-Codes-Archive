#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1000 + 8;

int p, q, c[maxN] = {0}, w = 0;
bool mark[maxN] = {0}, yon = 0;
vector <int> m[maxN];

void f (int x)
{
	if (yon)
		return;
	
	bool chk = 1;
	for (int i = 1; i < p; i++)
		if (!mark[i])
			chk = 0;
	if (chk && x == 0)
	{
		yon = 1;
		cout << "YES" << endl;
		cout << "0" << " ";
		for (int i = 0; i < p; i++)
			cout << c[i] << " ";
		cout << endl;
		return;
	}
	for (int i = 0; i < m[x].size(); i++)
	{
		if (!mark[m[x][i]])
		{
			mark[m[x][i]] = 1;
			c[w] = m[x][i];
			w++;
			f (m[x][i]);
			mark[m[x][i]] = 0;
			w--;
			c[w] = 0;
		}
	}
}

int main()
{
	int a, b;
	cin >> p >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> a >> b;
		m[a].push_back (b);
		m[b].push_back (a);
	}
	f (0);
	if (!yon)
		cout << "NO" << endl;
	return 0;
}