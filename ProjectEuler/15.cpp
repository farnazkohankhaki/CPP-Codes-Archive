#include <iostream>

using namespace std;

const int maxN = 100 + 8;

long long a[maxN][maxN];

void ch (int n)
{
    for (int i = 0; i <= n; i++)
    {
        a[0][i] = 1;
        a[i][i] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= 2 * n; j++)
            a[i][j] = a[i - 1][j - 1] + a[i][j - 1];
}
int main()
{
    int n;
    cin >> n;
    ch (n);
    cout << a[n][2 * n] << endl;
    return 0;
}
