#include <iostream>
#include <cmath>

using namespace std;

const int maxN = 100 + 8;

int a[maxN];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		int cnt = 0, tmp = a[i];
		for (int j = 2; j <= sqrt (a[i]); j++)
			if (j * j != a[i])
			{
				while (tmp % j == 0)
				{
					tmp /= j;
					cnt++;
				}
			}
			else
				cnt++;
		if (cnt	== 1)
			cout << "Yes" << endl;
		else	
			cout << "No" << endl;
	}
	return 0;
}
