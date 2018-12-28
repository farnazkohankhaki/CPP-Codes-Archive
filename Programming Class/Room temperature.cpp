#include <iostream>

using namespace std;

const int MAXN = 1000 + 100;

int n, t[MAXN], w[MAXN];

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i] >> w[i];
	long long sum = 0, s = 0;
	for (int i = 0; i < n; i++)
	{
		sum += t[i] * w[i];
		s += w[i];
	}
	cout << sum / s << endl;
	return 0;
}