#include <iostream>

using namespace std;

const int MAX_N = 1000 + 100;
const int s[4][3][2] = { {{0, 1}, {1, 1}, {1, 0}}, {{0, -1}, {1, -1}, {1, 0}}, {{-1, 0}, {-1, 1}, {0, 1}}, {{-1, -1}, {-1, 0}, {0, -1}}};

int a[MAX_N][MAX_N] = {{0}};

int main()
{
    int n, m, t, ans = 0;
    cin >> n >> m >> t;
    for (int i = 1; i <= t; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        a[x][y] = 1;
        for (int j = 0; j < 4; j++)
        {
            int cnt = 0;
            for (int k = 0; k < 3; k++)
            {
                int nx = x + s[j][k][0], ny = y + s[j][k][1];
                if (nx < 0 || ny < 0 || nx == n || ny == m)
                    continue;
                cnt += a[nx][ny];
            }
            if (cnt == 3 && ans == 0)
                ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}