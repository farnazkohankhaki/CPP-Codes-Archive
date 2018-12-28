#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int maxN = 2000000 + 8;

bool mark[maxN] = {0};
vector <int> prm, amav;

void prime (int n)
{
	for (int i = 2; i <= n; i++)
		if (!mark[i])
		{
			prm.push_back(i);
			for (int j = 2; j <= n/i; j++)
				mark[i * j] = 1;
		}
}
	
int main()
{
	long long a;
	cin >> a;
	int k = sqrt (a);
	prime (k);
	for (int i = 0; i < prm.size(); i++)
	{
		if (a % prm[i] == 0)
		{
			amav.push_back(prm[i]);
			while (a % prm[i] == 0)
				a /= prm[i];
		}
	}
	if (a != 1)
		amav.push_back(a);
	cout << amav[amav.size() - 1] << endl;
	return 0;
}