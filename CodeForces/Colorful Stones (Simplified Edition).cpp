#include <iostream>

using namespace std;

string s, t;
int p = 0;

int main()
{
	cin >> s >> t;
	for (int i = 0; i < t.size(); i++)
		if (t[i] == s[p])
			p++;
	cout << p + 1 << endl;
	return 0;
}