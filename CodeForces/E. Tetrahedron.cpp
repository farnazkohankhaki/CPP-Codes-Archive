#include <iostream>

using namespace std;

const long long MOD = 1000000007;// MAX_N = 1000 * 1000 * 10 + 100;

long long n, d[2][4];

int main()
{
    cin >> n;
    
    d[0][3] = 1;
    for (long long i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 1; k < 4; k++)
            {
                int u = (j + k) % 4;
                d[1][j] += d[0][u];
            }
            d[1][j] %= MOD;
        }
        for (int j = 0; j < 4; j++)
        {
            d[0][j] = d[1][j];
            d[1][j] = 0;
        }
    }
    
    cout << d[0][3] << endl;
    
    return 0;
}