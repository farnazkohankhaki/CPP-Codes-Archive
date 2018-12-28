/*
ID: fkohank1
PROG: milk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("milk.in");
ofstream fout ("milk.out");

const int maxM = 5000 + 8;
int main()
{
    int m;
    long long n, h = 0;
    pair <int, long long> a[maxM];
    fin >> n >> m;
    for (int i = 0; i < m; i++)
        fin >> a[i].first >> a[i].second;
    sort (a, a + m);
    for (int i = 0; i < m; i++)
    {
        if (a[i].second < n)
        {
            n -= a[i].second;
            h += a[i].first * a[i].second;
        }
        else
        {
            h += n * a[i].first;
            break;
        }
    }
    fout << h << endl;
    return 0;
}
    
