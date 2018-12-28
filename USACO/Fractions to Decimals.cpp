/*
 ID: fkohan1
 PROG: fracdec
 LANG: C++
 */

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("fracdec.in");
ofstream fout ("fracdec.out");

const int MAXN = 100000 + 1000;

int n, d, mark[MAXN][2];
string ans, Dec;

void makeInt (int k)
{
	string r;
	if (k == 0)
		ans += '0';
	while (k > 0)
	{
		r += k % 10 + '0';
		k /= 10;
	}
	for (int i = r.size() - 1; i >= 0; i--)
		ans += r[i];
}

int findDec (int x)
{
	int cnt = 0, y = x;
	while (mark[y][0] == 0)
	{
		mark[y][0] = 1;
		mark[y][1] = cnt;
		cnt++;
		y *= 10;
		Dec += y / d + '0';
		y %= d;
	}
	return y;
}

void makeDec (int x)
{
	int p = findDec (x);
	for (int i = 0; i < mark[p][1]; i++)
		ans += Dec[i];
	if (p == 0)
	{
		if (ans[ans.size() - 1] == '.')
			ans += '0';
		return;
	}
	ans += '(';
	for (int i = mark[p][1]; i < Dec.size(); i++)
		ans += Dec[i];
	ans += ')';
}
	
void findAns ()
{
	int k = n / d;
	makeInt (k);
	ans += '.';
	int de = n % d;
	makeDec (de);
}

void output ()
{
	for (int i = 0; i < ans.size(); i++)
	{
		if (i > 0 && i % 76 == 0)
			fout << endl;
		fout << ans[i];
	}
	fout << endl;
}

int main ()
{
	fin >> n >> d;
	findAns ();
	output ();
}