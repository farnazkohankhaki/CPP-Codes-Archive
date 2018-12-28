#include <iostream>
#include <algorithm>

using namespace std;

long long n, k, m;

void f()
{
    long long a = n - 1, b = k - 1, ans = 0;
    while(a != 0)
    {
        if (b > a)
        {
            ans++;
            break;
        }
        a -= b;
        ans++;
        b--;
    }
    cout << ans << endl;
}

int main()
{
    cin >> n >> k;
    m = ((k - 1) * k) / 2 + 1;
    if (n <= m)
        f();
    else 
        cout << -1 << endl;
    return 0;
}