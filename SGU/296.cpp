#include <iostream>

using namespace std;

int k;
string n, ans;

int findDis(int x)
{
	int dis = 0;
	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] - '0' == x)
			break;
		dis++;
	}
	return dis;
}

void add()
{
	for (int i = 9; i >= 0; i--)
	{
		int x = findDis(i);
		if (x <= k)
		{
			ans += i + '0';
			k -= x;
			n = n.substr(x + 1);
			break;
		}
	}
}

int main()
{
	cin >> n >> k;
	
	int f = n.size() - k;
	for (int i = 0; i < f; i++)
		add();
	
	cout << ans << endl;
	
	return 0;
}