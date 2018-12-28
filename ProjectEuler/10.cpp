#include <iostream>

using namespace std;

const int maxN = 2000000 + 8;

bool mark[maxN];

long long prime (int n)
{
    long long k = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!mark[i])
        {
            k += i;
            for (int j = i; j <= n / i; j++)
                mark[j * i] = 1;
        }
    }
    return k;
}
int main()
{
    int n;
    cin >> n;
    cout << prime (n) << endl;
    return 0;
}
