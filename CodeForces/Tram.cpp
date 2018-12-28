#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;

int main ()
{
	cin >> n;
	int a, b, in = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		in = in - a + b;
		ans = max (in, ans);
	}
	cout << ans << endl;
	return 0;
}