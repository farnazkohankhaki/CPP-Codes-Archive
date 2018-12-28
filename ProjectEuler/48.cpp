#include <iostream>

using namespace std;

const int maxN = 1000 + 8;

long long a[maxN];

int main()
{
	long long n, r = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
		for (int j = 1; j < i; j++)
			a[i] = (a[i] * i) % 10000000000;
		r = (r + a[i]) % 10000000000;
	}
	cout << r << endl;
	return 0;
}