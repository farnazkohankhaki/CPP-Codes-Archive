/*
 ID: fkohank1
 PROG: pprime
 LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

ifstream fin ("pprime.in");
ofstream fout ("pprime.out");

vector <int> pal, ans;

int hdi (int x)
{
	int r = 0;
	while (x > 0)
	{
		r++;
		x /= 10;
	}
	return r;
}

void pal1 ()
{
	for (int d1 = 1; d1 <= 9; d1++)
		pal.push_back(d1);
}

void pal2 ()
{
	for (int d1 = 1; d1 <= 9; d1 += 2)
		pal.push_back (d1 * 10 + d1);
}

void pal3 ()
{
	for (int d1 = 1; d1 <= 9; d1 += 2)
		for (int d2 = 0; d2 <= 9; d2++)
			pal.push_back(d1 * 100 + d2 * 10 + d1);
}

void pal4 ()
{
	for (int d1 = 1; d1 <= 9; d1 += 2)
		for (int d2 = 0; d2 <= 9; d2++)
			pal.push_back(d1 * 1000 + d2 * 100 + d2 * 10 + d1);
}

void pal5 ()
{
	for (int d1 = 1; d1 <= 9; d1 += 2)
		for (int d2 = 0; d2 <= 9; d2++)
			for (int d3 = 0; d3 <= 9; d3++)
				pal.push_back(d1*10000 + d2 * 1000 + d3 * 100 + d2 * 10 + d1);
}

void pal6 ()
{
	for (int d1 = 1; d1 <= 9; d1 += 2)
		for (int d2 = 0; d2 <= 9; d2++)
			for (int d3 = 0; d3 <= 9; d3++)
				pal.push_back(d1*100000 + d2 * 10000 + d3 * 1000 + d3 * 100 + d2 * 10 + d1);
	
}

void pal7 ()
{
	for (int d1 = 1; d1 <= 9; d1 += 2)
		for (int d2 = 0; d2 <= 9; d2++)
			for (int d3 = 0; d3 <= 9; d3++)
				for (int d4 = 0; d4 <= 9; d4++)
					pal.push_back(d1 * 1000000 + d2 * 100000 + d3 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1);
}

int main()
{
	int a, b, da, db;
	bool chk;
	fin >> a >> b;
	da = hdi (a);
	db = hdi (b);
	if (da <= 1 && db >= 1)
		pal1();
	if (da <= 2 && db >= 2)
		pal2();
	if (da <= 3 && db >= 3)
		pal3();
	if (da <= 4 && db >= 4)
		pal4();
	if (da <= 5 && db >= 5)
		pal5();
	if (da <= 6 && db >= 6)
		pal6();
	if (da <= 7 && db >= 7)
		pal7();
	for (int i = 0; i < pal.size(); i++)
	{
		chk = 1;
		for (int j = 2; j <= sqrt (pal[i]); j++)
			if (pal[i] % j == 0)
				chk = 0;
		if (chk && pal[i] >= a && pal[i] <= b)
			fout << pal[i] << endl;
	}
	return 0;
}