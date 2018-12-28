/*
 ID: fkohank1
 PROG: sprime
 LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

ifstream fin ("sprime.in");
ofstream fout ("sprime.out");

vector <int> m[10], m8;

bool isprm (int x)
{
	bool r = 1;
	for (int i = 2; i <= sqrt (x); i++)
		if (x % i == 0)
			r = 0;
	return r;
}

int main()
{
	
	int n;
	fin >> n;
	for (int i = 1; i <= 9; i++)
		m[i].clear();
	
	m[1].push_back (2);
	for (int i = 3; i <= 7; i+=2)
		m[1].push_back (i);
	
	for (int i = 2; i <= n; i++)
		for (int l = 0; l < m[i - 1].size(); l++)
			for (int j = 1; j <= 9; j+=2)
				if (isprm (m[i - 1][l] * 10 + j))
					m[i].push_back (m[i - 1][l] * 10 + j);
	
	
	for (int i = 0; i < m[n].size(); i++)
		fout << m[n][i] << endl;

	return 0;
}