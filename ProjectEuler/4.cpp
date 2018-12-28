#include <iostream>
#include <algorithm>

using namespace std;

int pow (int i, int j)
{
    if (j == 0)
        return 1;
    return i * pow (i, j - 1);
}

int tear (int k)
{
    int r = 0;
    while (k > 0)
    {
        r++;
        k /= 10;
    }
    return r;
}

bool pld (int k)
{
    bool r = 1;
    int m =  tear (k);
    for (int l = 0; l <= m / 2; l++)
        if ((k / pow (10, l)) % 10 != (k / pow (10, m - l - 1)) % 10)
            r = 0;
    return r;
}

int main()
{
    int maxx = 0;
    for (int i = 100; i < 1000; i++)
        for (int j = 100; j < 1000; j++)
            if (i * j > maxx)
                if (pld (i * j))
                    maxx = max (maxx, i * j);
    cout << maxx << endl;
    return 0;
}
