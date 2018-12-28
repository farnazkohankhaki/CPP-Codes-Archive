#include <iostream>
#include <algorithm>

using namespace std;

int x[2], n;

int gcd (int a, int b)
{
	if (b > a)
		swap (a, b);
	if (b == 0)
		return a;
	return gcd (b, a % b);
}

int main ()
{
	cin >> x[0] >> x[1] >> n;
	
	int state = 0;
	
	while (true)
	{
		int y = gcd (x[state], n);
		if (y <= n)
		{
			n -= y;
			state = (state + 1) % 2;
		}
		else
			break;
	}
	
	cout << (state + 1) % 2 << endl;
	return 0;
}