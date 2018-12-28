#include <iostream>

using namespace std;

const int maxN = 50+8;

int a[maxN];

int main()
{
    int n, k, m = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (1)
    {
        if (m >= k || a[m] < 1)
            break;
        else
            m++;
    }
    if(a[m-1] >= 1)
        while (a[m-1] == a[m])
            m++;
    cout << m << endl;
    return 0;
}
    
