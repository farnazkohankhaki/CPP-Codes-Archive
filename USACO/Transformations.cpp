/*
ID: fkohank1
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("transform.in");
ofstream fout ("transform.out");

const int maxN = 10 + 8;

bool a[maxN][maxN], b[maxN][maxN], c[maxN][maxN], d[maxN][maxN];

int n, re[70];

void c1 ()
{
    for (int j = 0; j < n; j++)
        for (int l = 0; l < n; l++)
            c[j][l] = a[n - l - 1][j];
    for (int j = 0; j < n; j++)
        for (int l = 0; l < n; l++)
            a[j][l] = c[j][l];
}

void c2 ()
{
    for (int j = 0; j < n; j++)
        for (int l = 0; l < n; l++)
            c[j][l] = a[n - j - 1][n - l - 1];
    for (int j = 0; j < n; j++)
        for (int l = 0; l < n; l++)
            a[j][l] = c[j][l];
}

void c3 ()
{
    for (int j = 0; j < n; j++)
        for (int l = 0; l < n; l++)
            c[j][l] = a[l][n - j - 1];
    for (int j = 0; j < n; j++)
        for (int l = 0; l < n; l++)
            a[j][l] = c[j][l];
}

void c4 ()
{
    for (int j = 0; j < n; j++)
        for (int l = 0; l < n; l++)
            c[j][l] = a[j][n - l - 1];
    for (int j = 0; j < n; j++)
        for (int l = 0; l < n; l++)
            a[j][l] = c[j][l];
}

void c51 ()
{
    c4 ();
    c1 ();
}

void c52 ()
{
    c4 ();
    c2 ();
}

void c53 ()
{
    c4 ();
    c3 ();
}

int main()
{
    bool k;
    int r = 7;
    char f;
    fin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            fin >> f;
            if (f == '@')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            fin >> f;
            if (f == '@')
                b[i][j] = 1;
            else
                b[i][j] = 0;
        }
    for (int j = 0; j < n; j++)
        for (int l = 0; l < n; l++)
            d[j][l] = a[j][l];
    for (int i = 1; i <= 7; i++)
    {
        k = 0;
        if (i == 1)
        {
            c1 ();
            for (int j = 0; j < n; j++)
                for (int l = 0; l < n; l++)
                    if (a[j][l] != b[j][l])
                        k = 1;
            if (!k)
            {
                r = i;
                break;
            }
            for (int j = 0; j < n; j++)
                for (int l = 0; l < n; l++)
                    a[j][l] = d[j][l];
        }
        if (i == 2)
        {
            c2 ();
            for (int j = 0; j < n; j++)
                for (int l = 0; l < n; l++)
                    if (a[j][l] != b[j][l])
                        k = 1;
            if (!k)
            {
                r = i;
                break;
            }
            for (int j = 0; j < n; j++)
                for (int l = 0; l < n; l++)
                    a[j][l] = d[j][l];
        }
        if (i == 3)
        {
            c3 ();
            for (int j = 0; j < n; j++)
                for (int l = 0; l < n; l++)
                    if (a[j][l] != b[j][l])
                        k = 1;
            if (!k)
            {
                r = i;
                break;
            }
            for (int j = 0; j < n; j++)
                for (int l = 0; l < n; l++)
                    a[j][l] = d[j][l];
        }
        if (i == 4)
        {
            c4 ();
            for (int j = 0; j < n; j++)
                for (int l = 0; l < n; l++)
                    if (a[j][l] != b[j][l])
                        k = 1;
            if (!k)
            {
                r = i;
                break;
            }
            for (int j = 0; j < n; j++)
                for (int l = 0; l < n; l++)
                    a[j][l] = d[j][l];
        }
        if (i == 5)
        {
            c51 ();
            for (int j = 0; j < n; j++)
                for (int l = 0; l < n; l++)
                    if (a[j][l] != b[j][l])
                        k = 1;
            if (!k)
            {
                r = i;
                break;
            }
            for (int j = 0; j < n; j++)
                for (int l = 0; l < n; l++)
                    a[j][l] = d[j][l];
        }
        if (i == 5)
        {
            k = 0;
            c52 ();
            for (int j = 0; j < n; j++)
                for (int l = 0; l < n; l++)
                    if (a[j][l] != b[j][l])
                        k = 1;
            if (!k)
            {
                r = i;
                break;
            }
            for (int j = 0; j < n; j++)
                for (int l = 0; l < n; l++)
                    a[j][l] = d[j][l];
        }
        if (i == 5)
        {
            k = 0;
            c53 ();
            for (int j = 0; j < n; j++)
                for (int l = 0; l < n; l++)
                    if (a[j][l] != b[j][l])
                        k = 1;
            if (!k)
            {
                r = i;
                break;
            }
            for (int j = 0; j < n; j++)
                for (int l = 0; l < n; l++)
                    a[j][l] = d[j][l];
        }
        if (i == 6)
        {
            for (int j = 0; j < n; j++)
                for (int l = 0; l < n; l++)
                    if (a[j][l] != b[j][l])
                        k = 1;
            if (!k)
            {
                r = i;
                break;
            }
        }
    }
    fout << r << endl;
    return 0;
}
