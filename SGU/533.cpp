#include <iostream>

using namespace std;

int main()
{
	int n, ans = 2;
	cin >> n;
	if (n == 21)
		cout << 1 << endl;
	else
	{
		while (n >= 44)
		{
			n -= 14;
			ans++;
		}
		if (n >= 30 && n <= 40)
			cout << ans << endl;
		else 
			cout << -1 << endl;
	}
	return 0;
}