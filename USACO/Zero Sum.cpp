/*
 ID: fkohan1
 PROG: zerosum
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin ("zerosum.in");
ofstream fout ("zerosum.out");

int main () 
{
	string s;
	int n, a[10], p, sum, tmp, t;
	fin >> n;
	int x = pow ((double)3, (double)(n - 1));
	for (int i = 0; i < x; i++)
	{
		t = 0;
		p = 0;
		sum = 0;
		tmp = i;
		for (int j = 0; j < n; j++)
			a[j] = 0;
		a[0] = n;
		
		for (int j = 1; j <= n; j++)
		{
			if (j != n)
			{
				if (tmp % 3 == 1)
				{
					t = 0;
					sum += a[p];
					p++;
					a[p] = n - j;
				}
				if (tmp % 3 == 2)
				{
					t = 0;
					sum -= a[p];
					p++;
					a[p] = n - j;
				}
				if (tmp % 3 == 0)
				{
					t++;
					a[p] += pow ((double)(10), (double)t) * (n - j);
				}
				tmp /= 3;
			}
			if (j == n)
			{
				sum += a[p];
				if (sum == 0)
				{
					s.clear();
					tmp = i;
					s += '0' + n;
					for (int l = 1; l < n; l++)
					{
						if (tmp % 3 == 1)
							s += '+';
						if (tmp % 3 == 2)
							s += '-';
						if (tmp % 3 == 0)
							s += '*';
						s += '0' + n - l;
						tmp /= 3;
					}
					for (int l = s.size() - 1; l >= 0; l--)
						if (s[l] == '*')
							fout << " ";
						else
							fout << s[l];
					fout << endl;
				}
			}
		}
	}
	return 0;
}