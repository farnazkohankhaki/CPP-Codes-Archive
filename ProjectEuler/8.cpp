#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string s = "", p;
	int maxa = 0;
	for (int i = 0; i < 20; i++)
	{
		cin >> p;
		s += p;
	}
	for (int i = 0; i < s.size() - 4; i++)
		maxa = max (maxa, (s[i] - '0') * (s[i + 1] - '0') * (s[i + 2] - '0') * (s[i + 3] - '0') * (s[i + 4] - '0'));
	cout << maxa << endl;
	return 0;
}