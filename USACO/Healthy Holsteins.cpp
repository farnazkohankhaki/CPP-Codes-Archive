/*
 ID: fkohank1
 PROG: holstein
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin ("holstein.in");
ofstream fout ("holstein.out");

const int maxV = 25 + 8, maxG = 15 + 8; 

int v, g, av[maxV], ag[maxG][maxV], w[maxV];
bool marka[maxG], markw[maxG];
vector <int> ans, p;

bool f (int x)
{
	bool r = 1;
	int y = 0,z = x;
	p.clear();
	for (int i = 0; i < v; i++)
		w[i] = 0;
	for (int i = 0; i < g; i++)
		markw[i] = 0;
	while (x > 0)
	{
		if (x % 2 == 1)
		{
			p.push_back (y);
			for (int i = 0; i < v; i++)
				w[i] += ag[y][i];
			markw[y] = 1;
		}
		y++;
		x /= 2;
	}
	for (int i = 0; i < v; i++)
		if (av[i] > w[i])
			r = 0;
	return r;
}

int main()
{
	fin >> v;
	for (int i = 0; i < v; i++)
		fin >> av[i];
	fin >> g;
	for (int i = 0; i < g; i++)
		for (int j = 0; j < v; j++)
			fin >> ag[i][j];
	int h = 1 << g;
	
	for (int i = 0; i < g; i++)
	{
		marka[i] = 1;
		ans.push_back(i);
	}
	
	for (int i = 0; i < h; i++)
	{
		if (f (i))
		{
			if (p.size() < ans.size())
			{
				ans.clear();
				for (int j = 0; j < p.size(); j++)
					ans.push_back(p[j]);
				for (int j = 0; j < g; j++)
					marka[j] = markw[j];
			}
			else if (p.size() == ans.size())
				for (int l = g - 1; l >= 0; l--)
				{
					if (!marka[l] && markw[l])
						break;
					if (marka[l] && !markw[l])
					{
						ans.clear();
						for (int j = 0; j < p.size(); j++)
							ans.push_back(p[j]);
						for (int j = 0; j < g; j++)
							marka[j] = markw[j];
						break;
					}
				}
		}
	}
	fout << ans.size();
	for (int i = 0; i < ans.size(); i++)
		fout << " " << ans[i] + 1;
	fout << endl;
	return 0;
}