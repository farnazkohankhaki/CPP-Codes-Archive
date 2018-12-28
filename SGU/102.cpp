#include <iostream>
#include <vector>

using namespace std;

const int maxN = 10000 + 8;

bool mark[maxN] = {0};
vector <int> prm;

void prime (int n)
{
	for (int i = 2; i <= n; i++)
		if (!mark[i])
		{
			if (n % i == 0)
				prm.push_back(i);
			for (int j = i + 1; j < n / i; j++)
				mark[i * j] = 1;
		}
}
	
int main()
{
	int n, cnt = 0;
	bool k;
	cin >> n;
	prime (n);
	for (int i = 1; i <= n; i++)
	{
		k = 0;
		for (int j = 0; j < prm.size(); j++)
			if (i % prm[j] == 0)
				k = 1;
		if (!k)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}