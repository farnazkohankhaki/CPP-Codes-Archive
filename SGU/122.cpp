#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000 + 100;

int n, par[MAXN], st, fi;
bool mark[MAXN], a[MAXN][MAXN];
string s;

int findNum (int d, int b)
{
	int r = 0;
	for (int i = d; i < b; i++)
	{
		r *= 10;
		r += s[i] - '0';
	}
	return r;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	getline(cin, s);
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		for (int j = 0; j < s.size(); j++)
		{
			int d = j, b = j;
			while (s[b] != ' ' && b != s.size())
				b++;
			j = b;
			int u = findNum(d, b);
			a[i][u - 1] = true;
		}
	}
}
void findC()
{
	if (a[st][fi])
	{
		par[st] = fi;
		return;
	}
	int u = fi, v = fi;
	vector <int> l;
	while (!(a[st][u] && a[fi][par[u]]))
		u = par[u];
	while (v != par[u])
	{
		l.push_back(v);
		v = par[v];
	}
	par[fi] = par[u];
	par[st] = u;
	for (int i = l.size() - 1; i > 0; i--)
		par[l[i]] = l[i - 1];
}

void makeL()
{
	for (int i = 0; i < n; i++)
	{
		if (!a[st][i])
			continue;
		if (!mark[i])
		{
			mark[i] = true;
			par[st] = i;
			st = i;
			par[st] = -1;
			return;
		}
	}	
	for (int i = 0; i < n; i++)
	{
		if (!a[fi][i])
			continue;
		if (!mark[i])
		{
			mark[i] = true;
			par[i] = fi;
			fi = i;
			return;
		}
	}
	
	findC();
	int u, v, s;
		for (int i = 0; i < n; i++)
		if (!mark[i])
			u = i;
	for (int i = 0; i < n; i++)
		if (a[u][i] && mark[i])
			v = i;
	for (int i = 0; i < n; i++)
		if (mark[i] && par[i] == v)
		{
			s = i;
			break;
		}
	mark[u] = true;
	par[u] = v;
	fi = u;
	st = s;
	par[st] = -1;
}

void findH()
{
	for (int i = 0; i < n; i++)
		if (a[0][i])
			fi = i;
	mark[st] = mark[fi] = true;
	par[st] = -1;
	par[fi] = st;
	
	for (int i = 2; i < n; i++)
		makeL();
}

void output()
{
	findC();
	int u = 0;
	cout << 1 << " ";
	u = par[u];
	while (u != 0)
	{
		cout << u + 1 << " ";
		u = par[u];
	}
	cout << 1 << endl;
}

int main()
{
	input();
	findH();
	output();
	return 0;
}