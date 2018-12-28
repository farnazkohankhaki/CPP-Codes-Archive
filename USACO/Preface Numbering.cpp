/*
 ID: fkohank1
 PROG: preface
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin ("preface.in");
ofstream fout ("preface.out");

const int maxS = 7 + 3;

int s[maxS] = {0};

void f (int x)
{
	int t;
	for (int i = 0; i < 4; i++)
	{
		t = x % 10;
		if (t == 1 || t == 2 || t == 3)
			s[i * 2] += t;
		if (t == 4)
		{
			s[i * 2]++;
			s[i * 2 + 1]++;
		}
		if (t == 5 || t == 6 || t == 7 || t == 8)
		{
			s[i * 2 + 1]++;
			s[i * 2] += t - 5;
		}
		if (t == 9)
		{
			s[i * 2]++;
			s[i * 2 + 2]++;
		}
		x /= 10;
	}
}

int main()
{
	int n;
	fin >> n;
	for (int i = 1; i <= n; i++)
		f (i);
	for (int i = 0; i < 7; i++)
		if (s[i] > 0)
		{
			if (i == 0)
				fout << "I " << s[i] << endl;
			if (i == 1)
				fout << "V " << s[i] << endl;
			if (i == 2)
				fout << "X " << s[i] << endl;
			if (i == 3)
				fout << "L " << s[i] << endl;
			if (i == 4)
				fout << "C " << s[i] << endl;
			if (i == 5)
				fout << "D " << s[i] << endl;
			if (i == 6)
				fout << "M " << s[i] << endl;
		}
	return 0;
}
