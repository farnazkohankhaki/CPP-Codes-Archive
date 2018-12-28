#include <iostream>

using namespace std;

const int maxN = 30+1;

int a[maxN][maxN];

int main()
{
    int n, k = 0, fa, fb;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            fa = 0;
            fb = 0;
            for (int m = 0; m < n; m++)
                fa += a[m][j];
            for (int m = 0; m < n; m++)
                fb += a[i][m];
            if (fa > fb)
                k++;
        }
    cout << k << endl;
    return 0;
}
