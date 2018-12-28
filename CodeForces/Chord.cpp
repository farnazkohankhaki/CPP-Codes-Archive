#include <iostream>

using namespace std;

int f (string s)
{
	int x;
	if (s[0] == 'C' && s[1] != '#')
		x = 1;
	if (s[0] == 'C' && s[1] == '#')
		x = 2;
	if (s[0] == 'D' && s[1] != '#')
		x = 3;
	if (s[0] == 'D' && s[1] == '#')
		x = 4;
	if (s[0] == 'E')
		x = 5;
	if (s[0] == 'F' && s[1] != '#')
		x = 6;
	if (s[0] == 'F' && s[1] == '#')
		x = 7;
	if (s[0] == 'G' && s[1] != '#')
		x = 8;
	if (s[0] == 'G' && s[1] == '#')
		x = 9;
	if (s[0] == 'A')
		x = 10;
	if (s[0] == 'B')
		x = 11;
	if (s[0] == 'H')
		x = 12;
	return x;
}

int dis (int x, int y)
{
	if (x < y)
		return  y - x;
	else
		return 12 - x + y;
}

int main()
{
	bool fa = 0;
	string a, b, c;
	cin >> a >> b >> c;

	// abc
	if (dis (f(a), f (b)) == 4 && dis (f (b), f (c)) == 3)
	{
		fa = 1;
		cout << "major" << endl;
	}
	if (dis (f(a), f (b)) == 3 && dis (f (b), f (c)) == 4)
	{
		fa = 1;
		cout << "minor" << endl;
	}
	//acb
	if (dis (f(a), f (c)) == 4 && dis (f (c), f (b)) == 3)
	{
		fa = 1;
		cout << "major" << endl;
	}
	if (dis (f(a), f (c)) == 3 && dis (f (c), f (b)) == 4)
	{
		fa = 1;
		cout << "minor" << endl;
	}
	//bac
	if (dis (f(b), f (a)) == 4 && dis (f (a), f (c)) == 3)
	{
		fa = 1;
		cout << "major" << endl;
	}
	if (dis (f(b), f (a)) == 3 && dis (f (a), f (c)) == 4)
	{
		fa = 1;
		cout << "minor" << endl;
	}
	//bca
	if (dis (f(b), f (c)) == 4 && dis (f (c), f (a)) == 3)
	{
		fa = 1;
		cout << "major" << endl;
	}
	if (dis (f(b), f (c)) == 3 && dis (f (c), f (a)) == 4)
	{
		fa = 1;
		cout << "minor" << endl;
	}
	//cab
	if (dis (f(c), f (a)) == 4 && dis (f (a), f (b)) == 3)
	{
		fa = 1;
		cout << "major" << endl;
	}
	if (dis (f(c), f (a)) == 3 && dis (f (a), f (b)) == 4)
	{
		fa = 1;
		cout << "minor" << endl;
	}
	//cba
	if (dis (f(c), f (b)) == 4 && dis (f (b), f (a)) == 3)
	{
		fa = 1;
		cout << "major" << endl;
	}
	if (dis (f(c), f (b)) == 3 && dis (f (b), f (a)) == 4)
	{
		fa = 1;
		cout << "minor" << endl;
	}
	if (fa == 0)
		cout << "strange" << endl;
	
	
	
	
	return 0;
}