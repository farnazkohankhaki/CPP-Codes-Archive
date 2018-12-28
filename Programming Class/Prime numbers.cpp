#include <iostream>
#include <vector>
#define ll long long

using namespace std;

const int MAXN = 1000 * 1000 + 1000;

bool mark[MAXN];
int a[6] = {7, 0, 2, 0, 0, 3};
vector <int> prime;
ll ans;

void findPrime()
{
	mark[1] = mark[0] = true;
	for (int i = 2; i < MAXN; i++)
		if (!mark[i])
		{
			prime.push_back(i);
			for (int j = 2; j * i < MAXN; j++)
				mark[j * i] = true;
		}
}

int findN()
{
	ll r = 0, d = 1;
	for (int i = 0; i < 6; i++)
	{
		r += a[i] * d;
		d *= 10;
	}
	return r;
}
	
ll NP (int x)
{
	ll r = 1;
	for (int i = 0; i < prime.size() && x > 1; i++)
	{
		int cnt = 0;
		while (x % prime[i] == 0)
		{
			cnt++;
			x /= prime[i];
		}
		cnt *= 5;
		r *= cnt + 1;
	}
	return r;
}

int main()
{
	findPrime();
	
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
			{
				a[1] = i;
				a[3] = j;
				a[4] = k;
				int b = findN();
				ans += NP(b);
			}
	
	cout << ans << endl;
	return 0;
}