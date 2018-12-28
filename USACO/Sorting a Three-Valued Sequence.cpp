/*
 ID: fkohank1
 PROG: sort3
 LANG: C++
 */

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("sort3.in");
ofstream fout ("sort3.out");

const int maxN = 1000 + 8;

int a[maxN];

int main()
{
	int n, t[4] = {0}, r = 0;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> a[i];
		t[a[i]]++;
	}
	for (int i = 0; i < t[1]; i++)
	{
		if (a[i] == 2)
			for (int j = t[1]; j < t[1] + t[2]; j++)
			{
				if (a[j] == 1)
				{
					a[j] = 2;
					a[i] = 1;
					r++;
					break;
				}
			}
		if (a[i] == 3)
			for (int j = t[1] + t[2]; j < t[1] + t[2] + t[3]; j++)
			{
				if (a[j] == 1)
				{
					a[j] = 3;
					a[i] = 1;
					r++;

					break;
				}
			}
	}
	for (int i = t[1]; i < t[1] + t[2]; i++)
	{
		if (a[i] == 3)
			for (int j = t[1] + t[2]; j < t[1] + t[2] + t[3]; j++)
			{
				if (a[j] == 2)
				{
					a[j] = 3;
					a[i] = 2;
					r++;
					break;
				}
			}
	}
	for (int i = 0; i < t[1]; i++)
		if (a[i] != 1)
			r += 2;
	fout << r << endl;
	return 0;
}