#include <iostream>

using namespace std;

const int MAXN = 100 + 10;

int a[MAXN], ans;
string s;

int main ()
{
	cin >> s;
	
	for (int i = 0; i < s.size(); i++)
		a[(s[i] - 'A') % 32]++;
	for (int i = 0; i < MAXN; i++)
		if (a[i] > 0)
			ans++;
	if (ans % 2)
		cout << "IGNORE HIM!" << endl;
	else 
		cout << "CHAT WITH HER!" << endl;

	return 0;
}