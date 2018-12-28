#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

string s[MAXN], ans;
int n;

void reverse(int ind)
{
	for (int i = 0; i < s[ind].size() / 2; i++)
		swap(s[ind][i], s[ind][s[ind].size() - 1 - i]);
}

string pluss(string s1, string s2)
{
	int a = 0;
	string r;
	for (int i = 0; i < s2.size(); i++)
	{
		int x = s2[i] + s1[i] + a - '0' - '0';
		r += (x % 10) + '0';
		a = x / 10;
	}
	for (int i = s2.size(); i < s1.size(); i++)
	{
		int x = s1[i] - '0' + a;
		r += (x % 10) + '0';
		a = x / 10;
	}
	if (a > 0)
		r += a + '0';
	return r;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
		reverse(i);
	ans = s[0];
	for (int i = 1; i < n; i++)
		ans = pluss(ans, s[i]);
	for (int i = ans.size() - 1; i >= ans.size() - 10; i--)
		cout << ans[i];
	cout << endl;
	return 0;
}