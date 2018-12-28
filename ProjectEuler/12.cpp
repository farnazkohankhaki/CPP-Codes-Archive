#include <iostream>

using namespace std;

int f (int x)
{
	int a = 0, b = 0;
	if (x % 2 == 0)
	{
		for (int i = 2; i <= x + 1; i++)
		{
			if ((x / 2) % i == 0)
				a++;
			if ((x + 1) % i == 0)
				b++;
		}
	}
	else 
	{
		for (int i = 2; i <= x + 1; i++)
		{
			if (x % i == 0)
				a++;
			if (((x + 1) / 2) % i == 0)
				b++;
		}
		
	}
	return 1 + a * b + a + b;
}

int main ()
{
	int i = 1;
	while (f (i) <= 500)
		i++;
	cout << i * (i + 1) / 2 << endl;
	return 0;
}