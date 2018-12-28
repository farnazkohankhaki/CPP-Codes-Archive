#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int n, x[MAXN], h[MAXN], y[MAXN];

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> h[i] >> y[i];
}

vector <int> init (int s)
{
	vector <int> r;
	r.push_back(0);
	r.push_back(x[s]);
	r.push_back(h[s]);
	r.push_back(y[s]);
	r.push_back(0);
	return r;
}

vector <int> merge (vector <int> r1, vector <int> r2)
{
	int p1 = 1, p2 = 1, lh = 0;
	bool d = 0;
	vector <int> r;
	r.push_back(0);
	while (p1 + 1 < r1.size() && p2 + 1 < r2.size())
	{
		if (r1[p1] < r2[p2])
		{
			if (r1[p1 + 1] != lh)
			{
				r.push_back(r1[p1]);
				r.push_back(r1[p1 + 1]);
				lh = r1[p1 + 1];
				while (r1[p1 + 1] > r2[p2 + 1] && r1[p1 + 2] > r2[p2])
				{
					p2 += 2;
					if (p2 + 1 >= r2.size())
					{
						for (int i = p1 + 2; i < r1.size(); i++)
							r.push_back(r1[i]);
						d = 1;
						break;
					}
				}
			}
			p1 += 2;
		}
		else if (r1[p1] > r2[p2])
		{
			if (r2[p2 + 1] != lh)
			{
				r.push_back(r2[p2]);
				r.push_back(r2[p2 + 1]);
				lh = r2[p2 + 1];
				while (r2[p2 + 1] > r1[p1 + 1] && r1[p1] < r2[p2 + 2])
				{
					p1 += 2;
					if (p1 + 1 >= r1.size())
					{
						for (int i = p2 + 2; i < r2.size(); i++)
							r.push_back(r2[i]);
						d = 1;
						break;
					}
				}
			}
			p2 += 2;
		}
		else
		{
			int tmp = max (r1[p1 + 1], r2[p2 + 1]);
			if (tmp != lh)
			{
				r.push_back(r1[p1]);
				r.push_back(tmp);
				lh = tmp;
			}
			p2 += 2;
			p1 += 2;
		}
	}
	if (p2 + 1 >= r2.size())
		swap (r1, r2);
	if (!d)
		for (int i = p2; i < r2.size(); i++)
			r.push_back(r2[i]);
	return r;
}

vector <int> findView(int s, int f)
{
	vector <int> r;
	if (s + 1 == f)
	{
		r = init(s);
		return r;
	}
	int m = (s + f) / 2;
	vector <int> r1, r2;
	r1 = findView(s, m);
	r2 = findView(m, f);
	r = merge(r1, r2);
	return r;
}

int main()
{
	input();
	vector <int> ans = findView(0, n);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}