/*
 ID: fkohank1
 PROG: contact
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

ifstream fin ("contact.in");
ofstream fout ("contact.out");

const int MAXN = 600000 + 600;

int a, b, n, m;
string s;

struct freq
{
	int fi, ind;
	bool operator < (const freq &x) const
	{
		if (fi <= x.fi)
			return false;
		else
			return true;
	}
} f[MAXN];

void input ()
{
	fin >> a >> b >> n;
	m = pow (3.0, (double) b);
	string t;
	getline (fin, t);
	while (getline (fin, t))
		s += t;
}

void init ()
{
	for (int i = 0; i < m; i++)
		f[i].ind = i;
}

void findF (int x, int y)
{
	if (x - y < -1)
		return;
	y--;
	int r = 0;
	for (int i = x - y; i <= x; i++)
	{
		r *= 3;
		r += s[i] - '0' + 1;
	}
	f[r].fi++;
}

void findFre ()
{
	init();
	for (int i = 0; i < s.size(); i++)
		for (int j = a; j <= b; j++)
			findF (i, j);
}

string makeBi (int x)
{
	string r, t;
	while (x > 0)
	{
		t += x % 3 + '0' - 1;
		x /= 3;
	}
	for (int i = t.size() - 1; i >= 0; i--)
		r += t[i];
	return r;
}

void output ()
{
	vector <int> out;
	sort (f, f + m);
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		out.clear();
		if (f[j].fi == 0)
			break;
		fout << f[j].fi << endl;
		out.push_back (f[j].ind);
		while (f[j + 1].fi == f[j].fi && j < m)
		{
			j++;
			out.push_back (f[j].ind);
		}
		j++;
		sort (out.begin(), out.end());
		for (int l = 0; l < out.size(); l++)
		{
			if (l % 6 != 0)
				fout << " ";
			fout << makeBi (out[l]);
			if (l % 6 == 5 || l == out.size() - 1)
				fout << endl;
		}
	}
}

int main ()
{
	input ();
	findFre ();
	output ();
	return 0;
}