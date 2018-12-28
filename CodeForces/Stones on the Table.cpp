#include <iostream>

using namespace std;

int n, ans;
string s;

int main ()
{
	cin >> n >> s;
	char c = 'A';
	for (int i = 0; i < n; i++)
	{
		if (s[i] == c)
			ans++;
		c = s[i];
	}
	cout << ans << endl;
	return 0;
}