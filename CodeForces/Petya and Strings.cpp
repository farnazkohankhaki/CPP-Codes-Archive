#include <iostream>

using namespace std;

string a, b;

int main ()
{
	cin >> a >> b;
	
	bool ch = 0;
	for (int i = 0; i < a.size(); i++)
	{
		int x = (a[i] - 'A') % 32, y = (b[i] - 'A') % 32;
		if (x < y)
		{
			cout << -1 << endl;
			ch = true;
			break;
		}
		if (x > y)
		{
			cout << 1 << endl;
			ch = true;
			break;
		}
	}

	if (!ch)
		cout << 0 << endl;
	
	return 0;
}