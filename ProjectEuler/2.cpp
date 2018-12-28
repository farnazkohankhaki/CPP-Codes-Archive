#include <iostream>

using namespace std;

int sfib (int n)
{
    int k = 0, a = 1, b = 2;
    while (b <= n)
    {
        if (a % 2 == 0)
            k += a;
        if (b % 2 == 0)
            k += b;
        a += b;
        b += a;
    }
    if (a <= n && a % 2 == 0)
        k += a;
    return k;
}

int main()
{
    int n;
    cin >> n;
    cout << sfib (n) <<  endl;
    return 0;
}
