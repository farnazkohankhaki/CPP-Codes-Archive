#include <iostream>

using namespace std;

const int maxN = 1000 + 100;

int n, k;
int mark[maxN];

int main()
{
	cin >> n >> k;
	int p = n - 1;
	for (int i= 0; i < n; i++)
		mark[i] = 1;
	
	for (int i = 1; i < n; i++)
	{
		int t = 0;
		while (t != k)
		{
			p++;
			p %= n;
			t += mark[p];
		}
		mark[p] = 0;
	}
	for (int i = 0; i < n; i++)
		if (mark[i])
		{
			cout << i + 1 << endl;
			break;
		}
	return 0;
}