#include <iostream>

using namespace std;

const int MAXN = 1000 * 1000 + 1000;

string s;
char c[MAXN];
int r[MAXN], l[MAXN], p, i = 1;

void add (char x)
{
	if (x == 'R')
	{
		if (r[p] == -1)
			return;
		p = r[p];
		return;
	}
	if (x == 'L')
	{
		if (l[p] == -1)
			return;
		p = l[p];
		return;
	}
	c[i] = x;
	int y = r[p];
	r[p] = i;
	l[i] = p;
	r[i] = y;
	if (y != -1)
		l[y] = i;
	p = i;
	return;
}

void output ()
{
	int y;
	for (int j = 0; j <= s.size(); j++)
		if (l[j] == -1)
			y = j;
	while (r[y] != -1)
	{
		cout << c[r[y]];
		y = r[y];
		
	}
	cout << endl;
}

int main ()
{
	cin >> s;
	
	l[0] = r[0] = -1;
	for (i; i <= s.size(); i++)
		add(s[i - 1]);
	
	output();
	
	return 0;
}