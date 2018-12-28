/*
ID: fkohank1
PROG: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("numtri.in");
ofstream fout ("numtri.out");

const int maxR = 1000 + 8;

int a[maxR][maxR];

int main()
{
    int r, f;
    fin >> r;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= i; j++)
        {
            fin >> f;
            a[i][j] = max (a[i - 1][j] + f, a[i - 1][j - 1] + f);
        }
    f = 0;
    for (int i = 1; i <= r; i++)
        f = max (f, a[r][i]);
    fout << f << endl;
    return 0;
}
