/*
ID: fkohank1
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("palsquare.in");
ofstream fout ("palsquare.out");

int n;

void base (int m)
{
    bool k = 0;
    string s1, s2, s3;
    int sq = m * m;
    while (sq != 0)
    {
        if (sq % n < 10)
            s2 += sq % n + '0';
        else
        {
            if (sq % n == 10)
                s2 += 'A';
            if (sq % n == 11)
                s2 += 'B';
            if (sq % n == 12)
                s2 += 'C';
            if (sq % n == 13)
                s2 += 'D';
            if (sq % n == 14)
                s2 += 'E';
            if (sq % n == 15)
                s2 += 'F';
            if (sq % n == 16)
                s2 += 'G';
            if (sq % n == 17)
                s2 += 'H';
            if (sq % n == 18)
                s2 += 'I';
            if (sq % n == 19)
                s2 += 'J';
        }
        sq = sq / n;
    }
    for (int i = 0; i <= s2.size() / 2; i++)
        if (s2[i] != s2[s2.size() - i - 1])
            k = 1;
    if (!k)
    {
        while (m != 0)
        {
            if (m % n < 10)
                s3 += m % n + '0';
            else
            {
                if (m % n == 10)
                    s3 += 'A';
                if (m % n == 11)
                    s3 += 'B';
                if (m % n == 12)
                    s3 += 'C';
                if (m % n == 13)
                    s3 += 'D';
                if (m % n == 14)
                    s3 += 'E';
                if (m % n == 15)
                    s3 += 'F';
                if (m % n == 16)
                    s3 += 'G';
                if (m % n == 17)
                    s3 += 'H';
                if (m % n == 18)
                    s3 += 'I';
                if (m % n == 19)
                    s3 += 'J';
            }
            m = m / n;
        }
        for (int i = s3.size() - 1; i >= 0; i--)
            s1 += s3[i];
        fout << s1 << " " << s2 << endl;
    }
}
                
int main ()
{
    fin >> n;
    for (int i = 1; i < 301; i++)
        base (i);
    return 0;
}
        
