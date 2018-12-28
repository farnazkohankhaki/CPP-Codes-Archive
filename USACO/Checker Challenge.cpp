/*
 ID: fkohank1
 PROG: checker
 LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("checker.in");
ofstream fout ("checker.out");

const int maxN = 30 + 9;

int a[maxN] = {0}, r = 0, n;
bool mark1[maxN] = {0}, mark2[maxN] = {0}, mark3[maxN] = {0};

void f (int x)
{
	if (x > n)
	{
		r++;
		if (r < 4)
		{
			fout << a[1];
			for (int i = 2; i <= n; i++)
				fout << " " << a[i];
			fout << endl;
		}
		return;
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (!mark1[i] && !mark2[i + x] && !mark3[i - x + n])
		{
			mark1[i] = 1;
			mark2[i + x] = 1;
			mark3[i - x + n] = 1;
			a[x] = i;
			f (x + 1);
			mark1[i] = 0;
			mark2[i + x] = 0;
			mark3[i - x + n] = 0;
		}
	}
}

int main()
{
	fin >> n;
	f (1);
	fout << r << endl;
	return 0;
}