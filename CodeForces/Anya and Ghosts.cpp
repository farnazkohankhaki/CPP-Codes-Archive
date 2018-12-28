#include <iostream>

using namespace std;

const int MAXI = 1000 + 100, cns = 400;

bool isC[MAXI];
int m, t, r, w[MAXI];

int main()
{
    cin >> m >> t >> r;
    for (int i = 0; i < m; i++)
        cin >> w[i];
    
    int ans = 0;
    bool isA = t >= r;
    for (int i = 0; i < m; i++)
    {
        if (!isA)
            break;
        int h = r;
        for (int j = -t; j < 0; j++)
            if (isC[j + w[i] + cns])
                h--;
        for (int j = w[i] - 1; j >= w[i] - t && h > 0; j--)
            if (!isC[j + cns])
            {
                h--;
                isC[j + cns] = true;
                ans++;
            }
    }
    if (isA)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}