#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	int n, p, tmp, ans = 0;
	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (pow ((double)tmp, (double)p) > 0)
			ans += pow ((double)tmp, (double)p);
	}
	cout << ans << endl;
	return 0;
}