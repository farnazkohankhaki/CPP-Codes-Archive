#include <iostream>

using namespace std;

const int maxN = 1000+8;

int a[maxN];
bool mark[maxN];

int Factorial (int n)
{
    int r;
    if (n == 1)
        return 1;
    else
        r = n*Factorial (n-1);
    return r;
}

void P (int n)
{
    int k = 1, m;
    for (int i = 1; i <= n; i++)
        mark[i] = 0;
    while (a[n-k] < a[n-k-1])
        k++;
    for (int i = n-1; i >= n-k; i--)
        mark[a[i]] = 1;
    for (int i = a[n-k-1]; i <= n; i++)
        if (mark[i])
        {
            mark[a[n-k-1]] = 1;
            a[n-k-1] = i;
            mark[i] = 0;
            break;
        }
    m = n-k;
    for (int i = 1; i <= n; i++)
        if(mark[i])
        {
            a[m] = i;
            m++;
        }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i] = i+1;
        cout << a[i];
    }
    cout << endl;
    a[n] = 0;
    for (int i = 0; i <= Factorial (n) -2; i++)
    {
        P (n);
        for (int j = 0; j < n; j++)
            cout << a[j];
        cout << endl;
    }
    return 0;
}
