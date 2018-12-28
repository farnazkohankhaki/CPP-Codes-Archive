/*
 ID: fkohank1
 PROG: prefix
 LANG: C++
 */

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("prefix.in");
ofstream fout ("prefix.out");

const int MAXN = 200 * 1000 + 1000, MAXS = 200 + 10;

string s, p[MAXS];
bool d[MAXN];
int t;

void input ()
{
	for (t = 0; ; t++)
	{
		fin >> p[t];
		if (p[t] == ".")
			break;
	}
	string c;
	while (fin >> c)
		s += c;
}

bool isP (int ind, int q)
{
	for (int i = 0; i < p[q].size(); i++)
		if (s[ind - p[q].size() + i] != p[q][i])
			return false;
	return true;
}

void build ()
{
	d[0] = true;
	for (int i = 1; i <= s.size(); i++)
		for (int j = 0; j < t; j++)
			if (p[j].size() <= i && d[i - p[j].size()] && isP (i, j))
				d[i] = true;
}

void output ()
{
	for (int i = s.size(); i >= 0; i--)
		if (d[i])
		{
			fout << i << endl;
			break;
		}
}

int main ()
{
	input();
	build();
	output();
	return 0;
}