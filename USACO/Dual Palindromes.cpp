/*
ID: fkohank1
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("dualpal.in");
ofstream fout ("dualpal.out");

bool base (int s)
{
    int c = 0, f = s;
    for (int i = 2; i <= 10; i++)
    {
        s = f;
        bool k = 0;
        string s2;
        while (s != 0)
        {
            s2 += s % i + '0';
            s = s / i;
        }
        for (int j = 0; j <= s2.size() / 2; j++)
            if (s2[j] != s2[s2.size() - j - 1])
                k = 1;
        if (!k)
            c++;
    }
    if (c > 1)
    {
        fout << f << endl;
        return 1;
    }
    else
        return 0;
}

int main()
{
    int n, s, c = 0;
    fin >> n >> s;
    while (c < n)
    {
        c += base (s + 1);
        s++;
    }
    return 0;
}
