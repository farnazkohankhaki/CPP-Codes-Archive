#include <iostream>

using namespace std;

int main()
{
    int p, m, c, k, r, v, a, b, d, re;
    cin >> p >> m >> c >> k >> r >> v;
    a = p / k;
    b = m / r;
    d = c / v;
    re = a;
    if (re > b)
        re = b;
    if (re > d)
        re = d;
    cout << re << endl;
    return 0;
}
