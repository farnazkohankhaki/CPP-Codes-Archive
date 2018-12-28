#include <iostream>

using namespace std;

int n, s;

int main ()
{
	cin >> n >> s;
	int a, b, ans = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if ((100 - b) % 100 > ans && (s > a || s == a && b == 0))
			ans = (100 - b) % 100;
	}
	cout << ans << endl;
	return 0;
}