#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 1000000 + 100000;

int n = 1000000;
bool mark[MAXN], cp[MAXN];

void findPrime ()
{
	mark[0] = mark[1] = true;
	for (int i = 2; i <= sqrt (n); i++)
		if (!mark[i])
			for (int j = 2; i * j < n; j++)
				mark[i * j] = true;
}

string st (int x)
{
	string s, r;
	while (x > 0)
	{
		r += x % 10 + '0';
		x /= 10;
	}
	for (int i = r.size() - 1; i >= 0; i--)
		s += r[i];
	return s;
}

int it (string s, int p)
{
	int r = 0, t = 1;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		int y = (i + p) % s.size();
		r += (s[y] - '0') * t;
		t *= 10;
	}
	return r;
}

bool isCP (int x)
{
	string s = st (x);
	for (int i = 1; i < s.size(); i++)
	{
		int y = it (s, i);
		if (mark[y])
			return false;
	}
	return true;
}

void findCPrime ()
{
	for (int i = 1; i < n; i++)
		if (!mark[i] && isCP (i))
			cp[i] = true;
}

void output ()
{
	int r = 0;
	for (int i = 1; i < n; i++)
		if (cp[i])
			r++;
	cout << r << endl;
}

int main ()
{
	findPrime();
	findCPrime();
	output();
	return 0;
}