/*
 ID: fkohan1
 PROG: runround
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin ("runround.in");
ofstream fout ("runround.out");

bool rn (long long x)
{
	int cnt = 0, w;
	bool mark[10] = {0}, r = 1;
	vector <int> s;	
	s.clear();
	while (x > 0)
	{
		s.push_back (x % 10);
		x /= 10;
	}
	w = s.size() - 1;
	mark[0] = 1;
	while (cnt < s.size())
	{
		if (mark[s[w]])
		{
			r = 0;
			break;
		}
		mark[s[w]] = 1;
		cnt++;
		w = (w + s.size() * 9 - s[w]) % s.size();
	}
	if (w != s.size() - 1)
		r = 0;
	return r;
}

int main()
{
	long long m;
	fin >> m;
	while (!rn (m + 1))
		m++;
	fout << m + 1 << endl;
	return 0;
}