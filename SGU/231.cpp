#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int maxN = 2000000 + 8, maxA = 10000 + 8;

bool mark[maxN] = {0};
vector <int> p;
int a[maxA];

void prime (int x)
{
	mark[1] = 1;
	for (int i = 2; i <= sqrt (x); i++)
		if (!mark[i])
			for (int j = 2; j <= x / i; j++)
				mark[i * j] = 1;
	for (int i = 1; i <= x; i++)
		if (!mark[i])
			p.push_back(i);
}
							   
int main()
{
	int n, r = 0;
	cin >> n;
	p.clear();
	prime (n);
	for (int i = 0; i < p.size(); i++)
		if (!mark[2 + p[i]] && (2 + p[i]) <= n)
		{
			a[r] = p[i];
			r++;
		}
	cout << r << endl;
	for (int i = 0; i < r; i++)
		cout << 2 << " " << a[i] << endl;
	return 0;
}