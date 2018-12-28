#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100 * 1000 + 10 * 1000;

long long n, a[MAX_N], d[MAX_N];

int main()
{
    cin >> n;
    int maxE = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a[tmp]++;
        maxE = max(maxE, tmp);
    }
    
    d[1] = a[1];
    for (int i = 2; i <= maxE; i++)
        d[i] = max(d[i - 1], d[i - 2] + i * a[i]);
    
    cout << d[maxE] << endl;
    
    return 0;
}