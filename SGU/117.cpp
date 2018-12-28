#include <iostream>
#include <vector>

using namespace std;

const int maxN = 10000 + 8;

int a[maxN];
bool mark[maxN] = {0};
vector <int> p;
pair <int, int> pr[maxN];

void prime (int x)
{
	p.clear();
	for (int i = 2; i <= x; i++)
		if (!mark[i])
		{
			p.push_back(i);
			for (int j = 2; j <= x / i; j++)
				mark[i * j] = 1;
		}
}

int main()
{
	int n, m, k, c = 0, r = 0, tmp;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	prime (k);
	for (int i = 0; i < p.size(); i++)
	{
		if (k % p[i] == 0)
		{
			tmp = 0;
			while (k % p[i] == 0)
			{
				k /= p[i];
				tmp++;
			}
			pr[c].first = p[i];
			pr[c].second = tmp;
			c++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		bool chk = 1;
		for (int j = 0; j < c; j++)
		{
			tmp = 0;
			while (a[i] % pr[j].first == 0)
			{
				tmp++;
				a[i] /= pr[j].first;
			}
			if (tmp * m < pr[j].second)
				chk = 0;
		}
		if (chk)
			r++;			 
	}
	cout << r << endl;
	return 0;
}
