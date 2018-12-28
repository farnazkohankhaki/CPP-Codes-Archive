#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	int x, tmp, ans = 0;
	for (int i = 2; i <= 1000000; i++)
	{
		tmp = 0;
		x = i;
		while (x > 0)
		{
			tmp += pow ((double) (x % 10), (double) 5);
			x /= 10;
		}
		if (tmp == i)
			ans += i;
	}
	cout << ans << endl;
	return 0;
}