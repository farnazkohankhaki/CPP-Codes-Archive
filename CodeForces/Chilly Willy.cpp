#include <iostream>

using namespace std;

int n;
string s;

void f1()
{
	if (n != 3)
		cout << -1 << endl;
	else
		cout << 210 << endl;
}

void f2 ()
{
	s += '1';
	int x = (n + 2) / 3, y = n % 3;
	if (y == 1)
	{
		for (int i = 0; i < n - 3; i++)
			s += '0';
		if (x % 2 == 0)
			s += "50";
		else
			s += "20";
	}
	if (y == 2)
	{
		if (x % 2 == 0)
		{
			for (int i = 0; i < n - 3; i++)
				s += '0';
			s += "80";
		}
		else
		{
			for (int i = 0; i < n - 4; i++)
				s += '0';
			s += "200";
		}
	}
	if (y == 0)
	{
		for (int i = 0; i < n - 4; i++)
			s += '0';
		if (x % 2 == 0)
			s += "170";
		else
			s += "110";
	}
	cout << s << endl;
}
		
int main ()
{
	cin >> n;
	if (n <= 3)
		f1();
	else
		f2();
	return 0;
}