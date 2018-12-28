#include <iostream>

using namespace std;

int fac[10];

void f ()
{
	fac[0] = 1;
	for (int i = 1; i <= 9; i++)
		fac[i] = fac[i - 1] * i;
}

int main()
{	
	int cnt = 0, tmp, sum;
	f();
	for (int i = 3; i < fac[9] * 7; i++)
	{
		sum = 0;
		tmp = i;
		while (tmp > 0)
		{
			sum += fac[tmp % 10];
			tmp /= 10;
		}
		if (sum == i)
			cnt += i;
	}
	cout << cnt << endl;
	return 0;
}