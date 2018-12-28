#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200 * 1000 + 100;

struct bank
{
	int x, ind, w;
	bool operator < (const bank &a) const
	{
		return x < a.x;
	}
}b[MAXN];

int b1, b2, n, d;

void findBanks()
{
	sort(b, b + n);
	int p = 0, maxa = 0, ans = 0, maxind = 0;
	for (int i = 1; i < n; i++)
	{
		while (b[i].x - b[p].x >= d)
		{
			if (maxa < b[p].w)
			{
				maxa = b[p].w;
				maxind = b[p].ind;
			}
			p++;
		}
		if (maxa == 0)
			continue;
		if (maxa + b[i].w > ans)
		{
			ans = maxa + b[i].w;
			b1 = maxind + 1;
			b2 = i + 1;
		}
	}
	if (ans == 0)
		b1 = b2 = -1;
}

int main()
{	
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{

		cin >> b[i].x >> b[i].w;
		b[i].ind = i;
	}
	findBanks();
	cout << b1 << " " << b2 << endl;
	return 0;
}