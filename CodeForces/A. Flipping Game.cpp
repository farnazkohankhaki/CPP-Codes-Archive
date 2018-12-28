#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200 + 20;

int n, a[MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > 0)
            ans++;
    
    int cnt = -n;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            int tmp = 0;
            for (int k = i; k <= j; k++)
                if (a[k] == 0)
                    tmp++;
                else
                    tmp--;
            cnt = max(tmp, cnt);
        }
    ans += cnt;
    
    cout << ans << endl;
    
    return 0;
}