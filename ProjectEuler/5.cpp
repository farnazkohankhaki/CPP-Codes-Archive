#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1000 + 8;

bool mark[maxN];
int p[maxN];

int pow (int a, int b)
{
    if (b == 0)
        return 1;
    else
    {
        if( b % 2 == 1)
            return pow (a, b / 2) * pow(a, b / 2) *a;
        else
            return pow (a, b / 2) * pow (a, b / 2);
    }
}

void prime (int m)
{
	for (int i = 2; i <= m; i++)
		if (mark[i] == false)
			for (int j = 2; j <= m/i; j++)
				mark[i*j] = true;
}

int main()
{
    int m, k, x, r = 1;
    cin >> m;
    prime (m);
    for (int i = 2; i <= m; i++)
    {
        x = i;
        for (int j = 2; j <= m; j++)
        {
            k = 0;
            while (x % j == 0)
            {
                k++;
                x /= j;
            }
            p[j] = max (k, p[j]);
        }
    }
    for (int i = 2; i <= m; i++)
        r *= pow (i, p[i]);
    cout << r << endl;
	return 0;
}
