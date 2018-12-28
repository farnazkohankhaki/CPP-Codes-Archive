#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 10 * 1000;

bool mark[MAXN];

int main()
{
    int a[4], d;
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    cin >> d;
    for (int i = 0; i < 4; i++)
        for (int j = a[i]; j <= d; j += a[i])
            mark[j] = true;
    int cnt = 0;
    for (int i = 1; i <= d; i++)
        if (mark[i])
            cnt++;
    cout << cnt << endl;
    return 0;
}