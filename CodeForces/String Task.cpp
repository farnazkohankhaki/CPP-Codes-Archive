#include <iostream>

using namespace std;

const int l = 97, p = 32;
string s, t;

void f ()
{
	for (int i = 0; i < s.size(); i++)
	{
		int x = s[i];
		if (x < 97)
			x += p;
		char a = x;
		if (a != 'a' && a != 'u' && a != 'i' && a != 'e' && a != 'y' && a != 'o')
		{
			t += '.';
			t += a;
		}
	}
}
	
int main ()
{
	cin >> s;
	f();
	cout << t << endl;
	return 0;
}