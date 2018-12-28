#include <iostream>

using namespace std;

const int MAXN = 10000 + 1000;

long long a0, a, b, g, m, k, t[MAXN], r[MAXN];

void init ()
{
	for (int i = 0; i < MAXN; i++)
		t[i] = (a * i * i + b * i + g) % m;
}

int main ()
{
	cin >> a0 >> a >> b >> g >> m >> k;
	
	init();
	
	while (k > 0)
	{
		if (r[a0])
		{
			int x = r[a0] - k;
			k %= x;
			for (int i = 0; i < MAXN; i++)
				r[i] = 0;
			if (k == 0)
				break;
		}
		r[a0] = k;
		a0 = t[a0];
		k--;
	}
	
	cout << a0 << endl;
	
	return 0;
}