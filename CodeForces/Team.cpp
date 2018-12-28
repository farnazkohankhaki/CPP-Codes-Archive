#include <iostream>

using namespace std;

int n, ans;

int main ()
{
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		if ((a + b + c) > 1)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
		