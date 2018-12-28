#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10 * 1000 + 1000;

string s;
string t[MAXN];

int find (string t)
{
	int r = 0;
	for (int i = 0; i < t.size(); i++)
		r += t[i] - 'A' + 1;
	return r;
}

long long findAns ()
{
	long long r = 0;
	int cnt = 0;
	for (int i = 1; i < s.size(); i++)
	{
		while (s[i] != '"')
		{
			t[cnt]+= s[i];
			i++;
		}
		i += 2;
		cnt++;
	}
	sort (t, t + cnt);
	for (int i = 0; i < cnt; i++)
		r += (i + 1) * find (t[i]);
	return r;
}
		
int main ()
{
	cin >> s;
	cout << findAns () << endl;
	return 0;
}