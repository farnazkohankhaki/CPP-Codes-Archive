/*
ID: fkohank1
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("namenum.in");
ofstream fout ("namenum.out");
ifstream ifs ("dict.txt");

const int maxN = 5000 + 8;

string s[maxN];

int main()
{
    bool k =
    0;
    string n, a[10];
    fin >> n;
    a[2] = "ABC";
    a[3] = "DEF";
    a[4] = "GHI";
    a[5] = "JKL";
    a[6] = "MNO";
    a[7] = "PRS";
    a[8] = "TUV";
    a[9] = "WXY";
    for (int i = 0; i < 5000; i++)
        ifs >> s[i];
    for (int i = 0; i < 5000; i++)
    {
        string c;
        for (int j = 0; j < s[i].size(); j++)
        {
            for (int l = 2; l <= 9; l++)
            {
                if (s[i][j] == a[l][0])
                    c += (l + '0');
                if (s[i][j] == a[l][1])
                    c += (l + '0');
                if (s[i][j] == a[l][2])
                    c += (l + '0');
            }
        }
        if (c == n)
        {
            fout << s[i] << endl;
            k = 1;
        }
    }
    if (!k)
        fout << "NONE" << endl;
    return 0;
}
