/*
 ID: fkohank1
 PROG: milk3
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin ("milk3.in");
ofstream fout ("milk3.out");

const int maxN = 20 + 8;

bool mark[maxN][maxN][maxN] = {{{0}}}, ans[maxN] = {0};
int a, b, c;
vector <int> r;

void dfs (int x, int y, int z)
{
	int e = a - x, f = b - y, g = c - z;
	mark[x][y][z] = 1;
	if (x == 0)
		ans[z] = 1;
	
	if (x < f && !mark[0][y + x][z])
		dfs (0, y + x, z);
	if (x >= f && !mark[x - f][b][z])
		dfs (x - f, b, z);
	
	if (y < e && !mark[x + y][0][z])
		dfs (y + x, 0, z);
	if (y >= e && !mark[a][y - e][z])
		dfs (a, y - e, z);
	
	if (x < g && !mark[0][y][z + x])
		dfs (0, y, z + x);
	if (x >= g && !mark[x - g][y][c])
		dfs (x - g, y, c);
	
	if (z < e && !mark[z + x][y][0])
		dfs (z + x, y, 0);
	if (z >= e && !mark[a][y][z - e])
		dfs (a, y, z - e);
	
	if (y < g && !mark[x][0][z + y])
		dfs (x, 0, z + y);
	if (y >= g && !mark[x][y - g][c])
		dfs (x, y - g, c);
	
	if (z < f && !mark[x][z + y][0])
		dfs (x, z + y, 0);
	if (z >= f && !mark[x][b][z - f])
		dfs (x, b, z - f);
}
	
int main()
{
	fin >> a >> b >> c;
	dfs (0, 0, c);
	for (int i = 0; i < 21; i++)
		if (ans[i])
			r.push_back(i);
	for (int i = 0; i < r.size() - 1; i++)
		fout << r[i] << " ";
	fout << r[r.size() - 1] << endl;
	return 0;
}