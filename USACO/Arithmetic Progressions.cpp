/*
 ID: fkohank1
 PROG: ariprog
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin ("ariprog.in");
ofstream fout ("ariprog.out");

const int maxN = 2 * 62500 + 10, maxA = 10000 + 8;

bool mark[maxN] = {0};
pair <int, int> ans[maxA];

int main()
{
	bool chk;
	int n, m, d, tans = 0;
	vector <int> num;
	fin >> n >> m;
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= m; j++)
			mark[i * i + j * j] = 1;
	for (int i = 0; i <= m * m * 2; i++)
		if (mark[i])
			num.push_back(i);
	for (int i = 0; i < num.size() - 1; i++)
		for (int j = i + 1; j < num.size(); j++)
		{
			chk = 1;
			d = num[j] - num[i];
			if ((num[i] + (n - 1) * d) <= 2 * m * m)
			{
				for (int l = 2; l < n; l++)
					if (!mark[num[i] + d * l])
						chk = 0;
			}
			else
				chk = 0;
			if (chk)
			{
				ans[tans].first = d;
				ans[tans].second = num[i];
				tans++;
				
			}
		}
	sort (ans, ans + tans);
	if (tans > 0)
		for (int i = 0; i < tans; i++)
			fout << ans[i].second << " " << ans[i].first << endl;
	else
		fout << "NONE" << endl;
	return 0;
}