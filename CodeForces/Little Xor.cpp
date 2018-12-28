#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int n, a[MAXN], ans;

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i; j++)
		{
			int x = a[i];
			for (int k = 1; k <= j; k++)
				x = x ^ a[i + k];
			ans = max (ans, x);
		}
	
	cout << ans << endl;
	
	return 0;
}