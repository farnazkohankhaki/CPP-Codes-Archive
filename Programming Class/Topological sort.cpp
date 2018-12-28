#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxN = 10000+8; 

queue <int> l, q;
vector <int> a[maxN];
int size[maxN];

int tplg(int n)
{
	int s = 0;
	for (int i = 1; i <= n; i++)
		if (size[i] == 0)
		{
			s++;
			l.push(i);
		}
	while (!l.empty()) 
	{
		for (int i = 0; i < a[l.front()].size(); i++)
		{
			size[a[l.front()][i]]--;
			if (size[a[l.front()][i]] == 0)
			{
				l.push(a[l.front()][i]);
				s++;
			}
		}
		q.push(l.front());
		l.pop();
	}
	return s;
}
int main()
{
	int n, m, u, v, r;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		a[u].push_back(v);
		size[v]++;
	}
	r = tplg(n);
	if (r != n)
		cout << "Impossible" << endl;
	else 
		for(int i = 0; i < n; i++)
		{
			cout << q.front();
			q.pop();
		}
	cout << endl;
	return 0;
}