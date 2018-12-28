#include <iostream>

using namespace std;

long long findNext ()
{
	long long c1 = 286, c2 = 166, c3 = 144;
	long long x = c1 * (c1 + 1) / 2, y = c2 * (c2 * 3 - 1) / 2, z = c3 * (2 * c3 - 1);
	while (x != y || y != z)
	{
		if (x <= y && x <= z)
		{
			c1++;
			x = c1 * (c1 + 1) / 2;
		}
		else if (y <= x && y <= z)
		{
			c2++;
			y = c2 * (c2 * 3 - 1) / 2;
		}
		else
		{
			c3++;
			z = c3 * (2 * c3 - 1);
		}	
	}
	return x;
}

int main ()
{
	cout << findNext() << endl;
	return 0;
}