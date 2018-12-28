#include <iostream>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;

const int MAXN = 1000 * 1000;

bool mark[MAXN];
int cnt, sum;
vector <int> prime;

void findP()
{
	mark[0] = mark[1] = true;
	for (int i = 2; i < MAXN; i++)
		if (!mark[i])
		{
			prime.push_back(i);
			for (int j = 2 * i; j < MAXN; j += i)
				mark[j] = true;
		}
}

bool isT(int x)
{
	int y = x, p = 1;
	while (y > 0)
	{
		p *= 10;
		if (mark[y])
			return false;
		y /= 10;
	}
	while (p > 1)
	{
		if (mark[x % p])
			return false;
		p /= 10;
	}
	return true;
}

int main()
{
	findP();
	for (int i = 4; i < prime.size() && cnt < 11; i++)
		if (isT(prime[i]))
		{
			cnt++;
			sum += prime[i];
		}
	cout << sum << endl;
	return 0;
}