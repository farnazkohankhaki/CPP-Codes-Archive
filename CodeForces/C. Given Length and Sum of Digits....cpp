#include <iostream>

using namespace std;

int m, s;

void output()
{
    if (s == 0)
    {
        int ans = -1;
        if (m == 1)
            ans = 0;
        cout << ans << " " << ans << endl;
        return;
    }
    
    if (s < 1 || s > 9 * m)
    {
        cout << -1 << " " << -1 << endl;
        return;
    }
    
    int res = s;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (i == 1 && j == 0)
                continue;
            if ((res - j) >= 0 && (res - j) <= (m - i) * 9)
            {
                cout << j;
                res -= j;
                break;
            }
        }
    }
    cout << " ";
    
    res = s;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 9; j >= 0; j--)
        {
            if (i == 1 && j == 0)
                continue;
            if ((res - j) >= 0 && (res - j) <= (m - i) * 9)
            {
                cout << j;
                res -= j;
                break;
            }
        }
    }
    cout << endl;

    
    return;
}
                
int main()
{
    cin >> m >> s;
    
    output();
    
    return 0;
}