/*
 ID: fkohank1
 PROG: hamming
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin ("hamming.in");
ofstream fout ("hamming.out");

const int maxN = 500 + 8;

int n, b, d, h;
bool a[maxN][maxN] = {{0}}, f = 0;
vector <int> p, ans;

bool isd (int x, int y)
{
	bool k = 0;
	int z = x ^ y, c = 0;
	while (z > 0)
	{
		if (z % 2 == 1)
			c++;
		z /= 2;
	}
	if (c >= d)
		k = 1;
	return k;
}

void fun (int x)
{
	if (f)
		return;
	if (p.size() == n)
	{
		for (int i = 0; i < p.size(); i++)
			ans.push_back(p[i]);
		f = 1;
		return;
	}
	for (int i = x; i < h; i++)
	{
		bool chek = 0;
		if (a[x][i])
		{
			chek = 1;
			for (int j = 0; j < p.size(); j++)
				if (!a[p[j]][i])
					chek = 0;
		}
		if (chek)
		{
			p.push_back (i);
			fun (i);
			p.pop_back();
		}
	}
}

int main()
{
	fin >> n >> b >> d;
	ans.clear();
	p.clear();
	h = 1 << b;
	for (int i = 0; i < h; i++)
		for (int j = i; j < h; j++)
			if (isd (i, j))
			{
				a[i][j] = 1;
				a[j][i] = 1;
			}
	for (int i = 0; i < h; i++)
	{
		if (f) 
			break;
		p.push_back(i);
		fun (i);
		p.pop_back();
	}
	fout << ans[0];
	for (int i = 1; i < ans.size(); i++)
	{
		if (i % 10 == 0)
			fout << endl << ans[i];
		else
			fout << " " << ans[i];
	}	
	fout << endl;
	return 0;
}
