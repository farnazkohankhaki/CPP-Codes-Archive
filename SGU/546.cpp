#include <iostream>
#include <cmath>

using namespace std;

int n, a[3], b[3];
string t, s;

void findXYZ()
{
	for (int i = 0; i < n; i++)
		if (t[i] == '0')
			b[0]++;
		else if (t[i] == '1')
			b[1]++;
		else
			b[2]++;
}

void del(int x)
{
	int h = b[x] - a[x], cnt = 0;
	for (int i = 0; i < n && cnt < h; i++)
		if (t[i] == x + '0')
		{
			t[i] = '3';
			cnt++;
		}
}

void add(int x)
{
	int h = a[x] - b[x], cnt = 0;
	for (int i = 0; i < n && cnt < h; i++)
		if (t[i] == '3')
		{
			t[i] = x + '0';
			cnt++;
		}
}

int findT()
{
	int r = 0;
	for (int i = 0; i < n; i++)
		if (s[i] != t[i])
			r++;
	return r;
}

void output()
{
	if (a[0] + a[1] > n)
	{
		cout << -1 << endl;
		return;
	}
	for (int i = 0; i < 3; i++)
		if (a[i] < b[i])
			del(i);
	
	for (int i = 0; i < 3; i++)
		if (a[i] > b[i])
			add(i);
	
	cout << findT() << endl << t << endl;
}

int main()
{
	cin >> n >> a[0] >> a[1];
	cin >> t;
	s = t;
	
	a[2] = n - a[0] - a[1];
	findXYZ();
	output();
	
	return 0;
}