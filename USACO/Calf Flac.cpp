/*
 ID: fkohank1
 PROG: calfflac
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("calfflac.in");
ofstream fout("calfflac.out");

const int maxN = 20000 + 8;

int makan[maxN];

int main()
{
	bool ch, p, t;
	char o;
	string s = "", f = "", c;
	int n, a, mak = 0, lan = 0, pan;
	
	while (getline (fin, c))
	{
		s += c;
		s += '\n';
	}
	
	n = s.size();
	
	for (int i = 0; i < n; i++)
	{
		a = s[i];
		if (a >= 65 && a <= 90)
		{
			o = a;
			f += o;
			makan[mak] = i;
			mak++;
		}
		if (a >= 97 && a <= 122)
		{
			o = a - 32;
			f += o;
			makan[mak] = i;
			mak++;
		}
	}
	
	for (int i = 0; i < mak; i++)
	{
		p = 1;
		t = 1;
		for (int j = 0; j <= 1001; j++)
		{
			if (p && (i + j) < mak && (i - j) >= 0)
			{
				if (f[i + j] == f[i - j])
				{
					if (lan < (2 * j + 1))
					{
						lan = 2 * j + 1;
						pan = i - j;
					}
				}
				else
					p = 0;
			}
			if (t && (i - j) >= 0 && (i + j + 1) < mak)
			{
				if (f[i - j] == f[i + j + 1])
				{
					if (lan < (2 * j))
					{
						lan = 2 * (j + 1);
						pan = i - j;
					}
				}
				else
					t = 0;
			}
		}
	}
	fout << lan << endl;
	for (int i = makan[pan]; i <= makan[pan + lan - 1]; i++)
		fout << s[i];
	fout << endl;
	return 0;
}