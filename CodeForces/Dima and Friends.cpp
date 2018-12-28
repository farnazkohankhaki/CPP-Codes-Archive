#include <iostream>

using namespace std;

int n, sum, ans;

int main()
{
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		sum += x;
	}
	for (int i = 1; i <= 5; i++)
		if ((sum+i)%(n+1) != 1)
			ans++;
	cout << ans << endl;
	return 0;
}