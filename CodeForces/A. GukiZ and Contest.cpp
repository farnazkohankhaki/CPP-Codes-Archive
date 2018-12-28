#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2000 + 200;

int n, r[MAXN];
pair <int, int> a[MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].first *= -1;
        a[i].second = i;
    }
    
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        r[a[i].second] = i + 1;
        if (i > 0 && a[i].first == a[i - 1].first)
            r[a[i].second] = r[a[i - 1].second];

    }
    
    for (int i = 0; i < n; i++)
        cout << r[i] << " ";
    
    cout << endl;
    
    return 0;
}