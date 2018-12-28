#include <iostream>

using namespace std;

const int maxN = 100+8;

int main()
{
    int n, f, a[maxN];
    bool h[maxN];
    cin >> n >> f;
    for(int i = 0; i <= 100; i++)
        h[i] = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        h[a[i]] = 1;
    }
    for(int i = 0; i < n; i++)
        if(h[a[i]])
            if(a[i] > f)
            {
                for(int j = f; j < a[i]; j++)
                    if(h[j])
                    {
                        cout << j <<" ";
                        h[j] = 0;
                    }
                cout << a[i] << " ";
                h[a[i]] = 0;
				f = a[i];
            }
            else
            {
                for(int j = f; j > a[i] ; j--)
                    if(h[j])
                    {
                        cout << j <<" ";
                        h[j] = 0;
                    }
                cout << a[i] << " ";
                h[a[i]] = 0;
				f = a[i];
            }
	cout << endl;
    return 0;
}
