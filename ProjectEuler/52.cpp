#include <iostream>
#include <vector>
#define ll long long
#define vt vector <int>

using namespace std;

vt a[10];

vt findV(ll x)
{
	vt r;
	while (x > 0)
	{
		r.push_back(x % 10);
		x /= 10;
	}
	return r;
}

bool isP(int x, int y)
{
	int t[2][10];
	for (int i = 0; i < 10; i++)
		t[0][i] = t[1][i] = 0;
	
	if (a[x].size() != a[y].size())
		return false;
	
	for (int i = 0; i < a[x].size(); i++)
	{
		t[0][a[x][i]]++;
		t[1][a[y][i]]++;
	}
	for (int i = 0; i < 10; i++)
		if (t[0][i] != t[1][i])
			return false;
	
	return true;
}

int main()
{
	for (ll i = 1; ; i++)
	{
		for (ll j = 1; j <= 6; j++)
			a[j] = findV (i * j);
		
		if (isP(1, 2) && isP(1, 3) && isP(1, 4) && isP(1, 5) && isP(1, 6))
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}