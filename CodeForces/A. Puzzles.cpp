#include <iostream>
#include <algorithm>

using namespace std;

const int MAXM = 50 + 5;
int n, m, a[MAXM];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    
    sort(a, a + m);
    int ans = a[n - 1] - a[0];
    for (int i = n; i < m; i++)
        ans = min(ans, a[i] - a[i - n + 1]);
    
    cout << ans << endl;
    
    return 0;
}