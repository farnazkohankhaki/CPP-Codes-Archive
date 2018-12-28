/*
ID: fkohank1
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("frac1.in");
ofstream fout ("frac1.out");

const int maxN = 200 + 8;

bool mark[maxN][maxN] = {{0}};
int p[maxN] = {0};

int main()
{
	int n, min;
	double f, q;
	fin >> n;
	while (!mark[1][1])
	{
		min = 1;
		f = (double)p[1] / (double)1;
		for (int i = 1; i <= n; i++)
		{
			q = (double)p[i] / (double)i;
			if (q < f)
			{
				f = q;
				min = i;
			}
		}
		fout << p[min] << "/" << min << endl;
		for (int j = 1; j <= n / min; j++)
			mark[min * j][p[min] * j] = 1;
		for (int j = 1; j <= n; j++)
			while (mark[j][p[j]])
				p[j]++;
	}
	return 0;
}