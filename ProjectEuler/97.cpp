#include <iostream>

using namespace std;

const long long  delta = 10000000000;

int n = 7830457, m = 28433;

int main ()
{
	long long r = 1;
	for (int i = 0; i < n; i++)
	{
		r *= 2;
		r %= delta;
	}
	r *= m;
	r %= delta;
	r++;
	r %= delta;
	cout << r << endl;
	return 0;
}