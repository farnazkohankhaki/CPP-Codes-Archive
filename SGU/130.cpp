#include <iostream>

using namespace std;

const int maxK = 30 + 8;

long long a[maxK] = {0};

int main()
{
	int k;
	cin >> k;
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i <= k; i++)
		for (int j = 0; j < i; j++)
			a[i] += a[j] * a[i - j - 1];
	cout << a[k] << " " << k + 1 << endl;
	return 0;
}