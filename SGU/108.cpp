#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10, MAXK = 5000 + 500;

int n, k, cnt, pcnt, ans[MAXK];
bool p1, p2 = 1, d[2][MAXN];
pair <int, int> s[MAXK];

void input ()
{
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> s[i].first;
		s[i].second = i;
	}
	sort (s, s + k);
}

int findD (int x)
{
	int r = x;
	while (x > 0)
	{
		r += x % 10;
		x /= 10;
	}
	return r;
}

void findG ()
{
	int g = 100, f = (g + n - 1) / g;
	
	for (int i = 0; i < f; i++)
	{
		for (int j = 1; j <= g; j++)
		{
			int x = j + g * i, y = findD (x);
			y -= g * i;
			if (y <= g)
				d[p1][y] = true;
			else
				d[p2][y - g] = true;
		}
		for (int j = 1; j <= g; j++)
		{
			if (!d[p1][j] && j + i * g <= n)
			{
				cnt++;
				while (s[pcnt].first == cnt)
				{
					ans[s[pcnt].second] = j + i * g;

					pcnt++;
				}
			}
			d[p1][j] = false;
		}
		swap (p1, p2);
	}
		
}

void output ()
{
	cout << cnt << endl;
	for (int i = 0; i < k; i++)
		cout << ans[i] << " ";
	cout << endl;
}

int main ()
{
	input();
	findG();
	output();
	return 0;
}