#include <iostream>

using namespace std;

const int MAX_N = 100 * 1000 + 10 * 1000;

int n, m, a[MAX_N], d[MAX_N];
bool mark[MAX_N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    d[n - 1] = 1;
    mark[a[n - 1]] = true;
    for (int i = n - 2; i >= 0; i--)
    {
        d[i] = d[i + 1];
        if (!mark[a[i]])
        {
            mark[a[i]] = true;
            d[i]++;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        cout << d[x - 1] << endl;
    }
    
    return 0;
}