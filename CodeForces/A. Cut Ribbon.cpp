#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 4000 + 400;

int n, a[3], d[MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
        d[a[i]] = 1;
    }
    
    sort(a, a + 3);
    for (int i = a[0]; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (d[i - a[j]] == 0 || i - a[j] < 0)
                continue;
            int x = d[i - a[j]] + 1;
            d[i] = max(d[i], x);
        }
    }
    
    cout << d[n] << endl;
    
    return 0;
}