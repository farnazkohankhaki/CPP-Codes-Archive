/*
 ID: fkohan1
 PROG: lamps
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 100 + 8;

bool a[maxN];
vector <string> b;
int n, tans = 0;

ifstream fin ("lamps.in");
ofstream fout ("lamps.out");
 
void f1 ()
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
			a[i] = 1;
		else
			a[i] = 0;
	}
}

void f2 ()
{
	for (int i = 0; i < n; i += 2)
	{
		if (a[i] == 0)
			a[i] = 1;
		else
			a[i] = 0;
	}
}

void f3 ()
{
	for (int i = 1; i < n; i += 2)
	{
		if (a[i] == 0)
			a[i] = 1;
		else
			a[i] = 0;
	}
}

void f4 ()
{
	for (int i = 0; i < n; i += 3)
	{
		if (a[i] == 0)
			a[i] = 1;
		else
			a[i] = 0;
	}
}

	
int main()
{
	int c, tmp = 0, q, w, e, r, f;
	vector <int> on, off;
	string tm;
	on.clear();
	off.clear();
	fin >> n >> c;
	while (1)
	{
		fin >> tmp;
		if (tmp == -1)
			break;
		on.push_back (tmp);
	}
	tmp = 0;
	while (1)
	{
		fin >> tmp;
		if (tmp == -1)
			break;
		off.push_back (tmp);
	}
	for (int i = 0; i < 16; i++)
	{
		f = 1;
		for (int j = 0; j < n; j++)
			a[j] = 1;
		q = i % 2;
		w = (i / 2) % 2;
		e = (i / 4) % 2;
		r = (i / 8) % 2;
		if (q == 1)
			f1();
		if (w == 1)
			f2();
		if (e == 1)
			f3();
		if (r == 1)
			f4();
		if ((q + w + e + r) > c || (q + w + e + r) % 2 != c % 2)
			f = 0;
		for (int j = 0; j < on.size(); j++)
			if (!a[on[j] - 1])
				f = 0;
		for (int j = 0; j < off.size(); j++)
			if (a[off[j] - 1])
				f = 0;
		if (f)
		{
			tm.clear();
			for (int j = 0; j < n; j++)
				tm += (a[j] + '0');
			b.push_back (tm);
			tans++;
		}
	}
	sort (b.begin(), b.end());
	if (tans == 0)
		fout << "IMPOSSIBLE" << endl;
	for (int i = 0; i < tans; i++)
	{
		for (int j = 0; j < n; j++)
			fout << b[i][j];
		fout << endl;
	}
	return 0;
}
		
