#include <iostream>

using namespace std;

string str (int x, int y)
{
	string r;
	r.clear();
	while (x > 0)
	{
		r += x % y;
		x /= y;
	}
	return r;
}

bool pl (string x)
{
	bool r = 1;
	for (int i = 0; i <= x.size(); i++)
		if (x[i] != x[x.size() - i - 1])
			r = 0;
	return r;
}

int main()
{
	int sum = 0;
	string a, b;
	for (int i = 1; i < 1000000; i++)
	{
		a = str (i, 10);
		b = str (i, 2);
		if (pl (a) && pl (b))
			sum += i;
	}
	cout << sum << endl;
	return 0;
}