#include <iostream>

using namespace std;

const int maxN = 1000+8;

int a[maxN];

void goshad (int n)
{
    a[0] = 0;
    int k = 1;
    while (k)
    {
        for (int i = 1; i <= n; i++)
            cout << a[i];
        cout << endl;
        k = 0;
        for (int i = n; i > 0; i--)
            if (a[i] == 0 && a[i-1] == 0)
            {
                k = 1;
                a[i] = 1;
                for (int j = i+1; j <= n; j++)
                    a[j] = 0;
                break;
            }
    }
}

int main()
{
    int n;
    cin >> n;
    goshad (n);
    system("pause");
    return 0;
}
