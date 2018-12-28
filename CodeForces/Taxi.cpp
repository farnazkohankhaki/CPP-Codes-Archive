#include <iostream>

using namespace std;

long long r[5];

int main()
{
    long long n, re = 0, f, k;
    int a;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 1)
            r[1]++;
        if (a == 2)
            r[2]++;
        if (a == 3)
            r[3]++;
        if (a == 4)
            r[4]++;
    }
    re += r[4];
    f = r[2]/2;
    re += f;
    r[2] = r[2]%2;
    if (r[3] > r[1])
    {
        re += r[1];
        r[3] -= r[1];
        r[1] = 0;
        re += r[3] + r[2];
    }
    else
    {
        re += r[3];
        r[1] -= r[3];
        r[3] = 0;
        f = r[2]*2 + r[1];
        k = f%4;
        re += f/4;
        if (k != 0)
            re++;
    }
    cout << re << endl;
    return 0;
}
