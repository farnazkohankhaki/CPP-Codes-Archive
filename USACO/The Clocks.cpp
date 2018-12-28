/*
 ID: fkohank1
 PROG: clocks
 LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin ("clocks.in");
ofstream fout ("clocks.out");

const int H = 262144;

int mv[10] = {0, 1245, 123, 2356, 147, 24568, 369, 4578, 789, 5689}, c[10], nc[10], ans[10], nans[10];

void move (int q)
{
	int p = mv[q];
	while (p > 0)
	{
		nc[(p % 10)] += 3;
		p /= 10;
	}
}

void out () 
{
	vector <int> p;
	for (int i = 1; i <= 9; i++)
		for (int j = 0; j < ans[i]; j++)
			p.push_back(i);
	if (p.size() > 0)
		fout << p[0];
	for (int i = 1; i < p.size(); i++)
		fout << " " << p[i];
}

int main()
{
	int tmp, a, tm = 200, tmm;
	bool chk;
	
	for (int i = 1; i <= 9; i++)
		fin >> c[i]; 
	
	for (int i = 0; i < H; i++)
	{
		chk = 1;
		a = i;
		tmm = 0;
		
		for (int j = 1; j <= 9; j++)
			nc[j] = c[j];
		
		for (int j = 1; j <= 9; j++)
		{
			tmp = a % 4;
			a /= 4;
			nans[j] = tmp;
			tmm += tmp;
			for (int l = 0; l < tmp; l++)
				move (j);
		}
		
		for (int j = 1; j <= 9; j++)
			if (nc[j] % 12 != 0)
				chk = 0;
		
		if (chk && tmm < tm)
		{
			tm = tmm;
			for (int j = 1; j <= 9; j++)
				ans[j] = nans[j];
		}
		
	}
	
	out ();
	
	fout << endl;
	return 0;
}
