/*
 ID: fkohan1
 PROG: subset
 LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("subset.in");
ofstream fout ("subset.out");

const int maxN = 40 + 8, maxS = 1000 + 8;
long long a[maxN][maxS] = {{0}};

int main()
{
	long long n, ans = 0;
	fin >> n;
	for (int i = 1; i <= n; i++)
		a[i][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n * (n + 1) / 4; j++)
			for (int l = 1; l < i; l++)
				a[i][j] += a[l][j - i];
	for (int i = 1; i <= n; i++)
		ans += a[i][n * (n + 1) / 4];
	if ((n * (n + 1) / 2) % 2 != 0)
		fout << 0 << endl;
	else
		fout << ans / 2 << endl;
	return 0;
}