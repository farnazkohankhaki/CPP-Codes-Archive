#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 1000;

int t, n, d[30], a = 26;
string s[MAXN];

void init()
{
	for (int i = 0; i < a; i++)
		d[i] = 0;
}

void dyna()
{
	for (int i = 0; i < n; i++)
	{
		int x = s[i][0] - 'A', y = s[i][s[i].size() - 1] - 'A';
		d[y] = max (d[y], d[x] + 1);
	}
}

int main ()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> s[j];
		
		init();
		dyna();
		cout << *max_element (d, d + a) << endl;
	}
	return 0;
}