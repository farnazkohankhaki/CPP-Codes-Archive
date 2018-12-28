#include <iostream>
#include <vector>

using namespace std;

int n = 100;

struct bigNum
{
	vector <int> a;
	bigNum (int x)
	{
		if (x == 0)
			a.push_back(0);
		for (; x != 0; x /= 10)
			a.push_back(x%10);
	}
	
	void dahBY ()
	{
		for (int i = 0; i < a.size() - 1; i++)
		{
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
		while (a[a.size() - 1] > 9)
		{
			a.push_back (a[a.size() - 1] / 10);
			a[a.size() - 2]  %= 10;
		}
	}
	
	void saf ()
	{
		while (a[a.size() - 1] == 0 && a.size() > 1)
			a.pop_back();
	}
	
	bigNum operator *(int y)
	{
		bigNum x (0);
		for (int i = 0; i <= a.size(); i++)
			x.a.push_back(0);
		for (int i = 0; i < a.size(); i++)
		{
			int j = 0;
			int t = y;
			while (t > 0)
			{
				x.a[i + j] += a[i] * (t % 10);
				t /= 10;
				j++;
			}
		}
		x.dahBY();
		x.saf();
		return x;
	}
};

int main ()
{
	bigNum x(1);
	for (int i = 2; i <= n; i++)
		x = x * i;
	int ans = 0;
	for (int i = 0; i < x.a.size(); i++)
		ans += x.a[i];
	cout << ans << endl;
	return 0;
}