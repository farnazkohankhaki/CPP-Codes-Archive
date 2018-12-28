#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 10000;

int n;
int x[MAXN], y[MAXN], cnt[MAXN], ans[MAXN];

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	for (int i = 0; i < n; i++)
		cnt[x[i]]++;
	
	for (int i = 0; i < n; i++)
	{
		ans[i] = n - 1;
		ans[i] += cnt[y[i]];
	}
	
	for (int i = 0; i < n; i++)
		cout << ans[i] << " " << 2 * n - 2 - ans[i] << endl;
		
	return 0;
}