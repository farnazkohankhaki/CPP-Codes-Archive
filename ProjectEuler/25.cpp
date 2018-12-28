#include <iostream>

using namespace std;

string s1 = "1", s2 = "1";
int n = 1000, cnt = 2;

string pluss()
{
	string s;
	int a = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		int x = s1[i] + s2[i] - '0' - '0' + a;
		s += x % 10 + '0';
		a = x / 10;
	}
	for (int i = s1.size(); i < s2.size(); i++)
	{
		int x = s2[i] - '0' + a;
		s += x % 10 + '0';
		a = x / 10;
	}
	if (a > 0)
		s += a + '0';
	return s;
}

int main()
{
	string s;
	cin >> n;
	while (s2.size() < n)
	{
		s = pluss();
		s1 = s2;
		s2 = s;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}