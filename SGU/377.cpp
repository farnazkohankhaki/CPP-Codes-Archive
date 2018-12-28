#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector <int> a1, a2, ans;

vector <int> add (vector <int> x, vector <int> y)
{
	int a = 0;
	for (int i = 0; i < x.size(); i++)
	{
		int b = x[i] + y[i] + a;
		int t = b % 10;
		a = b / 10;
		y[i] = t;
	}
	for (int i = x.size(); i < y.size(); i++)
	{
		int b = y[i] + a;
		int t = b % 10;
		a = b / 10;
		y[i] = t;
	}
	if (a > 0)
		y.push_back(a);
	return y;
}

int main()
{
	cin >> n >> m;
	if (n > m)
		swap (n, m);
	ans.push_back(1);

	for (int i = 0; i < n; i++)
		ans = add (ans, ans);
	a1 = ans;	
	for (int i = n; i < m; i++)
		ans = add (ans, ans);
	a2 = ans;
	a1[0] -= 2;
	ans = add (a1, a2);
	
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i];
	cout << endl;

	return 0;
}