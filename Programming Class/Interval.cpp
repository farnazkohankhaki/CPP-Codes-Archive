#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1000 + 100;
int n;

struct baze 
{
	int s, f, d, ind, par;
	bool operator < (const baze &x) const
	{
		if (s < x.s)
			return 1;
		else
			return 0;
	}
} b[maxN];

void fill()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (b[i].s > b[j].f && b[i].d < b[j].d + 1)
			{
				b[i].d = b[j].d + 1;
				b[i].par = j;
			}
}

void output()
{
	int maxi = 0;
	for (int i = 1; i < n; i++)
		if (b[i].d > b[maxi].d)
			maxi = i;
	cout << b[maxi].d << endl;
	while (b[maxi].par != -1)
	{
		cout << b[maxi].ind + 1 << " ";
		maxi = b[maxi].par;
	}
	cout << b[maxi].ind + 1 << endl;
}

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i].s >> b[i].f;
		b[i].ind = i;
		b[i].par = -1;
		b[i].d = 1;
	}
	sort (b, b + n);
	fill();
	output();
	return 0;
}