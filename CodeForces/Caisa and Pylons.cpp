#include <iostream>

using namespace std;

int n;

int main ()
{
	cin >> n;
	int a, ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a > ans)
			ans = a;
	}
	cout << ans << endl;
	return 0;
}