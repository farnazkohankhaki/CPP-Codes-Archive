#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxM = 1000000+8;

bool mark[maxM] = {0};

int a, b, la, lb, sa = 0, sb = 0;

void prime (int x)
{
	for (int i = 2; i <= sqrt (x); i++)
		if (mark[i] == 0)

			for (int j = 2; j <= x/i; j++)
				mark[i*j] = 1;
}

int main()
{
	cin >> a >> b;
	prime (max (a, b));
	for (int i = 2; i <= max (a, b); i++)
	{
		if (!mark[i] && a % i == 0)
		{
			la = i;
			sa += i;
		}
		if (!mark[i] && b % i == 0)
		{
			lb = i;
			sb += i;
		}
	}
	sa = la - sa + la;
	sb = lb - sb + lb;
	if (sa > sb)
		cout << "a" << endl;
	else
		cout << "b" << endl;
	return 0;
}