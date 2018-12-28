#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 100+7;

int main()
{
    double r = 0;
    int n, f[maxN];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> f[i];
    sort (f, f+n);
    for (int i = n-1; i >= 0; i--)
        if ((n-i) % 2 == 1)
            r += f[i]*f[i];
        else
            r -= f[i]*f[i];
    r = r*3.1415;
    cout << r << endl;
    return 0;
}

