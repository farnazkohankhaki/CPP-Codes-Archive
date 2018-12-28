#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200000 + 20000;

long long n, a[MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a + n);
    cout << a[n - 1] - a[0] << " ";
    long long f = 0, s = 0;
    for (int i = 0; i < n; i++)
        if (a[0] == a[i])
            f++;
        else if(a[n - 1] == a[i])
            s++;
    if (a[0] == a[n - 1])
        cout << n * (n - 1) / 2 << endl;
    else
        cout << s * f << endl;
    
    return 0;
}